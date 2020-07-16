#ifndef A_ROS_H
#define A_ROS_H
#include <stdint.h>

struct TCB{
    uint32_t *sp;
    struct TCB *nextPtr;
};

typedef struct TCB OSThreadCB;

typedef void (*TaskHandler)(void);

void start_task(OSThreadCB *me, TaskHandler task, uint32_t *stack, uint32_t s_size);

void scheduler();

void OS_init();




#endif
