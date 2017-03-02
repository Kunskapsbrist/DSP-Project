//---------------------------------------------------------
// main example 1
//---------------------------------------------------------
#include "hellocfg.h"			//BIOS include file
#include "framework.h"
#include <stdio.h>
#include <stdlib.h>

static int index = 0;
static int16_t buffer[32000];
static uint8_t dip1 = 0;
static uint8_t dip2 = 0;
static uint8_t dip6 = 0;
static uint8_t dip7 = 0;
static uint8_t dip8 = 0;

//---------------------------------------------------------
//---------------------------------------------------------
void main(void)
{
	initAll();
	return;  		// return to BIOS scheduler
}

int addToBuffer(int16_t s16, int i){

	buffer[i] = s16;

	i++;
	i = i % 32000;
	return i;
}

int16_t readFromBuffer(int i){

	int16_t s16 = buffer[i];
	return s16;
}

void led2Hz(void){

}

void led6Hz(void){

}

void led20Hz(void){
	DIP_get(DIP_1, &dip1);
	DIP_get(DIP_2, &dip2);
	DIP_get(DIP_6, &dip6);
	DIP_get(DIP_7, &dip7);
	DIP_get(DIP_8, &dip8);
}

//---------------------------------------------------------
//---------------------------------------------------------
void audioHWI(void)
{
	int16_t s16;
	int16_t mask = 0x0000;


	s16 = read_audio_sample();

	if (MCASP->RSLOT)
	{

		if (dip1){	// IF SWITCH 1 ON,

			if (dip2){


				s16 = readFromBuffer(index);
				index++;
				index = index % 32000;

				if (dip6){

				}

				if (dip7){

				}

				if (dip8){

				}

			} else {
				index = addToBuffer(s16, index);
			}

		} else {	// IF SWITCH 1 OFF, NO OUTPUT
			s16 &= mask;
		}



	} else {
		s16 &= mask;
	}

	write_audio_sample(s16);
}
