#include <REG51.H>
#include "lcd.c"
#define adc_port P0              //ADC Port
sbit rd = P3^4;                  //Read signal P1.0
sbit wr = P3^3;                  //Write signal P1.1
sbit intr = P3^2;                //INTR signal P1.3
sbit led = P3^0;
unsigned char adc_val;

void conv();                     //Start of conversion function
void read();                     //Read ADC function



void main()
{
    delay_ms(100);
		intr = 1;
		lcd_init();
		lcd_out(1,1,"ADC with 8051");
		lcd_out(2,1,"Voltage: ");
		
		
		while(1)
		{				                    //Forever loop
			conv();                  //Start conversion
			read();                  //Read ADC				
			lcd_print(2,11,adc_val,4);
			delay_ms(100);
    }
}

void conv()
{
       
        wr = 0;                      //Make WR low
        wr = 1;                      //Make WR high

        while(intr == 1);                 //Wait for INTR to go low
}
void read()	 		// function to read the Analog to digital converted value
{

        rd = 1;                      //Make RD low
        rd = 0;
        adc_val = P1;          //Read ADC port
		    delay_ms(250);
        rd = 1;                      //Make RD high
}
