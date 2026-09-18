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

int UART1::puts(const char* s, uint16_t size){
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

int UART1::put_uint8(uint8_t num)
{
    int return_value = -1;

    if(init_status == true)
    {
        return_value = 0;

        char buffer[3] = {'N', 'N', 'N'};
        char curr;
        uint8_t index = 0;

        if(num == 0)
        {
            buffer[0] = '0';
        }
        else
        {
            while(num > 0)
            {
                curr = '0' + (num % 10);
                num = num / 10;
                buffer[index] = curr;
                index++;
            }
        }

        for(int i = 2; i >= 0; i--)
        {
            if(buffer[i] != 'N')
            {
                putc(buffer[i]);
            }
        }
    }

    return return_value;
}
/*
int UART1::putnum(uint32_t number){
    int return_value = 0;
    char buffer[10];
    uint8_t cnt = 0;
    if(init_status == true){
        while(number > 0){
            char temp = '0' + (number % 10);
            buffer[cnt] = temp;
            cnt++;
            number = number / 10;
        }
        while(cnt > 0){
            cnt--;
            putc(buffer[cnt]);
        }
        puts("\n\r",2);
    }
    else{
        return_value = -1;
    }
    return return_value;
}
*/
