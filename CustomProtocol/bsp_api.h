/*
 * File:    customprotocol.h
 * Author:  Nguyen Tuan Phong
 * Date:    2024-09-05
 */
#ifndef BSP_API_H_
#define BSP_API_H_

#include "customprotocol.h"

Custom_Protocol_StateTypeDef UART_Init(void);
Custom_Protocol_StateTypeDef UART_Transmit(uint8_t *pData, uint16_t size);
Custom_Protocol_StateTypeDef UART_Receive(CustomProtocolRingBuffer *pData);
uint32_t gettick(void);
#endif