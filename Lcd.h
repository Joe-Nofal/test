/*
 * Lcd.h
 *
 *  Created on: Dec 28, 2016
 *      Author: Sragaai
 */

#ifndef LCD_H_
#define LCD_H_

/* Interface to initialize the LCD Driver                                                                            */
void Lcd_vidInit (void);

/* Interface to send the configuration commands to the LCD Driver                                                    */
void Lcd_vidSendCommand (u8 u8CmdCpy);

/* Interface to write character on LCD screen                                                                        */
void Lcd_vidWriteCharctr (u8 u8DataCpy);

/* Interface to write string on LCD screen                                                                           */
void Lcd_vidWriteString (u8* pu8StringCpy);

#endif /* LCD_H_ */
