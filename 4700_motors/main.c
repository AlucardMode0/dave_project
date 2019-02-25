/*
 *  main.c
 *  Created on: 2019 Feb 23 11:00:00
 *  Author: Vere
 */

#include <DAVE.h>

void delay(int times) {
	int i, j;
	for (j = 0; j < times; ++j) {
		for (i = 0; i < 0x5FFF; ++i) {
		}
	}
}

void rotate_motor(uint32_t direction) {
	/*
	 * direction
	 * 1 - clockwise
	 * 0 - counterclockwise
	 */
	uint32_t i = 0, j = 0;
	static uint8_t state = 0;

	DIGITAL_IO_SetOutputLow(&coil1);
	DIGITAL_IO_SetOutputLow(&coil2);
	DIGITAL_IO_SetOutputLow(&coil3);
	DIGITAL_IO_SetOutputLow(&coil4);

	for (j = 0; j < 65; ++j) {
		for (i = 0; i < 32; ++i) {
			switch (state) {
			case 0:
				DIGITAL_IO_SetOutputHigh(&coil1);
				DIGITAL_IO_SetOutputHigh(&coil2);
				DIGITAL_IO_SetOutputLow(&coil3);
				DIGITAL_IO_SetOutputLow(&coil4);
				break;
			case 1:
				DIGITAL_IO_SetOutputLow(&coil1);
				DIGITAL_IO_SetOutputHigh(&coil2);
				DIGITAL_IO_SetOutputHigh(&coil3);
				DIGITAL_IO_SetOutputLow(&coil4);
				break;
			case 2:
				DIGITAL_IO_SetOutputLow(&coil1);
				DIGITAL_IO_SetOutputLow(&coil2);
				DIGITAL_IO_SetOutputHigh(&coil3);
				DIGITAL_IO_SetOutputHigh(&coil4);
				break;
			case 3:
				DIGITAL_IO_SetOutputHigh(&coil1);
				DIGITAL_IO_SetOutputLow(&coil2);
				DIGITAL_IO_SetOutputLow(&coil3);
				DIGITAL_IO_SetOutputHigh(&coil4);
				break;
			default:
				break;
			}

			if (direction) {
				state = (state + 1) % 4;
			} else {
				if (state == 0) {
					state = 3;
				} else {
					state -= 1;
				}
			}

			delay(1);
		}
	}
}

int main(void) {
	DAVE_STATUS_t status;

	/* Initialization of DAVE APPs  */
	status = DAVE_Init();

	if (status != DAVE_STATUS_SUCCESS) {
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while (1U) {

		}
	}

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while (1U) {

		rotate_motor(1);

		//delay - il faci tu cat vrei puza dintre rotiri
		delay(500);

		rotate_motor(0);

		for (;;)
			;
	}
}
