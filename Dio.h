/*
 * Dio.h
 *
 *  Created on: Dec 27, 2016
 *      Author: Sragaai
 */

#ifndef DIO_H_
#define DIO_H_

/********************************************* External Definitions **************************************************/
/* Output Ports                                                                                                      */
#define DIO_PORTA        0
#define DIO_PORTB        1
#define DIO_PORTC        2
#define DIO_PORTD        3

/*********************************************************************************************************************/

/*********************************************************************************************************************/
/************************************************ Dio Interfaces *****************************************************/

/* Interface to set the value of output pin in port                                                                  */
void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy);

/* Interface to get the value of input pin in port                                                                   */
u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy);

/* Interface to set the direction of pin in port                                                                     */
void Dio_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy);

/* Interface to set port direction                                                                                   */
void Dio_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8ValueCpy);

/* Interface to set the output value of port                                                                         */
void Dio_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy);

/* Interface to get the input value on Port                                                                          */
u8 Dio_u8GetPortValue(u8 u8PortNumberCpy);

/*********************************************************************************************************************/

#endif /* DIO_H_ */
