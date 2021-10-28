#include "usart1.h"


void USART(unsigned int speed)
{
	UBRR0H = (unsigned char) (speed>>8);
	UBRR0L = (unsigned char) speed;
	UCSR0B = 1 <<  RXEN0 | 1 <<  TXEN0; // ¬ключаем прием и передачу
	UCSR0A |= 1 << U2X0; // удвоение частоты
	UCSR0C |= 1 << USBS0; // 2 стоп бита
	UCSR0B |= 1 << RXCIE0; // разрешаем прерывани€	при приеме
	
}

void USART_Trans(unsigned char data[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		while (!(UCSR0A & (1 << UDRE0)));
		UDR0 = data[i];
	}
}