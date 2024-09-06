/*
 * File:    customprotocol.h
 * Author:  Nguyen Tuan Phong
 * Date:    2024-09-05
 */

#include "bsp_api.h"
#include <string.h>
#include <stdio.h>

Custom_Protocol_StateTypeDef UART_Init(void)
{
    printf("Init UART OK\n");
    return CUSTOM_PROTOCOL_STATE_OK;
}

Custom_Protocol_StateTypeDef UART_Transmit(uint8_t *pData, uint16_t size)
{
    if (pData == NULL || size == 0 || size > CUSTOM_PROTOCOL_SIZE)
    {
        return CUSTOM_PROTOCOL_STATE_ERROR;
    }

    printf("Data transmit: ");
    for (uint16_t i = 0; i < size; i++)
    {
        printf("[%d] ", pData[i]);
    }
    printf("\n");
    return CUSTOM_PROTOCOL_STATE_OK;
}

Custom_Protocol_StateTypeDef UART_Receive(CustomProtocolRingBuffer *pData)
{
    if (pData == NULL)
    {
        return CUSTOM_PROTOCOL_STATE_ERROR;
    }
    uint8_t data[11] = {0xFF, 0x01, 0x00, 0x04, 0x01, 0x02, 0x03, 0x04, 0x00, 0x0A, 0x00};

    pData->size = 11;

    memcpy(pData->data, data, 11);

    pData->size = 11;

    return CUSTOM_PROTOCOL_STATE_OK;
}

uint32_t gettick(void)
{
    uint32_t value = 0;
    return value;
}