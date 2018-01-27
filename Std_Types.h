#ifndef _STD_TYPES_H

#define _STD_TYPES_H

/* Type definition of unsigned 8-bit integer, 0->255                                                                 */
typedef unsigned char u8;

/* Type definition of unsigned 16-bit integer, 0->65535                                                              */
typedef unsigned short int u16;

/* Type definition of unsigned 32 bit integer, 0->4294967295                                                         */
typedef unsigned long int u32;

/* Type definition of signed 8-bit integer, -128,127                                                                 */
typedef signed char s8;

/* Type definition of signed 16-bit integer, -32768->32767                                                           */
typedef signed short int s16;

/* Type definition of singed 32-bit integer, -2147483648->2147483647                                                 */
typedef signed long int s32;

/* Type definition of 32-bit float,  -2147483648->2147483647                                                         */
typedef float f32;

/* Type definition of 64-bit, (-2^63)->((-2^63)-1)                                                                   */
typedef double f64;

/* Type definition of 64-bit, (-2^79)->((-2^79)-1)                                                                   */
typedef long double f80;

/* Definition of Standard ON                                                                                         */
#define STD_HIGH         0x01

/* Definition of Standard OFF                                                                                        */
#define STD_LOW          0x00

/*********************************************************************************************************************/
/* Type definition for byte and bit access                                                                           */
typedef union
{
  struct
  {
    u8 u8b0 :1; /* LSB (least significant bit)*/
    u8 u8b1 :1; /* BIT 1                      */
    u8 u8b2 :1; /* BIT 2                      */
    u8 u8b3 :1; /* BIT 3                      */
    u8 u8b4 :1; /* BIT 4                      */
    u8 u8b5 :1; /* BIT 5                      */
    u8 u8b6 :1; /* BIT 6                      */
    u8 u8b7 :1; /* MSB (most significant bit) */
  } strBit; /*for bit  access             */
  u8 u8Byte; /* for byte access            */
} STD_tenuPort;
/*********************************************************************************************************************/
#endif
