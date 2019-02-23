/*
 * main.c
 *
 *  Created on: 2019 Feb 21 21:42:19
 *  Author: Dante woandoiawndnaw doawn danoidanwdoawn oinwoan oawin nwoisnoawnd oinwoan
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
void delay(void)
{
	int i,j=1;
	for(i=0;i<0xFFFF;++i)
		j=0;
}


void invarte_motoare_stangaC(uint32_t jumatati)
{
	DIGITAL_IO_SetOutputLow(&coil1);
	  DIGITAL_IO_SetOutputLow(&coil2);
	  DIGITAL_IO_SetOutputLow(&coil3);
	  DIGITAL_IO_SetOutputLow(&coil4);
	  uint32_t i=0,j=0;
	  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
	  for(i=1;i<=jumatati;++i)
		  for (j=0;j<25;j++)
		  {  	  delay();
		  		//coil3=0;				// end step 3
		  	//	coil1=1;
		  		DIGITAL_IO_SetOutputLow(&coil3);
		  		DIGITAL_IO_SetOutputHigh(&coil1);
		  											// step 1

		  		delay();
		  	//	coil4=0;				// end step 4
		  	//	coil2=1;           		// step 2
		  		DIGITAL_IO_SetOutputLow(&coil4);
		  		DIGITAL_IO_SetOutputHigh(&coil2);
		  		delay();
		  		//coil1=0;    			// end step 1
		   		//coil3=1;          		// step 3
		   		DIGITAL_IO_SetOutputLow(&coil1);
		   		DIGITAL_IO_SetOutputHigh(&coil3);
		  		delay();
		  		//coil2=0;				// end step 2
		  		//coil4=1;          		// step 4
		  		DIGITAL_IO_SetOutputLow(&coil2);
		  		DIGITAL_IO_SetOutputHigh(&coil4);
		  }

}

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {


    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  invarte_motoare_stangaC(10);
	  for(;;);
  }
}
