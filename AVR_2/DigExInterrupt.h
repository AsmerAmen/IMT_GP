/*
 *  Digital External Interrupt.c
 *
 *  Created on: Sep 16, 2017
 *      Author: Asmer Amen
 */

#ifndef DIGEXINTERRUPT_H_
#define DIGEXINTERRUPT_H_

	/*		Registers		*/

#define SREG  *((U8*) 0x5F)
#define GICR  *((U8*) 0x5B)
#define MCUCR *((U8*) 0x55)

/***************************************************************/

		/**		Configuration		**/

/* GICR: General Interrupt Control Register */
	/* Interruption Pins
	 * Enable -> 1
	 */
#define INT0 1  //Bit 6
#define INT1 1	//Bit 7
#define INT2 0	//Bit 5

/* MCUCR: MCU Control Register */
	/* Interrupt Sense control
	 * ISC11, ISC10 for INT1
	 * ISC01, ISC00 for INT0
	 *
	 * Low level -> 00, Any change -> 01
	 * Falling edge -> 10
	 * Rising edge -> 11
	 */
#define ISC11 1 //Bit3
#define ISC10 1 //Bit2

#define ISC01 1 //Bit1
#define ISC00 0	//Bit0


/******************************************************************/

/* Prototypes */


void DEI_voidInit(void);

/* __vector: jump to vector table, _1: index 1 */
void __vector_1 (void) __attribute__((signal,__INTR_ATTRS));

/* __vector: jump to vector table, _16: index 17 */
void __vector_16 (void) __attribute__((signal,__INTR_ATTRS));

#endif /* DIGEXINTERRUPT_H_ */
