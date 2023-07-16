#include <mega32a.h>        `

#define PIN1  PORTA.0
#define PIN2  PORTA.1
#define PIN3  PORTA.2
#define PIN4  PORTA.3
#define PIN6  PORTA.4
#define PIN10 PORTA.5
#define PIN12 PORTA.6
#define PIN13 PORTA.7
#define PIN14 PORTB.0
#define PIN15 PORTB.1

#define PIN5  PORTC.0
#define PIN7  PORTC.1
#define PIN9  PORTC.2
#define PIN11 PORTC.3

#define G_LED PORTD.2
#define R_LED PORTD.3

unsigned char concatenate (char first, char second, char third, char fourth);

void main()
{
    char D = 5;
    char i, j; 

    DDRA = 0xFF;     //1=input for ICs output for avr
    DDRC = 0x0;
    DDRB = 0xFF; 
    DDRD = 0xFF;
    
    while (1)
          { 
             for (i = 0; i <= 1; i++) 
              {
              for  (j=0;j <= 15;j++)
              {
                 PIN13 = j>>3 & 1;
                 PIN14 = j>>2 & 1 ;
                 PIN15 = j>>1 & 1;
                 PIN1 = j & 1 ;
                        
                PIN12 = D>>3 & 1;
                PIN10 = D>>2 & 1;
                PIN6 = D>>1 & 1;
                PIN4 = D & 1;
                 
                PIN2= 0;
                PIN3=0;
                PIN3=1;
                PIN2=1;
                D = D ^(15);
                }
                
                for (j=0; j <= 15; j++)
                {
                 PIN13 = j>>3 & 1;
                 PIN14 = j>>2 & 1 ;
                 PIN15 = j>>1 & 1 ;
                 PIN1 = j & 1 ;
                
                PIN2=0;
                
                if(concatenate(!PIN11, !PIN9, !PIN7, !PIN5) == 13)
                    {
                    R_LED  = 1;
                    }
                    
                PIN2=1;
                D=D^(15);   
                }
                
                D=D^(15);
                }
                      
          
          PIN11=0;
          PIN9=0;
          PIN7=0;
          PIN5=0;
                
          if (concatenate(PIN11, PIN9, PIN7, PIN5) != 0)
          {
            R_LED=1;
          } 
          
          PIN11=1;
          PIN9=1;
          PIN7=1;
          PIN5=1;    
           
          if (concatenate(PIN11, PIN9, PIN7, PIN5) != 15)
          {
            R_LED = 1;
          } 
                                    
          if (R_LED == 0)
           G_LED = 1;
        }
         
        }      


unsigned char concatenate (char first, char second, char third, char fourth)
{
    return ((((((first << 1) | second) << 1) | third) << 1) | fourth);
}
