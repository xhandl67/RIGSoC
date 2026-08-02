#ifndef UART_H
#define UART_H
#include <stdint.h>
#include <stdbool.h>
#define UART_RX_REG 0
#define UART_TX_REG 4
#define UART_STATUS_REG 8
#define UART_BAUDDIV_REG 0xC
#define UART1_BASE 0x80001000
#define UART_STATUS_RX_EMPTY 1
#define UART_STATUS_TX_FULL 2

class UART1{
    private:
        volatile uint32_t* bauddiv_reg;
        volatile uint32_t* status_reg;
        volatile uint32_t* rx_reg;
        volatile uint32_t* tx_reg;
        bool init_status;
    public:
        void init_regs(void);
        int putc(char c);
        int set_bauddiv(uint16_t bauddiv);
        int puts(char* s, uint16_t size);
};

#endif