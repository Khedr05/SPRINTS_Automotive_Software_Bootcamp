/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "event_groups.h"
#include "queue.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/

#define BIT_0	( 1 << 0 )
#define BIT_1	( 1 << 1 )
#define BIT_2	( 1 << 2 )
#define BIT_3	( 1 << 3 )
#define BIT_4	( 1 << 4 )


EventGroupHandle_t edgeEventGroup = NULL;
EventBits_t eventOfEdge;

TaskHandle_t btnOneEdgeScanningTask_Handler = NULL;
TaskHandle_t btnTwoEdgeScanningTask_Handler = NULL;
TaskHandle_t uartSendString100msTask_Handler = NULL;

QueueHandle_t uartQueue = NULL;
TaskHandle_t createUartQueueTask_Handler = NULL;


TaskHandle_t uartConsumerTask_Handler = NULL;
TaskHandle_t uartSendTask_Handler = NULL;

struct uartQueueMessage
{
    const signed char messageData[ 27 ];
};

struct uartQueueMessage btnOneRisingEdge = {"\nbtnOneRisingEdgeMassage"};
struct uartQueueMessage btnOneFallingEdge = {"\nbtnOneFallingEdgeMassage"};

struct uartQueueMessage btnTwoRisingEdge = {"\nbtnTwoRisingEdgeMassage"};
struct uartQueueMessage btnTwoFallingEdge = {"\nbtnTwoFallingEdgeMassage"};

struct uartQueueMessage stringOf100MsTask = {"\n100MsTaskMassage"};



void createUartQueueTask(void * pvParameters)
{
	for(;;)
	{
		 uartQueue = xQueueCreate(20 , sizeof(struct uartQueueMessage ));
		
		if( uartQueue == NULL )
    {
			/* Do Nothing */
    }
		else
		{
			 vTaskSuspend(createUartQueueTask_Handler);
		}
	}
}



void btnOneEdgeScanningTask(void * pvParameters)
{
	pinState_t preState = PIN_IS_LOW;
	pinState_t newState;
	for(;;)
	{
	     newState = GPIO_read(PORT_0 , PIN0);
			 if((preState == PIN_IS_HIGH) && (newState == PIN_IS_LOW))
			 {
					 eventOfEdge = xEventGroupSetBits( edgeEventGroup , BIT_0);
			 }
			 else if((preState == PIN_IS_LOW) && (newState == PIN_IS_HIGH))
			 {
					eventOfEdge = xEventGroupSetBits( edgeEventGroup , BIT_1);
			 }
			 else
			 {
				 /* Do Nothing */
			 }
			preState = newState; 
		 	vTaskDelay(50);
		 
	}	
}

void btnTwoEdgeScanningTask(void * pvParameters)
{
	pinState_t preState = PIN_IS_LOW;
	pinState_t newState;
	for(;;)
	{
	     newState = GPIO_read(PORT_0 , PIN1);
			 if((preState == PIN_IS_HIGH) && (newState == PIN_IS_LOW))
			 {
					 eventOfEdge = xEventGroupSetBits( edgeEventGroup , BIT_2);
			 }
			 else if((preState == PIN_IS_LOW) && (newState == PIN_IS_HIGH))
			 {
					eventOfEdge = xEventGroupSetBits( edgeEventGroup , BIT_3);
			 }
			 else
			 {
				 /* Do Nothing */
			 }
			preState = newState; 
		 	vTaskDelay(50);	 
	}	
}

void uartSendString100msTask(void * pvParameters)
{
	for(;;)
	{
		eventOfEdge = xEventGroupSetBits( edgeEventGroup , BIT_4);
		vTaskDelay(100);
	}	
}

void uartConsumerTask(void * pvParameters)
{
	for(;;)
	{ 
		   eventOfEdge = xEventGroupWaitBits(
            edgeEventGroup,   
            BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_4, 
            pdTRUE,        
            pdFALSE,      
            0);
		  if((eventOfEdge & BIT_0) != 0)
			{
				 eventOfEdge = 0;
				 xQueueSend( uartQueue,btnOneFallingEdge.messageData, ( TickType_t ) 100);
			}
			else if((eventOfEdge & BIT_1) != 0)
			{
				eventOfEdge = 0;
				xQueueSend( uartQueue,btnOneRisingEdge.messageData, ( TickType_t ) 100);
			}
			else if((eventOfEdge & BIT_2) != 0)
			{
				eventOfEdge = 0;
				xQueueSend( uartQueue,btnTwoFallingEdge.messageData, ( TickType_t ) 100);
			}
			else if((eventOfEdge & BIT_3) != 0)
			{
				eventOfEdge = 0;
				xQueueSend( uartQueue,btnTwoRisingEdge.messageData, ( TickType_t ) 100);
			}
			else if((eventOfEdge & BIT_4) != 0)
			{
				eventOfEdge = 0;
				xQueueSend( uartQueue,stringOf100MsTask.messageData, ( TickType_t ) 100);
			}
			else
			{
				/* Do Nothing */
			}
			vTaskDelay(50);
	}	
}
void uartSendTask(void * pvParameters)
{
	for(;;)
	{
		const signed char str[27];
	 if( uartQueue != NULL )
   {
      if( xQueueReceive( uartQueue,(void *)str,( TickType_t ) 100 ) == pdPASS )
      {
         while(vSerialPutString(str , sizeof(str) / sizeof(str[0])) == pdFALSE);
      }
			else
			{
				/* Do Nothing */
			}
   }
	 else
	 {
		  /* Do Nothing */
	 }		 
		vTaskDelay(40);
	}
}
/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

	edgeEventGroup = xEventGroupCreate();
    /* Create Tasks here */
	  xTaskCreate
	(
			 createUartQueueTask,
			 "createUartQueueTask",
			 configMINIMAL_STACK_SIZE,
			 (void *)1,
				1,
			&createUartQueueTask_Handler	
	);
	 xTaskCreate
	(
			 btnOneEdgeScanningTask,
			 "btnOneEdgeScanningTask",
			 configMINIMAL_STACK_SIZE,
			 (void *)1,
				1,
			&btnOneEdgeScanningTask_Handler	
	);
		xTaskCreate
	(
			 btnTwoEdgeScanningTask,
			 "btnTwoEdgeScanningTask",
			 configMINIMAL_STACK_SIZE,
			 (void *)1,
				1,
			&btnTwoEdgeScanningTask_Handler	
	);
		 xTaskCreate
	(
			 uartSendString100msTask,
			 "uartSendString100msTask",
			 configMINIMAL_STACK_SIZE,
			 (void *)1,
				1,
			&uartSendString100msTask_Handler	
	);
    xTaskCreate
	(
			 uartConsumerTask,
			 "uartConsumerTask",
			 configMINIMAL_STACK_SIZE,
			 (void *)1,
				1,
			&uartConsumerTask_Handler	
	);			 
    xTaskCreate
	(
			 uartSendTask,
			 "uartSendTask",
			 configMINIMAL_STACK_SIZE,
			 (void *)1,
				1,
			&uartSendTask_Handler	
	);	
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


