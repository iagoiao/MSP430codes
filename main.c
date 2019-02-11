/*Function that writes a digit to a seven segment display
 *
 */
/*
current config
seg a P1.7
seg	b P1.6
seg c P3.7
seg d P3.6
seg e P3.5
seg f P3.4
seg g P2.2

disp 1 en P2.1
disp 2 en P2.6
disp 3 en P2.5
disp 4 en P2.0
*/
//Pin Macros to increase the flexibility of the code
#define segAPin	    GPIO_PIN7
#define segBPin		GPIO_PIN6
#define segCPin		GPIO_PIN7
#define segDPin		GPIO_PIN6
#define segEPin		GPIO_PIN5
#define segFPin		GPIO_PIN4
#define segGPin		GPIO_PIN2

#define segAPort    GPIO_PORT_P1
#define segBPort	GPIO_PORT_P1
#define segCPort	GPIO_PORT_P3
#define segDPort	GPIO_PORT_P3
#define segEPort	GPIO_PORT_P3
#define segFPort	GPIO_PORT_P3
#define segGPort	GPIO_PORT_P2

#define Disp1EnablePin  GPIO_PIN1
#define Disp2EnablePin	GPIO_PIN6
#define Disp3EnablePin	GPIO_PIN5
#define Disp4EnablePin	GPIO_PIN0

#define Disp1EnablePort	GPIO_PORT_P2
#define Disp2EnablePort	GPIO_PORT_P2
#define Disp3EnablePort	GPIO_PORT_P2
#define Disp4EnablePort	GPIO_PORT_P2


#include "driverlib.h"
void WriteDigitTo7Seg(int digit, uint8_t displaynum);
void Init7SegPins();

void main(void)
{

    //Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);
    Init7SegPins();
    while(1)
	{
    	WriteDigitTo7Seg(7, 1);
		WriteDigitTo7Seg(24, 2);
		WriteDigitTo7Seg(26, 3);
		WriteDigitTo7Seg(13, 4);
	}

    __bis_SR_register(LPM4_bits + GIE);

    //For debugger
    __no_operation();
}
//Functions
void Init7SegPins()
{
		//Set pins as outputs
	  GPIO_setAsOutputPin(segAPort,segAPin);
	  GPIO_setAsOutputPin(segBPort,segBPin);
	  GPIO_setAsOutputPin(segCPort,segCPin);
	  GPIO_setAsOutputPin(segDPort,segDPin);
	  GPIO_setAsOutputPin(segEPort,segEPin);
	  GPIO_setAsOutputPin(segFPort,segFPin);
	  GPIO_setAsOutputPin(segGPort,segGPin);

	  GPIO_setAsOutputPin(Disp1EnablePort,Disp1EnablePin);
	  GPIO_setAsOutputPin(Disp2EnablePort,Disp2EnablePin);
	  GPIO_setAsOutputPin(Disp3EnablePort,Disp3EnablePin);
	  GPIO_setAsOutputPin(Disp4EnablePort,Disp4EnablePin);


}
void WriteDigitTo7Seg(int digit, uint8_t displaynum)//Assumes common cathode displays, and assumes that the enable is active high
{
	//Disables all segments
	GPIO_setOutputLowOnPin(Disp1EnablePort,Disp1EnablePin);
	GPIO_setOutputLowOnPin(Disp2EnablePort,Disp2EnablePin);
	GPIO_setOutputLowOnPin(Disp3EnablePort,Disp3EnablePin);
	GPIO_setOutputLowOnPin(Disp4EnablePort,Disp4EnablePin);

	switch(displaynum)
	{
	case 1 :
		GPIO_setOutputHighOnPin(Disp1EnablePort,Disp1EnablePin);

		break;
	case 2 :
		GPIO_setOutputHighOnPin(Disp2EnablePort,Disp2EnablePin);

		break;
	case 3 :
		GPIO_setOutputHighOnPin(Disp2EnablePort,Disp3EnablePin);

		break;
	case 4 :
		GPIO_setOutputHighOnPin(Disp4EnablePort,Disp4EnablePin);

		break;
	}



	//Clear all segments
	GPIO_setOutputLowOnPin(segAPort,segAPin);
	GPIO_setOutputLowOnPin(segBPort,segBPin);
	GPIO_setOutputLowOnPin(segCPort,segCPin);
	GPIO_setOutputLowOnPin(segDPort,segDPin);
	GPIO_setOutputLowOnPin(segEPort,segEPin);
	GPIO_setOutputLowOnPin(segFPort,segFPin);
	GPIO_setOutputLowOnPin(segGPort,segGPin);



	switch(digit)
	{
	case 0	://abcdef
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		break;
	case 1	://bc
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		break;
	case 2	://abdeg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 3	://abcdg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);
		break;
	case 4	://bcgf
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		break;
	case 5	://acdgf
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		break;
	case 6	://acdefg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);

		break;
	case 7	://abc
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);

		break;
	case 8	://abcdefg	;
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 9	://abcdfg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);
		break;
	case 10	:		//Shows A abcefg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

	break;
	case 11	:		//Shows b cdefg
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 12	:		//Shows C adef
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);

		break;
	case 13	:		//Shows d bcdeg
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 14	:		//Shows E adefg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 15	:		//Shows F aefg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 16	:		//Shows r aef
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);


		break;
	case 17	:		//Shows t defg
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 18	:		//Shows n ceg
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 19	:		//Shows L def
	GPIO_setOutputHighOnPin(segDPort,segDPin);
	GPIO_setOutputHighOnPin(segEPort,segEPin);
	GPIO_setOutputHighOnPin(segFPort,segFPin);

		break;
	case 20	:		//Shows U bcdef
	GPIO_setOutputHighOnPin(segBPort,segBPin);
	GPIO_setOutputHighOnPin(segCPort,segCPin);
	GPIO_setOutputHighOnPin(segDPort,segDPin);
	GPIO_setOutputHighOnPin(segEPort,segEPin);
	GPIO_setOutputHighOnPin(segFPort,segFPin);

		break;
	case 21	:		//Shows - g
	GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 22	:		//Shows o cdeg
		GPIO_setOutputHighOnPin(segCPort,segCPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;

	case 23	:		//Shows raised o abfg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);

		break;
	case 24:	//shows raised o with a underline abdfg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);
		break;
	case 25: //Shows a _ d
		GPIO_setOutputHighOnPin(segDPort,segDPin);
		break;
	case 26: //Shows nothing

			break;
	case 27: //Shows p abefg
		GPIO_setOutputHighOnPin(segAPort,segAPin);
		GPIO_setOutputHighOnPin(segBPort,segBPin);
		GPIO_setOutputHighOnPin(segEPort,segEPin);
		GPIO_setOutputHighOnPin(segFPort,segFPin);
		GPIO_setOutputHighOnPin(segGPort,segGPin);


			break;
	}
}

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
