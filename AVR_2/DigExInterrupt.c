/*
 * Digital External Interrupt.c
 *
 *  Created on: Sep 16, 2017
 *      Author: Asmer Amen
 */


#include "Types.h"
#include "utilss.h"
#include "DIO.h"

#include "DigExInterrupt.h"
#include "ADC_Driver.h"  // --> Registers

/*
 * Digital External Interrupt Initialization
 */
void DEI_voidInit(void)
{
	/* Enable 'I' the global interrupt. */
	set_bit(SREG, 7);

	/* Enable the interrupt INT0,INT1, INT2
	 * Check Configuration
	 */
	GICR |= (INT0<<6) | (INT1<<7) | (INT2<<5);

	/*
	 * Configure the external interrupt INT0, INT1
	 * Sense control.
	 */
	MCUCR |= (ISC00<<0) | (ISC01<<1) | (ISC10<<2) | (ISC11<<3);
}	/* end function DEI_voidInit */

/*
// ADC Vector
void __vector_16 (void)
{
	U8 DigValue = ( ADCH * V_REF ) / RESOLUTION ;

}
*/
