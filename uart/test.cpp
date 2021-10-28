#include "main.h"


/*ISR(USART_RX_vect)
{
	int a;
	a = UDR0;
	a++;
	USART_Trans (a);
}*/

int main(void)
{
	unsigned char arr[10] = {1,2,3,4,5,6,7,8,9,0};
    USART(16);
	USART_Trans(arr, 10);
	sei();
	
    while (1) 
    {

    }
}

