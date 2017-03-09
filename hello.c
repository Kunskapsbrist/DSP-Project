//---------------------------------------------------------
// main example 1
//---------------------------------------------------------
#include "hellocfg.h"			//BIOS include file
#include "framework.h"
#include "linear_filter_api.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

static int index = 0;
static float buffer[32000];
static uint8_t dip1 = 0;
static uint8_t dip2 = 0;
static uint8_t dip6 = 0;
static uint8_t dip7 = 0;
static uint8_t dip8 = 0;
static int ledMode = 0;

p_linear_filter lp_filter;
p_linear_filter bp_filter;
p_linear_filter hp_filter;

//---------------------------------------------------------
//---------------------------------------------------------
void main(void)
{
	lp_filter = filter_init(a_lp, N_LP_A, b_lp, N_LP_B);
	bp_filter = filter_init(a_bp, N_BP_A, b_bp, N_BP_B);
	hp_filter = filter_init(a_hp, N_HP_A, b_hp, N_HP_B);
	initAll();
	return;  		// return to BIOS scheduler
}

int addToBuffer(float s16, int i){

	buffer[i] = s16;

	i++;
	i = i % 32000;
	return i;
}

float readFromBuffer(int i){

	float s16 = buffer[i];
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

	switch (ledMode){

	case 0:
		LED_turnOff(LED_1);
		LED_turnOff(LED_2);
		break;

	case 1:
		LED_toggle(LED_1);
		LED_toggle(LED_2);

	}
}

//---------------------------------------------------------
//---------------------------------------------------------
void audioHWI(void)
{
	float s16;
	float f1, f2, f3;
	int16_t mask = 0x0000;


	s16 = (float) read_audio_sample();

	if (MCASP->RSLOT)
	{

		if (dip1){	// IF SWITCH 1 ON,

			if (dip2){

				// LED 1 AT 2HZ

				s16 = readFromBuffer(index);
				index++;
				index = index % 32000;

				if (dip6){
					f1 = filter_filter(lp_filter, &s16);
				}

				if (dip7){
					f2 = filter_filter(bp_filter, &s16);
				}

				if (dip8){
					f3 = filter_filter(hp_filter, &s16);
				}

				s16 = f1 + f2 + f3;

			} else {

				ledMode = 1;

				// BOTH LEDS AT 20HZ
				index = addToBuffer(s16, index);
			}

		} else {	// IF SWITCH 1 OFF, NO OUTPUT

			// BOTH LEDS OFF
			ledMode = 0;
			s16 = 0.0;
		}



	} else {
		s16 = 0.0;
	}

	write_audio_sample((int16_t) s16);
}
