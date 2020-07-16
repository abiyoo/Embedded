#include "aROS.h"
#include <stdint.h>

OSThreadCB * volatile headPtr;
OSThreadCB * volatile tailPtr;

OSThreadCB * volatile currentPtr;
OSThreadCB * volatile nextPtr;

void start_task(OSThreadCB *me, TaskHandler task, uint32_t *stack, uint32_t s_size){


    uint32_t *sp = (uint32_t *)((((uint32_t)stack + s_size)/8)*8);

    *(--sp) = (uint32_t)1 << 24;
    *(--sp) = (uint32_t)task;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;
    *(--sp) = (uint32_t)0xDEADBEEF;

    me->sp = sp;

    if (headPtr != (OSThreadCB *)0){

        tailPtr->nextPtr = me;
        tailPtr = me;
    }else{

        headPtr = me;
        tailPtr = me;
    }
}

void PendSV_Handler(){



    __asm__ (
          "CPSID             I;"
          "POP              {r7};"
          "LDR              r0,=currentPtr;"
          "LDR              r1, [r0];"
          "CBZ              r1, saveContext;"
          "PUSH             {r4-r11};"
          "STR              SP, [r1];"
       "saveContext:;"
          "LDR             r2,=nextPtr;"
          "LDR             r2,[r2];"
          "LDR             SP,[r2];"
          "POP             {r4-r11};"
          "STR             r2, [r0];"
          "BX              LR;"
          "CPSIE           I;"


     );

}

void scheduler(){



        if (currentPtr == (OSThreadCB *)0 || (currentPtr->nextPtr == (OSThreadCB *)0)){

            nextPtr = headPtr;
        }else{

            nextPtr = currentPtr->nextPtr;
        }

        *(uint32_t volatile *) 0xE000ED04 = (1U << 28);
}

void OS_init(){

    *(uint32_t volatile *)0xE000ED20 |= (0xFFU << 16);
}
