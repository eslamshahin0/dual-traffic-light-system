/**
 * *************************************************************************
 *  @file      OS_program.c			
 *  @author    Eslam Shahin (eslamshahin552000@gmail.com)                          
 *  @version   v1.0                                            
 *  @date      10/09/2020                                  
 *  @brief     This file have the implementation of 
 *                          	                                 
 *
 *  @note      This program is distributed in the hope  that it  
 * 	           will be useful,but WITHOUT ANY WARRANTY; without     
 *	           even the implied warranty of  MERCHANTABILITY or     
 *	           FITNESS FOR A PARTICULAR PURPOSE.  
 *                                                      
 * *************************************************************************                                                                
 */

/******************************************************************************
 * Includes
 *******************************************************************************/
// Include libraries
#include "my_types.h"
#include "mcu.h"
// Include files 
#include "os.h"

/******************************************************************************
 * Module Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Module Preprocessor Macros
 *******************************************************************************/

/******************************************************************************
 * Module Typedefs
 *******************************************************************************/

/******************************************************************************
 * Module Variable Definitions
 *******************************************************************************/
/* Array of tasks "Array of STRUCT " */
sTask_t OS_Tasks[MAX_TASKS_NUMBER];

static uint32_t g_CurrentTick = 0;
extern uint32_t SystemCoreClock;
/******************************************************************************
 * Static Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Function Definitions
 *******************************************************************************/

/**
 * @brief Initializes the OS and configures the SysTick timer.
 * 
 * This function sets up the SysTick timer based on the system clock and the desired tick period.
 */
 void OS_voidInit(void)
{
	uint32_t time = (SystemCoreClock / 1000000) * 1000 * OS_TICK_PERIOD_MS;
	SysTick_Config(time);

}

/*
 * @brief Creates a new task with the specified periodicity, function, and initial delay.
 * 
 * @param Priodicity The periodicity of the task.
 * @param pFunction Pointer to the task function.
 * @param FristDelay The initial delay before the task starts.
 * @return eTaskStatus_t Returns TASK_SUCCESS if the task is created successfully, otherwise TASK_FAILED.
 */
eTaskStatus_t OS_voidCreatTask(uint32_t Priodicity, void (*pFunction)(void),
		uint32_t FristDelay)
{
	static uint8_t Piorirty = 0;
	eTaskStatus_t state = TASK_SUCCESS;
	/* Check that there is no task with the same piorirty */
	if ((OS_Tasks[Piorirty].pFunction == 0) && (Piorirty < MAX_TASKS_NUMBER))
	{
		OS_Tasks[Piorirty].Period = Priodicity;
		OS_Tasks[Piorirty].pFunction = pFunction;
		OS_Tasks[Piorirty].State = Task_Ready; /* Put the sTask_t in init eTaskState_t */
		OS_Tasks[Piorirty].FristDelay = FristDelay;
		Piorirty++;
	}
	else
	{
		state = TASK_FAILED;
	}
	return state;
}

/*
 * @brief Starts the OS by enabling global interrupts.
 * 
 * This function is intended to enable global interrupts, allowing the OS to start scheduling tasks.
 */
void OS_voidStart(void)
{
	/* Enable Global Interrupt */
}

/*
 * @brief The OS scheduler that manages task execution.
 * 
 * This function is called periodically to check and execute tasks that are ready to run.
 */
void OS_Scheduler(void)
{
	for (uint8_t i = 0; i < MAX_TASKS_NUMBER; i++)
	{ /* Loop to select the function to run*/

		if ((OS_Tasks[i].pFunction != NULL)
				&& (OS_Tasks[i].State == Task_Ready))
		{ /* Check if it exist */

			if (OS_Tasks[i].FristDelay == 0)
			{

				OS_Tasks[i].FristDelay = OS_Tasks[i].Period - 1;
				OS_Tasks[i].RunMe++;
				OS_Tasks[i].pFunction();
			}
			else
			{
				OS_Tasks[i].FristDelay--;
			}
		}

	}
	g_CurrentTick++;
}

/*
 * @brief Pauses a specific task.
 * 
 * @param pFunction Pointer to the task function to be paused.
 */
void OS_voidPuseTask(void (*pFunction)(void))
{

	for (uint8_t i = 0; i < MAX_TASKS_NUMBER; i++)
	{ /* Loop to select the function to run*/

		if (OS_Tasks[i].pFunction == pFunction)
		{
			OS_Tasks[i].State = Task_Puse;

		}
	}
}

/*
 * @brief Resumes a specific paused task.
 * 
 * @param pFunction Pointer to the task function to be resumed.
 */
void OS_voidResumeTask(void (*pFunction)(void))
{
	for (uint8_t i = 0; i < MAX_TASKS_NUMBER; i++)
	{ /* Loop to select the function to run*/

		if (OS_Tasks[i].pFunction == pFunction)
		{
			OS_Tasks[i].State = Task_Ready;

		}
	}
}

/*
 * @brief Kills a specific task.
 * 
 * @param pFunction Pointer to the task function to be killed.
 */
void OS_voidKillTask(void (*pFunction)(void))
{
	for (uint8_t i = 0; i < MAX_TASKS_NUMBER; i++)
	{ /* Loop to select the function to run*/

		if (OS_Tasks[i].pFunction == pFunction)
		{
			OS_Tasks[i].State = (eTaskState_t) NULL;

		}
	}

}

/*
 * @brief Gets the number of times a specific task has been executed.
 * 
 * @param pFunction Pointer to the task function.
 * @return uint32_t The number of times the task has been executed.
 */
uint32_t OS_voidGetExcutionNumbers(void (*pFunction)(void))
{
	for (uint8_t i = 0; i < MAX_TASKS_NUMBER; i++)
	{ /* Loop to select the function to run*/

		if (OS_Tasks[i].pFunction == pFunction)
		{
			return OS_Tasks[i].RunMe;

		}
	}
	return 0;
}

/*
 * @brief Gets the current tick count of the OS.
 * 
 * @return uint32_t The current tick count.
 */
uint32_t OS_GetCurrentTick(void)
{
	return g_CurrentTick;
}

/*************** END OF FUNCTIONS *********************************************/
