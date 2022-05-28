/*
 * lm35.h
 *
 * Created: 3/31/2022 6:48:04 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef LM35_H_
#define LM35_H_
#include "../../MCAL/GPIO/mcal_gpio.h"
#include "../../MCAL/ADC/adc.h"

/*Section:Data Type Definitions*/
typedef struct{
	uint8_type  port_type:4;
	uint8_type  pin_type:3;
	uint8_type  reserved:1; 
}tempSensor_t;

/*Section:Function Decelerations*/

ret_status TempSensor_init(tempSensor_t *tempSensor);
ret_status TempSensor_get_value(tempSensor_t *tempSensor,uint8_type* temp_value);



#endif /* LM35_H_ */