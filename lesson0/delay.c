void delay();


void delay (){

    int volatile counter = 0;

    while (counter < 1000000) {

        counter++;
    }
}