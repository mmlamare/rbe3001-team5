/*
 * USARTDebug.c
 *
 *  Created on: Jan 17, 2017
 *      Author: Matt
 */

#include "RBELib/RBELib.h" //This was the Goldfarb's's idea

/**
 * @brief Initializes USART1 as a print terminal to the PC. This function
 * must check the incoming baudrate against the valid baudrates
 * from the data-sheet. If the baudrate is invalid, then the
 * DEFAULT_BAUD constant must be used instead.
 *
 * @param baudrate The desired baudrate to set for USART1.
 */
void debugUSARTInit(unsigned long baudrate){
	//Borrowed Example from data sheet:
	/*Set baud rate */
	UBRR1H = (unsigned char)(baudrate>>8);
	UBRR1L = (unsigned char)baudrate;
	/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS1)|(3<<UCSZ00);
}

/**
 * @brief Sends one byte to the USART1 Tx pin (Transmits one byte).
 *
 * @param byteToSend The byte that is to be transmitted through USART1.
 *
 * @todo Make the function that will put a character on the USART1 TX line.
 */
void putCharDebug(char byteToSend){
	//Borrowed Example from data sheet:
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1 << UDRE1)));

	/* Put data into buffer, sends the data */
	UDR1 = byteToSend;
}

/**
 * @brief Receives one byte of data from the serial port (i.e. from the PC).
 *
 * @return byteReceived Character that was received on the USART.
 *
 * @todo Make the function that will listen for input on the USART1 RX line.
 */
unsigned char getCharDebug(void){
	/* Wait for data to be received */
	while ( !(UCSR1A & (1 << RXC1)));

	/* Get and return received data from buffer */
	return UDR1;

}
