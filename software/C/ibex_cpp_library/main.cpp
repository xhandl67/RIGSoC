#include "uart.h"

#define CLK_FREQ 10000000
#define BAUDRATE 115200
UART1 test_uart1;
uint16_t delay_volatile(uint16_t milliseconds){
    volatile uint16_t cnt = 0;
    for(volatile uint16_t i = 0; i<milliseconds; ++i){
        for(volatile uint16_t j = 0; j<1000; ++j){
            cnt++;
        }
    }
    return cnt;
}
int main(void){
    uint16_t cnt_val = 0;
    test_uart1.init_regs();
    test_uart1.set_bauddiv((uint16_t)(CLK_FREQ / BAUDRATE));
    cnt_val = delay_volatile(1000);
    while(1){
        test_uart1.puts("MELIXFILLER\r\n\0",15);
        cnt_val = delay_volatile(1000);
    }
}