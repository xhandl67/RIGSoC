//#include "gpio.h"
/*
#include "demo_system.h"
//Versuche LED zu blinken
#define GPIO_BASE_ADDRESS 0x80000000
#define UART0_BASE 0x80001000
#define UART_RX_REG 0
#define UART_TX_REG 4
#define UART_STATUS_REG 8

#define UART_STATUS_RX_EMPTY 1
#define UART_STATUS_TX_FULL 2
void delay(uint16_t millisecons){
    volatile uint32_t cnt = 0;
    for(volatile  i = 0; i<millisecons; ++i){
        for(volatile  j = 0; j<1000; ++j){
            cnt++;
        }
    }
}
*/
// Inner loop iterations per "ms". The volatile counter costs ~10 cycles per
// iteration, so at 10 MHz ~1000 iterations ~= 1 ms. The previous value (100000)
// made one "ms" ~100 ms, i.e. ~100 s per half period - the LED looked dead.
//Millers baudrate 4096
int a = 0x0F0F0F0F;
int main(void){
    return a;
    /*
    volatile uint32_t* pointer_to_gpio = (volatile uint32_t*)(GPIO_BASE_ADDRESS);
    volatile uint32_t* uart_base = (volatile uint32_t*)(UART0_BASE);
    char c = 'A';
    volatile uint32_t* uart_tx_reg = (volatile uint32_t*)(UART0_BASE+UART_TX_REG);
    volatile uint32_t* uart_status_reg = (volatile uint32_t*)(UART0_BASE + UART_STATUS_REG);
    while(1){
        while(((*uart_status_reg >> UART_STATUS_TX_FULL) & 1 == 1)){
            //mach ganix
        }
        *uart_tx_reg = c;
    }
    */

    //Laut gpio.h ist gpio_out bei 0x0
    //*pointer_to_gpio = 0;+
    /*
    delay(100);
    puts((const char*)"Hier spricht ein fetter Tuerke\r\n\0");
    while(1){
        delay(1000);
        puts((const char*)"TIMONIGA\r\n\0");
    }
    */

}
