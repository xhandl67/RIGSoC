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
    uint64_t test_num = 1234567834343403;
    delay_volatile(100);
    set_baudval(CPU_FREQ/BAUDRATE);
    delay_volatile(100);
    uint32_t low = test_num & 0x00000000FFFFFFFF;
    uint32_t high = (uint32_t)(test_num >> 32); 
    while(1){
        puts("ICH HASSE IBEX\r\n\0",18);     
        delay_volatile(100);
        putnum(high);
        putnum(low);
        putc('\n');
        delay_volatile(100);
    }
    
    return 0;
}