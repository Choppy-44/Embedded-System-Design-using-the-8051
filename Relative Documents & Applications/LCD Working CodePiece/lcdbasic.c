#include<reg51.h>
#include "lcd.c"
void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i = 115;
		while(i > 0)
			i--;
		count--;
	}
}

void main()
{
	lcd_init();
	lcd_out(1,1,".");
	lcd_print(2,1,453,4);
	while(1)
	{}

}