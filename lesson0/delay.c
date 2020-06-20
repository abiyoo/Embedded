#include "delay.h"

/*
void test(){

    int volatile foo[5];

    foo[10] = (int) &hackfn;

}

void hackfn (){

    int volatile hack_x = 0;

    while (hack_x <= 5)
    {
        hack_x++;

    }
}
*/

void delay (){

    int volatile counter = 0;

   // test();

    while (counter < 1000000) {

        counter++;
    }
}
