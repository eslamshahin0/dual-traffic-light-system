/**
 * ***************************************************************
 *  @file      OS_interface.h			
 *  @author    Eslam Shahin (eslamshahin552000@gmail.com)                          
 *  @version   v1.0                                            
 *  @date      10/09/2020		                                   
 *  @brief     [Write a brief of this file ]
 *                          	                                 
 *
 *  @note      This program is distributed in the hope  that it  
 * 	           will be useful,but WITHOUT ANY WARRANTY; without     
 *	           even the implied warranty of  MERCHANTABILITY or     
 *	           FITNESS FOR A PARTICULAR PURPOSE.  
 *                                                      
 * ***************************************************************                                                                
 */
 
#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define OS_TICK_PERIOD_MS        (20)
/*
Select the Maxmum number of tasks ,
note each task has a unicke id and it is equal to its priority
	*/
#define MAX_TASKS_NUMBER        5
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef  enum {
	Task_Ready,
	Task_Puse,
	Task_Resume
}eTaskState_t;

typedef  enum {
	TASK_FAILED,
	TASK_SUCCESS
}eTaskStatus_t;

typedef struct {

	uint32_t Period;						/* Time that task will be excuted  */
	void (*pFunction)(void);		/* Pointer to Function  */
	uint32_t FristDelay;				/* Ticks to wait after the schaduler run the task */
	eTaskState_t State;  /* Task state  */
	uint32_t RunMe;            		/* Incremented when task is due to execute*/
}sTask_t;
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Initializes the OS and configures the SysTick timer.
 * 
 * This function sets up the SysTick timer based on the system clock and the desired tick period.
 */
void OS_voidInit(void);

/**
 * @brief Starts the OS by enabling global interrupts.
 * 
 * This function is intended to enable global interrupts, allowing the OS to start scheduling tasks.
 */
void OS_voidStart(void);

/**
 * @brief Creates a new task with the specified periodicity, function, and initial delay.
 * 
 * @param Priodicity The periodicity of the task.
 * @param pFunction Pointer to the task function.
 * @param FristDelay The initial delay before the task starts.
 * @return eTaskStatus_t Returns TASK_SUCCESS if the task is created successfully, otherwise TASK_FAILED.
 */
 eTaskStatus_t OS_voidCreatTask( uint32_t Priodicity ,void(*pFunction)(void),uint32_t FristDelay);

/**
 * @brief The OS scheduler that manages task execution.
 * 
 * This function is called periodically to check and execute tasks that are ready to run.
 */
void OS_Scheduler(void);

/**
 * @brief Resumes a specific paused task.
 * 
 * @param pFunction Pointer to the task function to be resumed.
 */
void OS_voidResumeTaskvoid( void(*pFunction)(void));

/**
 * @brief Kills a specific task.
 * 
 * @param pFunction Pointer to the task function to be killed.
 */
void OS_voidKillTaskvoid( void(*pFunction)(void));

/**
 * @brief Pauses a specific task.
 * 
 * @param pFunction Pointer to the task function to be paused.
 */
void OS_voidPuseTaskvoid( void(*pFunction)(void));

/**
 * @brief Gets the number of times a specific task has been executed.
 * 
 * @param pFunction Pointer to the task function.
 * @return uint32_t The number of times the task has been executed.
 */
uint32_t  OS_voidGetExcutionNumbersvoid( void(*pFunction)(void));

/**
 * @brief Gets the current tick count of the OS.
 * 
 * @return uint32_t The current tick count.
 */
uint32_t OS_GetCurrentTick(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*File_H_*/

/*** End of File **************************************************************/
