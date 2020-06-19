//#include "TM4C123GH6PM.h"
#include "bsp.h"


#define GPIOCGR (*((unsigned int *) 0x400FE608U))

#define GPIOF_BASE 0x40025000

#define GPIOF_DIR (*(unsigned int *)(GPIOF_BASE + 0x400U))
#define GPIOF_DEN (*(unsigned int *)(GPIOF_BASE + 0x51CU))
#define GPIOF_DATA (*(unsigned int *)(GPIOF_BASE + 0x3FCU))

void delay();

void delay (){

    int volatile counter = 0;

    while (counter < 1000000) {

        counter++;
    }
}

int main() {


    GPIOCGR = 0x20U; //Clock Gating
    GPIOF_DIR = 0x0EU; //Direction
    GPIOF_DEN = 0x0EU; //Digital Enable


   while (1)
   {

       delay();
       GPIOF_DATA = 0x02U;
       delay();
       GPIOF_DATA = 0x04U;
       delay();
       GPIOF_DATA = 0x08U;

   }


/*
    SYSCTL->RCGCGPIO  |= (1U << 5); // enable Run mode for GPIOF
    SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF
    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);

    SysTick->LOAD = SYS_CLOCK_HZ/2U - 1U;
    SysTick->VAL  = 0U;
    SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;

    SysTick_Handler();

    __enable_irq();
    while (1) {
        GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
        GPIOF_AHB->DATA_Bits[LED_GREEN] = 0U;
    }

*/
    return 0;
}
