/*
 * Dio.c
 *
 *  Created on: Dec 22, 2016
 *      Author: Sragaai
 */
/**************************************************** INCLUSIONS *****************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Dio.h"

/*********************************************************************************************************************/
/* Registers Definitions   
#define SREG *((volatile u8*)0x5F)                                                                                          */
#define PORTA *((volatile u8*)0x3B)
#define DDRA  *((volatile u8*)0x3A)
#define PINA  *((volatile u8*)0x39)
#define PORTB *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0x37)
#define PINB  *((volatile u8*)0x36)
#define PORTC *((volatile u8*)0x35)
#define DDRC  *((volatile u8*)0x34)
#define PINC  *((volatile u8*)0x33)
#define PORTD *((volatile u8*)0x32)
#define DDRD  *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Interface to set the Output value of the pin                                                                      */
void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy)
{

  switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTA, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(PORTA, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTB, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(PORTB, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTC, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(PORTC, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTD, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(PORTD, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }

}
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Interface to get the value of the input pin                                                                       */
u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy)
{

  u8 Loc_u8PinValue = 0;
  switch (u8PortNumberCpy)
  {
  case 0:

    Loc_u8PinValue = GET_BIT(PINA, u8PinNumberCpy);
    break;

  case 1:

    Loc_u8PinValue = GET_BIT(PINB, u8PinNumberCpy);
    break;

  case 2:

    Loc_u8PinValue = GET_BIT(PINC, u8PinNumberCpy);
    break;

  case 3:

    Loc_u8PinValue = GET_BIT(PIND, u8PinNumberCpy);
    break;

  default:
    break;

  }
  return Loc_u8PinValue;
}
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Interface to Set the direction of PIN                                                                             */
void Dio_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy)
{

  switch (u8PortNumberCpy)
  {
  case 0:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRA, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(DDRA, u8PinNumberCpy);
    }
    break;
  case 1:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRB, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(DDRB, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRC, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(DDRC, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRD, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(DDRD, u8PinNumberCpy);
    }
    break;

  default:
    break;

  }

}

/* Interface to set port direction                                                                                   */
void Dio_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8ValueCpy)
{

  switch (u8PortNumberCpy)
  {
  case 0:
    DDRA = u8ValueCpy;
    break;

  case 1:
    DDRB = u8ValueCpy;
    break;

  case 2:
    DDRC = u8ValueCpy;
    break;

  case 3:
    DDRD = u8ValueCpy;
    break;

  default:
    break;
  }

}

/* Interface to set the output value of port                                                                         */
void Dio_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy)
{
  switch (u8PortNumberCpy)
  {
  case 0:
    PORTA = u8ValueCpy;
    break;

  case 1:
    PORTB = u8ValueCpy;
    break;

  case 2:
    PORTC = u8ValueCpy;
    break;

  case 3:
    PORTD = u8ValueCpy;
    break;

  default:
    break;
  }

}

/* Interface to get the input value on Port                                                                          */
u8 Dio_u8GetPortValue(u8 u8PortNumberCpy)
{

  u8 LOC_u8Return = 0x00;

  switch (u8PortNumberCpy)
  {

case 0:
  LOC_u8Return = PINA;
  break;

case 1:
  LOC_u8Return = PINB;
  break;

case 2:
  LOC_u8Return = PINC;
  break;

case 3:
  LOC_u8Return = PIND;
  break;

default:
  break;

  }
  return (LOC_u8Return);
}

/*********************************************************************************************************************/
