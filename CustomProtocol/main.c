/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>

/*********************************************************************
 *
 *       main()
 *
 *  Function description
 *   Application entry point.
 */
#include "bsp_api.h"

Custom_Protocol_Handle_Typedef *protocolPtr;

Custom_Protocol_Handle_Typedef Protocol_Interface =
    {
        .Init = UART_Init,
        .Transmit = UART_Transmit,
        .Receive = UART_Receive,
        .get_tick_ms = gettick,
};

int main(void)
{

  protocolPtr = &Protocol_Interface;
  CPT_Init(protocolPtr);

  uint8_t data[] = {0x01, 0x02, 0x03, 0x04};

  CPT_Transmit(protocolPtr, data, 4);

  CPT_ReceiverIT(protocolPtr, 2000);

  CPT_Receiver_Process(protocolPtr);//use in the interrupt

  while (1)
  {
  }
}
/*************************** End of file ****************************/
