#include <mega32a.h>        `
#include <delay.h>

#define PIN1 PORTA.0
#define PIN2 PORTA.1
#define PIN3 PORTA.2
#define PIN4 PORTA.3
#define PIN5 PORTA.4
#define PIN6 PORTA.5
#define PIN7 PORTA.6
//#define PIN8 PORTA.7
#define PIN9  PORTA.7

#define PIN10 PORTC.0
#define PIN11 PORTC.1
#define PIN12 PORTC.2
#define PIN13 PORTC.3
#define PIN14 PORTC.4
#define PIN15 PORTC.5
#define PIN16 PORTC.6

#define G_LED PORTD.2
#define R_LED PORTD.3

int i=0;

unsigned char concatenate_5 (char first, char second, char third, char fourth, char fif);
unsigned char concatenate_6 (char first, char second, char third, char fourth, char fif,  char sixth);

void main()
{   
    DDRA=0x0;     //pin 1,2,3,4,5,6,7 Output
    DDRC=0xFF;   //pin 9 Output  & pin  10,11,12,13,14,15 Input
    DDRD=0xFF;   

    while (1)
    { 
       
               for (i=0;i<40;i=i+2)
                {
                    int X = ((i / 10) << 4) + (i % 10);
                      
                    PIN14 = (X >> 1) >> 4 & 1;
                    PIN13 = (X >> 1) >> 3 & 1;
                    PIN12 = (X >> 1) >> 2 & 1;
                    PIN11 = (X >> 1) >> 1 & 1;
                    PIN10 = (X >> 1) & 1;
                    
                    DDRA = 0xFF;
                     
                    PIN1=1; 
                    PIN2=1; 
                    PIN3 =1;
                    PIN4 =1;
                    PIN5 =1;
                    PIN6 =1;
                    PIN7 =1;
                    PIN9 =1;
                                                               
                   if (i == concatenate_6(PIN5 , PIN4 , PIN3 , PIN2, PIN1 , X&1))
                    {
                    R_LED  = 1;   
                    }            

                    PIN1=0; 
                    PIN2=0; 
                    PIN3 =0;
                    PIN4 =0;
                    PIN5 =0;
                    PIN6 =0;
                    PIN7 =0;
                    PIN9 =0;                 
                                
                if (concatenate_5(PIN5, PIN4, PIN3, PIN2, PIN1) != 0)
                    {
                    R_LED = 1;
                    }       
                    
                    DDRA = 0;
                    
                }
                    
                if (R_LED == 0)
                    G_LED = 1;
                          
                 }
       }  
      
         
unsigned char concatenate_6 (char first, char second, char third, char fourth, char fif,  char sixth)
{
    return (((((((((first << 1) | second) << 1) | third) << 1) | fourth) << 1 | fif) << 1) | sixth);
}
         
         
         
unsigned char concatenate_5 (char first, char second, char third, char fourth, char fif)
{
    return (((((((first << 1) | second) << 1) | third) << 1) | fourth) << 1 | fif);
}