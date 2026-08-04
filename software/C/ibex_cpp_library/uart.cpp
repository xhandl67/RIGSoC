#include "uart.h"

void UART1::init_regs(void){
    status_reg = (volatile uint32_t*)(UART1_BASE + UART_STATUS_REG);
    bauddiv_reg = (volatile uint32_t*)(UART1_BASE + UART_BAUDDIV_REG);
    rx_reg = (volatile uint32_t*)(UART1_BASE + UART_RX_REG);
    tx_reg = (volatile uint32_t*)(UART1_BASE + UART_TX_REG);
    init_status = true;
}

int UART1::putc(char c){
    int return_value = 0;
    if(init_status == true){
        while(((*status_reg >> UART_STATUS_TX_FULL) & 1) == 1){
            //warten 
        }
        *tx_reg = c;
    }
    else{
        return_value = -1;
    }
    return return_value;
}

int UART1::set_bauddiv(uint16_t bauddiv){
    int return_value = 0;
    if(init_status == true){
        *bauddiv_reg = bauddiv;
    }
    else{
        return_value = -1;
    }
    return return_value;
}

int UART1::puts(char* s, uint16_t size){
    uint16_t cnt = 0;
    int return_value = 0;
    if(init_status == true){
        while(cnt < size && *s != '\0'){
            putc(*s);
            s++;
            cnt++;
        }
    }
    else{
        return_value = -1;
    }
    return return_value;
}