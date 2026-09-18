#ifndef UART_H
#define UART_H
#include <stdint.h>
#define UART_RX_REG 0
#define UART_TX_REG 4
#define UART_STATUS_REG 8
#define UART_BAUDDIV_REG 0xC
#define UART1_BASE 0x80001000
#define UART_STATUS_RX_EMPTY 1
#define UART_STATUS_TX_FULL 2

int set_baudval(uint32_t baudval);
int putc(char c);
int puts(char* s, uint32_t size);
int putnum(uint32_t num);

#endif 