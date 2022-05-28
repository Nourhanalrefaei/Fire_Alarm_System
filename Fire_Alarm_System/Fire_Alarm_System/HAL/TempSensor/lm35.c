/*
 * lm35.c
 *
 * Created: 3/31/2022 6:47:47 PM
 *  Author: NourhanAlrefaei
 */ 
#include "lm35.h"


ret_status TempSensor_init(tempSensor_t *tempSensor)
{
	ret_status ret=R_NOK;
	if((tempSensor!=NULL_POINTER)&&(tempSensor->port_type==PORT_A)&&(tempSensor->pin_type<PIN_INVALID))
	{
		gpio_pin_direction_initialize(tempSensor->port_type,tempSensor->pin_type,DIRECTION_INPUT);
		adc_init(tempSensor->pin_type);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
ret_status TempSensor_get_value(tempSensor_t *tempSensor,uint8_type* temp_value)
{
	float32_type Voltage=ZERO_INIT;
	ret_status ret=R_NOK;
	if((tempSensor!=NULL_POINTER)&&(tempSensor->port_type==PORT_A)&&(tempSensor->pin_type<PIN_INVALID))
	{
		_delay_us(50);
		adc_start_conversion(tempSensor->pin_type);
		uint16_type adc_value=adc_read_value();         //Read Analog Channel 
		//Calculate the Temperature 
		Voltage =(5.0/1023.0)*adc_value;
		*temp_value=Voltage/0.01;                      // temp=(voltage/10mv)
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}