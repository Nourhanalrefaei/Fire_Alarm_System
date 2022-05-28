/*
 * System.c
 *
 * Created: 5/26/2022 11:22:21 PM
 *  Author: NourhanAlreafei
 */ 
#include "System.h"

/***********************Hardware Components*****************************/
char_lcd_t char_lcd={.lcd_rw_port=PORT_B,.lcd_rw_pin=PIN_2,.lcd_rs_port=PORT_B,.lcd_rs_pin=PIN_1,.lcd_en_port=PORT_B,.lcd_en_pin=PIN_3,
	                 .lcd_data_port=PORT_A,.lcd_data_pin4=PIN_4,.lcd_data_pin5=PIN_5,
					 .lcd_data_pin6=PIN_6,.lcd_data_pin7=PIN_7};
tempSensor_t tempSen={.port_type=PORT_A,.pin_type=PIN_0};
led_t led_indicator={.port_info.port_type=PORT_C,.port_info.pin_type=PIN_2,.led_stat=LED_OFF};
relay_t Fan={.port_name=PORT_B,PIN_4};
	

void Sys_init(void)
{
	lcd_initialize(&char_lcd);
	TempSensor_init(&tempSen);
	Buzz_INIT();
	led_init(&led_indicator);
	relay_initialize(&Fan);
	
	Current_state=Normal_Mode;
}
void Normal_state(void)
{
	relay_turn_off(&Fan);
	led_turn_off(&led_indicator);
	Buzz_OFF();
	TempSensor_get_value(&tempSen,&Measured_Temp);
	lcd_send_string_data_pos(&char_lcd,0,0,"Temperature:");
	byte_to_string(Measured_Temp,Measured_Temp_txt);
	lcd_send_string_data_current_pos(&char_lcd,Measured_Temp_txt);
	lcd_send_string_data_current_pos(&char_lcd,"C");
	if(Measured_Temp>Temp_REF)
	{
		Current_state=Fire_Mode;
	}
	
}
void Fire_state(void)
{
	lcd_send_string_data_pos(&char_lcd,0,0,"There is a fire");
	relay_turn_on(&Fan);
	Buzz_ON();
	led_turn_toggle(&led_indicator);
	_delay_ms(1000);
	Buzz_OFF();
	TempSensor_get_value(&tempSen,&Measured_Temp);
	if(Measured_Temp<Temp_REF)
	{
		Current_state=Normal_Mode;
	}
	
}