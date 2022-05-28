/*
 * Fire_Alarm_System.c
 *
 * Created: 5/26/2022 9:07:22 PM
 * Author : NourhanAlrefaei
 */ 

#define  F_CPU    16000000UL
#include "System/System.h"

int main(void)
{
	Sys_init();
    while (1) 
    {
		switch(	Current_state)
		{
			case Normal_Mode:
			{
				Normal_state();
				break;
			}
			case Fire_Mode:
			{
				Fire_state();
				break;
			}
			default:break;
		}
    }
}

