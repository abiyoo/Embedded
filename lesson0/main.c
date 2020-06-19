//#include "TM4C123GH6PM.h"
#include "bsp.h"


#define LED_RED 1U << 1
#define LED_BLUE 1U << 2
#define LED_GREEN 1U << 3

#define GPIOCGR (*((unsigned int *) 0x400FE608U))

#define GPIOF_BASE 0x40025000

#define GPIOF_DATA_BASE 0x40025000

#define GPIOF_DIR (*(unsigned int *)(GPIOF_BASE + 0x400U))
#define GPIOF_DEN (*(unsigned int *)(GPIOF_BASE + 0x51CU))
#define GPIOF_DATA (*(unsigned int *)(GPIOF_BASE + 0x3FCU))


int main() {


    GPIOCGR = 0x20U; //Clock Gating
    GPIOF_DIR = 0x0EU; //Direction
    GPIOF_DEN = 0x0EU; //Digital Enable


   while (1)
   {

       delay();
       *((unsigned int *)(GPIOF_DATA_BASE + (LED_GREEN<<2)))  = ~LED_GREEN;
       *((unsigned int *)(GPIOF_DATA_BASE + (LED_RED<<2)))  = LED_RED;
       //GPIOF_DATA = 0x02U;
       delay();
       *((unsigned int *)(GPIOF_DATA_BASE + (LED_RED<<2)))  =  ~LED_RED;
       *((unsigned int *)(GPIOF_DATA_BASE + (LED_BLUE<<2)))  = LED_BLUE;
       //GPIOF_DATA = 0x04U;
       delay();
       *((unsigned int *)(GPIOF_DATA_BASE + (LED_BLUE<<2)))  = ~LED_BLUE;
       *((unsigned int *)(GPIOF_DATA_BASE + (LED_GREEN<<2)))  = LED_GREEN;
       //GPIOF_DATA = 0x08U;

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
