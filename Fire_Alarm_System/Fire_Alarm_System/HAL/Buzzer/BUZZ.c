/*
 * BUZZ.c
 *
 * Created: 2/5/2022 4:08:04 PM
 *  Author: DELL
 */ 

#include "BUZZ.h"

void Buzz_INIT(void)
{
	gpio_pin_direction_initialize(BUZZ_PORT,BUZZ_PIN,DIRECTION_OUTPUT);
}

void Buzz_ON(void)
{
	gpio_set_pin(BUZZ_PORT,BUZZ_PIN);
}

void Buzz_OFF(void)
{
	gpio_clear_pin(BUZZ_PORT,BUZZ_PIN);
}