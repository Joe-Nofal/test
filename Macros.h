

#ifndef MACROS_H
#define MACROS_H

#define SET_BIT(Byte,Pos)                       (Byte |= (1<<Pos))
#define CLEAR_BIT(Byte,Pos)                     (Byte &= ~(1<<Pos))
#define TOGGLE_BIT(Byte,Pos)                    (Byte ^=(1<<Pos))
#define SET_BYTE(Byte)                          (Byte |=(0xFF))
#define CLEAR_BYTE(Byte)                        (Byte &=(0x00))
#define SET_NIBBLE_HIGH(Byte)                   (Byte |=(0xF0))
#define SET_NIBBLE_LOW(Byte)                    (Byte |=(0x0F))
#define CLEAR_NIBBLE_HIGH(Byte)                 (Byte &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte)                  (Byte &=(0xF0))
#define GET_BIT(Reg,Bit)                        ((Reg &(1<<Bit))>>Bit)


#endif
