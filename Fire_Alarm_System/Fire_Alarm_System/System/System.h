/*
 * System.h
 *
 * Created: 5/26/2022 11:22:50 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "..\MCAL/GPIO/mcal_gpio.h"
#include "..\HAL/Char_LCD/hal_char_lcd.h"
#include "..\HAL/TempSensor/lm35.h"
#include "..\HAL/DC_Motor/hal_dc_motor.h"
#include "..\HAL/Relay/hal_relay.h"
#include "..\HAL/Buzzer/BUZZ.h"
#include "..\HAL/Led/hal_led.h"

#define  Normal_Mode               0
#define  Fire_Mode                 1

uint8_type Current_state;
uint8_type Measured_Temp;
uint16_type Measured_Temp_txt[4];
#define  Temp_REF                  40

/*Sys_init:initialize all Components and peripherals*/
void Sys_init(void);
/*Normal State: in this state (Buzzer-Fan-Led)are off and only ADC start conversion 
to read the value of temperature sensor and display on LCD*/
void Normal_state(void);
/*Fire State: in this state (Buzzer-Fan-Led) are on until the ADC read value<Temp_REF*/
void Fire_state(void);

#endif /* SYSTEM_H_ */