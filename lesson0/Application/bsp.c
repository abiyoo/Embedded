/* Board Support Package */
#include "TM4C123GH6PM.h"
#include "bsp.h"
#include "aROS.h"

static uint32_t volatile l_tickCtr;


__attribute__((naked)) void assert_failed (char const *file, int line) {
    /* TBD: damage control */
    NVIC_SystemReset(); /* reset the system */
}

void SysTick_Handler(void) {

    scheduler();

    ++l_tickCtr;

//    __disable_irq();
//    scheduler();
//    __enable_irq();
  //  GPIOF_AHB->DATA_Bits[LED_BLUE] ^= LED_BLUE;


}

int BSP_tickCtr (void){

    uint32_t tickCtr;
    __disable_irq();
    tickCtr = l_tickCtr;
    __enable_irq();

    return tickCtr;
}

void BSP_delay (uint32_t tick){
    uint32_t start = BSP_tickCtr();

    while ((BSP_tickCtr() - start) < tick){

    }

}


void BSP_init(void){

        SYSCTL ->RCGCGPIO |= (1u << 5); //Clock Gating
       // GPIOCGR = 0x20U; //Clock Gating
        SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF
        GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN ); //Direction
        GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN ); //Digital Enable


        SysTick->LOAD = (SYS_CLOCK_HZ/TICKS_PER_SECOND) - 1U;
        SysTick->VAL  = 0U;
        SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;

        NVIC_SetPriority(SysTick_IRQn, 0U);
        __enable_irq();
}

void BSP_ledRedOn(void){
    GPIOF_AHB->DATA_Bits[LED_RED] = LED_RED;
}

void BSP_ledRedOff(void){
    GPIOF_AHB->DATA_Bits[LED_RED] = 0U;
}

void BSP_ledGreenOn(void){
    GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
}

void BSP_ledGreenOff(void){
    GPIOF_AHB->DATA_Bits[LED_GREEN] = 0U;
}

void BSP_ledBlueOn(void){
    GPIOF_AHB->DATA_Bits[LED_BLUE] = LED_BLUE;
}

void BSP_ledBlueOff(void){
    GPIOF_AHB->DATA_Bits[LED_BLUE] = 0U;
}










