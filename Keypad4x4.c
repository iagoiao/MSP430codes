/*Function that reads a 4x4 keypad and return the pressed key as a char
 *Code was made more flexible allowing changes at the pins to be made in a easy way
 */

#include "driverlib.h"
char KeyPadRead();
//Defines for the pins used by the keypad
#define KeyPadRow1Pin	GPIO_PIN1
#define KeyPadRow2Pin	GPIO_PIN2
#define KeyPadRow3Pin	GPIO_PIN0
#define KeyPadRow4Pin	GPIO_PIN1

#define KeyPadRow1Port	GPIO_PORT_P1
#define KeyPadRow2Port	GPIO_PORT_P1
#define KeyPadRow3Port	GPIO_PORT_P3
#define KeyPadRow4Port	GPIO_PORT_P3



#define KeyPadColumn1Pin	GPIO_PIN2
#define KeyPadColumn2Pin	GPIO_PIN3
#define KeyPadColumn3Pin	GPIO_PIN3
#define KeyPadColumn4Pin	GPIO_PIN4

#define KeyPadColumn1Port	GPIO_PORT_P3
#define KeyPadColumn2Port	GPIO_PORT_P3
#define KeyPadColumn3Port	GPIO_PORT_P1
#define KeyPadColumn4Port	GPIO_PORT_P1


uint8_t test=0;
void main(void)
{

    //Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);
    delay(10);//Delay 1 seg


    while(1)
    {
    	test= KeyPadRead();
    	if(test=='1')
    		test=1;
    }

    __bis_SR_register(LPM4_bits + GIE);

    //For debugger
    __no_operation();
}
//Functions
char KeyPadRead()
{

	/* Line 8 -	P1.1
	 * Line 7 -	P1.2
	 * Line 6 -	P3.0
	 * Line 5 -	P3.1
	 * Line 4 -	P3.2
	 * Line 3 -	P3.3
	 * Line 2 -	P1.3
	 * Line 1 -	P1.4
	 */
	char pressedkey;
    uint8_t IsShorted=0;
	//Set row pins as outputs


    GPIO_setAsOutputPin(KeyPadRow1Port,KeyPadRow1Pin);
    GPIO_setAsOutputPin(KeyPadRow2Port,KeyPadRow2Pin);
	GPIO_setAsOutputPin(KeyPadRow3Port,KeyPadRow3Pin);
	GPIO_setAsOutputPin(KeyPadRow4Port,KeyPadRow4Pin);

    //Set output to low on all of the first 4 pins
    GPIO_setOutputLowOnPin(KeyPadRow1Port,KeyPadRow1Pin);
    GPIO_setOutputLowOnPin(KeyPadRow2Port,KeyPadRow2Pin);
    GPIO_setOutputLowOnPin(KeyPadRow3Port,KeyPadRow3Pin);
    GPIO_setOutputLowOnPin(KeyPadRow4Port,KeyPadRow4Pin);


    //Set the remaining 4 pins as inputs with pull down resistors
    GPIO_setAsInputPinWithPullDownResistor(KeyPadColumn1Port,KeyPadColumn1Pin);
    GPIO_setAsInputPinWithPullDownResistor(KeyPadColumn2Port,KeyPadColumn2Pin);
    GPIO_setAsInputPinWithPullDownResistor(KeyPadColumn3Port,KeyPadColumn3Pin);
    GPIO_setAsInputPinWithPullDownResistor(KeyPadColumn4Port,KeyPadColumn4Pin);

    //Set output High on the first pin, If it is connected to one of the other pins that pin must read 1 otherwise it should read 0
    GPIO_setOutputHighOnPin(KeyPadRow1Port,KeyPadRow1Pin);
    //Check if any of the buttons of the first row is pressed
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn1Port,KeyPadColumn1Pin);
    if(IsShorted==1)
    {
    	pressedkey='1';
    	return pressedkey;
    }

    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn2Port,KeyPadColumn2Pin);
    if(IsShorted==1)
    {
     	pressedkey='2';
       	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn3Port,KeyPadColumn3Pin);
    if(IsShorted==1)
    {
      	pressedkey='3';
       	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn4Port,KeyPadColumn4Pin);
    if(IsShorted==1)
    {
      	pressedkey='A';
       	return pressedkey;
    }
    GPIO_setOutputLowOnPin(KeyPadRow1Port,KeyPadRow1Pin);
    //Check if any of the buttons of the second row is pressed
    GPIO_setOutputHighOnPin(KeyPadRow2Port,KeyPadRow2Pin);
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn1Port,KeyPadColumn1Pin);
   	if(IsShorted==1)
    {
       	pressedkey='4';
      	return pressedkey;
    }

   	IsShorted	=	GPIO_getInputPinValue(KeyPadColumn2Port,KeyPadColumn2Pin);
   	if(IsShorted==1)
    {
    	pressedkey='5';
      	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn3Port,KeyPadColumn3Pin);
    if(IsShorted==1)
    {
    	pressedkey='6';
       	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn4Port,KeyPadColumn4Pin);
    if(IsShorted==1)
    {
      	pressedkey='B';
       	return pressedkey;
    }
    GPIO_setOutputLowOnPin(KeyPadRow2Port,KeyPadRow2Pin);

    //Check if any of the buttons of the third row is pressed
    GPIO_setOutputHighOnPin(KeyPadRow3Port,KeyPadRow3Pin);
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn1Port,KeyPadColumn1Pin);
   	if(IsShorted==1)
    {
       	pressedkey='7';
      	return pressedkey;
    }

   	IsShorted	=	GPIO_getInputPinValue(KeyPadColumn2Port,KeyPadColumn2Pin);
   	if(IsShorted==1)
    {
    	pressedkey='8';
      	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn3Port,KeyPadColumn3Pin);
    if(IsShorted==1)
    {
    	pressedkey='9';
       	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn4Port,KeyPadColumn4Pin);
    if(IsShorted==1)
    {
      	pressedkey='C';
       	return pressedkey;
    }
    GPIO_setOutputLowOnPin(KeyPadRow3Port,KeyPadRow3Pin);

    //Check if any of the buttons of the fourth row is pressed
    GPIO_setOutputHighOnPin(KeyPadRow4Port,KeyPadRow4Pin);
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn1Port,KeyPadColumn1Pin);
   	if(IsShorted==1)
    {
       	pressedkey='*';
      	return pressedkey;
    }

   	IsShorted	=	GPIO_getInputPinValue(KeyPadColumn2Port,KeyPadColumn2Pin);
   	if(IsShorted==1)
    {
    	pressedkey='0';
      	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn3Port,KeyPadColumn3Pin);
    if(IsShorted==1)
    {
    	pressedkey='#';
       	return pressedkey;
    }
    IsShorted	=	GPIO_getInputPinValue(KeyPadColumn4Port,KeyPadColumn4Pin);
    if(IsShorted==1)
    {
      	pressedkey='D';
       	return pressedkey;
    }
    //If the code reach this point means that no key was pressed
    pressedkey='X';
    GPIO_setOutputHighOnPin(KeyPadRow4Port,KeyPadRow4Pin);
    //Set all outputs to low
    return pressedkey;

}

void delay(int delayin100ms)
{

//    BCSCTL3 |= XCAP_3;					// xtal has 12.5 pF caps
    TA1CCR0 = 1638*2*delayin100ms;					// f_xtal / 2 - 1 gives 2 Hz *2 = 1 second
    TA1CTL = TASSEL_1 + MC_1 + TA1CTL;	                // ACLK + Up Mode + Clear timer
    TA1CTL &= ~BIT0;					// reset TAIFG
    while ((TA1CTL & BIT0) == 0)
    { 		        // wait for timer to reach TACCR0
    }
} // delay


//******************************************************************************
//
//This is the PORT1_VECTOR interrupt vector service routine
//
//******************************************************************************
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(PORT1_VECTOR)))
#endif
void Port_1(void)
{
    //P1.0 = toggle
    GPIO_toggleOutputOnPin(
        GPIO_PORT_P1,
        GPIO_PIN0
        );

    //P1.4 IFG cleared
    GPIO_clearInterrupt(
        GPIO_PORT_P1,
        GPIO_PIN4
        );
}
