/*
 * main.c
 *
 *]
 */
#include "Std_Types.h"
#include "Macros.h"
#include "util/delay.h"
#include <avr/io.h>
#include<stdlib.h>
#include "Dio.h"
#include "Lcd.h"
#include "avr/interrupt.h"
#define F_CPU 8000000

void spi_init_master (void);
void spi_init_slave (void);
volatile u8 spi_tranceiver (volatile u8 );
void Master_Work(void);
void Slave_Work(void);


/*
int main(void)
{

  u8 au8Name[7] = "youssef";
  u32 x =332;
  u8 f[2];
  itoa(x,f,10);
   // Port Initialization                                                                                             
   Dio_vidSetPortDirection(DIO_PORTA, 0xFF);

  Dio_vidSetPortDirection(DIO_PORTD, 0xFF);
   // LCD initialization                                                                                              
   Lcd_vidInit();
   
    //Write Character  
                                                                                                 
																								 
 Lcd_vidSendCommand( ((1<<7)+0x40+5 ));//(1<<LCD_DDRAM)+LCD_START_LINE2+x
   Lcd_vidWriteCharctr(0b00100011);
   Lcd_vidWriteCharctr(0b01111111);
  Lcd_vidWriteCharctr('i');

  Lcd_vidWriteCharctr('s');

  Lcd_vidWriteCharctr(' ');
   Lcd_vidWriteString(f);
  Lcd_vidWriteString(au8Name);
  
  _delay_ms(3000);

 Lcd_vidSendCommand( 0x1c); //shift right 
 _delay_ms(100);
 Lcd_vidSendCommand( 0x1c);
  _delay_ms(100);
   Lcd_vidSendCommand( 0x1c);
  
//  while (1)  {



 // }

//}
*/


//.................
////////////////////////////////
#define SREG *((volatile u8*)0x5F);
volatile u8 MasterDATAsend=0;
volatile u8 MasterDATAReceive =255;
volatile u8 SlaveDATAsend = 255;
volatile u8 SlaveDATAReceive =0;
volatile u8 f[4];


void main()
{
	f[0] = 0 ;f[1] = 0 ;f[2] = 0 ;
	//itoa(MasterDATAReceive,f,10);
	spi_init_master ();
	

	   Dio_vidSetPortDirection(DIO_PORTA, 0xFF);

	   Dio_vidSetPortDirection(DIO_PORTD, 0xFF);
	   // LCD initialization
	   Lcd_vidInit();

	while(1)
	{
	 
	 Master_Work();
	  
	
	}
}


void spi_init_master (void)
{
	// Set MOSI, SCK as Output
	DDRB = (1<<5)|(1<<7)|(1<<4);
	
	// Enable SPI, Set as Master
	//Prescaler: Fosc/16, Enable Interrupts
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

// Initialize SPI Slave Device
void spi_init_slave (void)
{
	DDRB = (1<<6);     //MISO as OUTPUT
	SPCR = (1<<SPE);   //Enable SPI
}

volatile u8 spi_tranceiver (volatile u8 data)
{
	// Load data into the buffer
	SPDR = data;
	
	//Wait until transmission complete
	while(!(SPSR & (1<<SPIF) ));
	
	// Return received data
	return(SPDR);
}

void Master_Work(void)
{
		MasterDATAReceive = spi_tranceiver(MasterDATAsend++);
		/* Clear Display                                                                                                   */
		Lcd_vidSendCommand(0b00000001);
		Lcd_vidSendCommand( ((1<<7)+0x00+0 ));
		Lcd_vidWriteString("i am Master SD-- : ");
		Lcd_vidSendCommand( ((1<<7)+0x40+0 ));
		itoa(MasterDATAReceive,f,10);
		Lcd_vidWriteString(f);
		_delay_ms(1000);

}

void Slave_Work(void)
{
	SlaveDATAReceive = spi_tranceiver(SlaveDATAsend--);
	/* Clear Display                                                                                                   */
	Lcd_vidSendCommand(0b00000001);

	Lcd_vidSendCommand( ((1<<7)+0x00+0 ));
	Lcd_vidWriteString("i am slave : ");
	Lcd_vidSendCommand( ((1<<7)+0x40+0 ));
	itoa(SlaveDATAReceive,f,10);
	Lcd_vidWriteString(f);
	_delay_ms(1000);

}