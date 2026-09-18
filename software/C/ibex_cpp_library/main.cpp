#include "uart.h"
#include "timer.h"
#define CLK_FREQ 10000000
#define BAUDRATE 115200

UART1 test_uart1;
TIMER t1;
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
    volatile uint32_t* timer_low_reg = (volatile uint32_t*)(0x80002000);
    test_uart1.init_regs();
    test_uart1.set_bauddiv((uint16_t)(CLK_FREQ / BAUDRATE));
    volatile uint32_t* mtime_low = (volatile uint32_t*)(0x80002000 + 0);
    cnt_val = delay_volatile(100);
    test_uart1.puts("STARTE UART DU GESICHTSMENSCH\r\n\0",33);
    uint32_t timestamp_low = 0;
    timestamp_low = *timer_low_reg;
    while(timestamp_low > 0){
        char curr = (char)(timestamp_low % 10) + '0';
        timestamp_low = timestamp_low / 10;
        test_uart1.putc(curr);

    }
    test_uart1.putc('\n');
    test_uart1.puts("FERTIG!!\r\n\0",12);
    return timestamp_low;
}