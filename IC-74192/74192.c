#include <mega32a.h>
#include <delay.h>

#define PIN15 PORTA.0
#define PIN1  PORTA.1
#define PIN10 PORTA.2
#define PIN9  PORTA.3
#define PIN5  PORTA.4
#define PIN4  PORTA.5
#define PIN11 PORTA.6
#define PIN14 PORTA.7

#define PIN3  PINC.0
#define PIN2  PINC.1
#define PIN6  PINC.2
#define PIN7  PINC.3
#define PIN12 PINC.4
#define PIN13 PINC.5 

#define RLED     PORTD.7
#define GLED     PORTD.6

#define HIGH     1
#define LOW      0


char i;
char D;
char flag = 0;
unsigned char concatenate(char first, char second, char third, char fourth);

void main(void)
{
DDRC = 0;
DDRA = 0xFF;
DDRD = 0xFF;

    while (1)
    {
        PORTA = 0;

        PIN4 = LOW;
        PIN5 = LOW;
        PIN14 = LOW;
        
        PIN4 = HIGH;
        PIN5 = HIGH;
        PIN11 = HIGH;
        
            for(i = 0 ; i <= 8; i++)
            {
                if(concatenate(PIN7, PIN6, PIN2, PIN3) != i)
                    {
                        //RLED = HIGH;
                        flag = 1;
                    }
                if (PIN12 != HIGH)
                    {
                        //RLED = HIGH;
                        flag = 1;
                    }
                PIN5 = LOW;
                PIN5 = HIGH;
            }
            
            if(concatenate(PIN7, PIN6, PIN2, PIN3) != i) 
                 {
                        //RLED = HIGH;
                        flag = 1;
                 }
            
            for(i = 9 ; i >= 1 ; i--)
            {
                if(concatenate(PIN7, PIN6, PIN2, PIN3)  != i)
                    {
                        //RLED = HIGH;
                        flag = 1;
                    }
                if (PIN13 != HIGH)
                    {
                        //RLED = HIGH;
                        flag = 1; 
                    } 
                PIN4 = LOW;
                PIN4 = HIGH;
            }
            
            if(concatenate(PIN7, PIN6, PIN2, PIN3) != i) 
                 {
                        //RLED = HIGH;
                        flag = 1;
                    }
                 
            
            D = 5;
            
            for(i = 0 ; i <= 1 ; i++)
            {
                PIN9  = (D>>3 & 1);
                PIN10 = (D>>2 & 1);
                PIN1  = (D>>1 & 1);
                PIN15 = (D & 1);
                
                PIN11 = LOW;
                PIN11 = HIGH;
                
                if(concatenate(PIN7, PIN6, PIN2, PIN3) != D)
                    {
                        //RLED = HIGH;
                        flag = 1;  
                    }
                D = D ^ 0xF; 
            }
            
            if (flag == 0)
                GLED = HIGH; 
            else 
                RLED = HIGH;
        }
}          

unsigned char concatenate(char first, char second, char third, char fourth)
{
    return (((((first << 1) | second ) << 1) | third) << 1) | fourth;
}