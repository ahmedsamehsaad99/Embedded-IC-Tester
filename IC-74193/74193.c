/*******************************************************

Project : IC-Test
Version : 
Date    : 24-Dec-2021

*******************************************************/

#include <mega32.h>
#include <delay.h>

// SETTING --> OUTPUT OF ATMEGA
// GETTING --> INPUT OF ATMEGA

// 2, 3, 6, 7, 12, 13   OUTPUT
// 1, 4, 5, 9, 10, 14, 15 INPUT

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

#define G_LED PORTD.2
#define R_LED PORTD.3

#define HIGH 1
#define LOW 0


unsigned char concatenate(char first, char second, char third, char fourth);

void main(void)
{   

char D = 5;
DDRC = 0;
DDRA = 0xFF;
DDRD = 0xFF;

while (1)
      {      
        unsigned char i;     
                     
        PORTA = 0;

        PIN4 = LOW;
        PIN5 = LOW;
        PIN14 = LOW;
        
        PIN4 = HIGH;
        PIN5 = HIGH;
        PIN11 = HIGH;
             
        for (i = 0; i < 15; i++)
        {   
            if (concatenate(PIN7, PIN6, PIN2, PIN3) != i)
                R_LED = HIGH; 
                
            if (PIN12 != HIGH)      /// ACTIVE LOW
                R_LED = HIGH; 
                
            PIN5 = LOW;
            PIN5 = HIGH;
        }                 
                  
        if (concatenate(PIN7, PIN6, PIN2, PIN3) != i)  // I = 15
            R_LED = HIGH;             
        
        for (i = 15; i > 0; i--)
        {  
            if (concatenate(PIN7, PIN6, PIN2, PIN3) != i)
                R_LED = HIGH;
                
            if (PIN13 != HIGH)
                R_LED = HIGH; 
                
            PIN4 = LOW; 
            PIN4 = HIGH;      
        }               
                                        
        if (concatenate(PIN7, PIN6, PIN2, PIN3) != i)   // I = 0
            R_LED = HIGH;
                   
       for (i = 0; i <= 1; i++)
        {
            PIN9  = (D>>3 & 1);
            PIN10 = (D>>2 & 1);
            PIN1  = (D>>1 & 1);
            PIN15 = (D & 1);
      
            PIN11 = LOW;
            PIN11 = HIGH;                            
                       
            if (concatenate(PIN7, PIN6, PIN2, PIN3) != D)
               R_LED = HIGH;
      
            D = D ^ 0xF;
        }                
               
        if (R_LED == LOW)
            G_LED = HIGH;         
      }
}

unsigned char concatenate(char first, char second, char third, char fourth)
{
    return (((((first << 1) | second ) << 1) | third) << 1) | fourth;
}