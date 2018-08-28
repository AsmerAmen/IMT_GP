/*
 * _main.c
 *
 * Created: 28/Aug/2018
 *  Author: Asmer
 */ 

#include <avr/io.h>
#include "DIO.h"
#include "ADC_Driver.h"
#include <util/delay.h>
#include "utilss.h"

#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"

#include "LCD.h"

/* Define Tasks Priorities */
#define  TASK1_PRIORITY (2)
#define  TASK2_PRIORITY (2)

/*tasks codes prototypes */
 void check_temp_task(void*pvParamter);
 void write_temp_task(void*pvParamter);

 /* create a semaphor */
  xSemaphoreHandle temp_ready_semaphore;

  /* create a queue */
  xQueueHandle xTempValue_Queue;




int main(void)
{


	/* DIO configuration */
	DIO_voidSetPinDirection(DIO_u8PinA6, DIO_u8PinIp);
	DIO_voidSetPortDirection('C', DIO_u8PinOp);

	/*initialize Resources*/
	LCD_voidInit();
	ADC_voidInit();

	/*Create Queue to hold temperature value*/
	xTempValue_Queue = xQueueCreate(1, sizeof (int));

	/*If Queue was created, proceed, otherwise do nothing.*/
	if(xTempValue_Queue != NULL){

		/*Create tasks*/
		xTaskCreate(check_temp_task, "check_temp", 400, NULL, TASK1_PRIORITY, NULL);
		xTaskCreate(write_temp_task, "write_temp", 400, NULL, TASK2_PRIORITY, NULL);

		/*Create binary semaphore with initial value 0 because we used it for sync. between INTERRUPT and TASK*/
		temp_ready_semaphore = xSemaphoreCreateRecursiveMutex();


		/*start Scheduler */
		vTaskStartScheduler();
	}
	else{
		for(;;);
	}
	
	return 0;
    
}

/*Task1 Code */
 void check_temp_task(void*pvParamter)
{
//	xSemaphoreTakeRecursive(temp_ready_semaphore, 100);
	int sampled, analog;
	portBASE_TYPE xStatus;
	for (;;)
	{
		sampled = ADC_u16Read(5);
		analog = (sampled * (5*100))/RESOLUTION;

		xStatus = xQueueSendToBack(xTempValue_Queue, &analog, 1000);
		if (xStatus != pdPASS){
			LCD_voidClear();
			LCD_voidString("T1: Not Send.");
			_delay_ms(2000);
		}
//	xSemaphoreGive(temp_ready_semaphore);
		taskYIELD();

	}

		
}

/*Task 2 Code*/
 void write_temp_task(void*pvParamter)
{
//	 xSemaphoreTakeRecursive(temp_ready_semaphore, 100);
	 portBASE_TYPE xStatus;
	 int recieveValue;

	while(1)
	{
		if(uxQueueMessagesWaiting(xTempValue_Queue)!=0){
			xStatus = xQueueReceive(xTempValue_Queue, &recieveValue, 1000/portTICK_RATE_MS);
			if(xStatus==pdPASS){
				LCD_voidClear();
				LCD_voidString("Temp:");
				LCD_voidInteger(recieveValue);
				_delay_ms(2000);
			}
			else{
				LCD_voidClear();
				LCD_voidString("T2: Not received.");
				_delay_ms(2000);
			}

		}
//		xSemaphoreGiveRecursive(temp_ready_semaphore);

	}
}
