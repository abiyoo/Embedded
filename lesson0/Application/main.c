#include "TM4C123GH6PM.h"
#include "bsp.h"
#include <stdint.h>
#include "aROS.h"

OSThreadCB tcb_red;
void blinky_red(){

    while(1){

    BSP_ledRedOn();
    BSP_delay(TICKS_PER_SECOND/100U);
    BSP_ledRedOff();
    BSP_delay(TICKS_PER_SECOND/100U);
    }

}

OSThreadCB tcb_green;
void blinky_green(){

    while(1){
    BSP_ledGreenOn();
    BSP_delay(TICKS_PER_SECOND/100U);
    BSP_ledGreenOff();
    BSP_delay(TICKS_PER_SECOND/100U);
    }
}

int main() {

//uint32_t start;
     BSP_init();
     OS_init();


     uint32_t stack_red[40];
     start_task(&tcb_red, &blinky_red, &stack_red[0], sizeof(stack_red));


     uint32_t stack_green[40];
     start_task(&tcb_green, &blinky_green, &stack_green[0], sizeof(stack_green));

     while(1){

     }


/*
uint32_t volatile x = 1;

       if(x){
           blinky_red();
       }else {

           blinky_green();
       }



#if ABIY
   static enum{
       INITIAL,
       OFF_STATE,
       ON_STATE
   }state = INITIAL;

   switch (state){

   case INITIAL:
       start = BSP_tickCtr();
       state = ON_STATE;
       break;
   case OFF_STATE:

       if (BSP_tickCtr() - start >= TICKS_PER_SECOND){

           BSP_ledGreenOn();
           start = BSP_tickCtr();
           state = ON_STATE;
       }
       break;

   case ON_STATE:

       if (BSP_tickCtr() - start >= TICKS_PER_SECOND){

                  BSP_ledGreenOff();
                  start = BSP_tickCtr();
                  state = OFF_STATE;
              }
              break;

   }

#endif

*/

    return 0;
}
