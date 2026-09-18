#include "uart.h"

int set_baudval(uint32_t baudval){
    volatile uint32_t* baudrate_reg = (volatile uint32_t*)(UART1_BASE + UART_BAUDDIV_REG);
    *baudrate_reg = baudval;
    return 0;
}

int putc(char c){
    volatile uint32_t* status_reg = (volatile uint32_t*)(UART1_BASE + UART_STATUS_REG);
    volatile uint32_t* transmit_reg = (volatile uint32_t*)(UART1_BASE + UART_TX_REG);
    while(((*status_reg >> UART_STATUS_TX_FULL) & 1) == 1){
        //wait until transmit reg is empty
    }
    *transmit_reg = c;
    return 0; 
}

int puts(char* s, uint32_t size){
    uint32_t cnt = 0; 
    char* temp = s;
    while(cnt < size && *temp != '\0'){
        putc(*temp);
        temp++;
        cnt++;
    }
    return 0;
}
int putnum(uint32_t num){
    char buffer[10] = {0};
    uint8_t index = 0;
    if(num == 0){
        putc('0');
        return 0;
    }
    while(num > 0){
        char curr_digit = (num % 10) + '0';
        buffer[index] = curr_digit;
        index++;
        num = num / 10;
    }

    for(int i = 9; i>= 0; i--){
        if(buffer[i] != 0){
            putc(buffer[i]);
        }
    }
    return 0;
}