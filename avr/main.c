/** \file main.c
  *
  * \brief Entry point for hardware Bitcoin wallet.
  *
  * This file is licensed as described by the file LICENCE.
  */

#include <avr/interrupt.h>
#include "../common.h"
#include "../stream_comm.h"
#include "../wallet.h"
#include "../xex.h"
#include "hwinit.h"
#include "lcd_and_input.h"

/** This will be called whenever something very unexpected occurs. This
  * function must not return. */
void fatalError(void)
{
	streamError();
	cli();
	for (;;)
	{
		// do nothing
	}
}

/** Entry point. This is the first thing which is called after startup code.
  * This never returns. */
int main(void)
{
	initUsart();
	initAdc();
	initLcdAndInput();

	do
	{
		processPacket();
	} while (true);
}

