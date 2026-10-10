#include "uart.h"

void delay_volatile(uint32_t milliseconds){
    for(volatile uint32_t i = 0; i<milliseconds; ++i){
        for(volatile uint16_t j = 0; j<1000; ++j){ 
        }
    }
}
#define CPU_FREQ 10000000
#define BAUDRATE 115200
int main(void){
    delay_volatile(100);
    set_baudval(CPU_FREQ/BAUDRATE);
    delay_volatile(100);
    puts("STARTE IBEX DU KEK\r\n\0",22);
    delay_volatile(10);
    puts("ES WIRD ERNST\r\n\0",17);
    while(1){
        puts("ICH HASSE IBEX\r\n\0",18);     
        delay_volatile(100);

    }
    
}