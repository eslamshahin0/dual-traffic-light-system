/******************************************************************************
 * @file        sw.c
 * @author      Eslam Shahin
 * @date        2025-01-04
 * @brief       Switch task
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/

/******************************** Includes ************************************/
/* Default libs */
#include "my_types.h"
/* Lower Layer */
#include "mcu.h"
/* Module */
#include "sw.h"
/******************************* Macros and Enums *****************************/

/********************************** Structs ***********************************/

/***************************** Global Variables *******************************/
sw_t g_sw[SW_MAX_NUM_];
/************************** Static Global Variables ***************************/
static uint16_t g_sw_time[SW_MAX_NUM_];

/************************** Static Function Prototypes ************************/
static void sw_monitor(sw_name_t name);


/****************************** Init Functions ********************************/

/*
 * @brief Initializes the switch module.
 * 
 * This function is intended to initialize the GPIO pins for the switches.
 */
void SW_Init(void)
{
	/* Init gpio (NA as done in the MX )*/

}

/****************************** Update Functions ******************************/

/*
 * @brief Updates the state of all switches.
 * 
 * This function monitors the state of each switch and updates its status.
 */
void SW_Update(void)
{
	for(sw_name_t i = 0 ;i< SW_MAX_NUM_;i++)
	{
		sw_monitor(i);
	}
}

/****************************** Setter Functions ******************************/

/****************************** Getter Functions ******************************/

/*
 * @brief Gets the current state of a specific switch.
 * 
 * @param name The name of the switch to check.
 * @return sw_state_t The current state of the switch (PRESSED or NOT_PRESSED).
 */
sw_state_t SW_GetState(sw_name_t name )
{
	return g_sw[name].State;
}

/************************** Static Function Implementation ********************/

/**
 * @brief Monitors the state of a specific switch.
 * 
 * This function checks if a switch is pressed and updates its state accordingly.
 * 
 * @param name The name of the switch to monitor.
 */
static void sw_monitor(sw_name_t name)
{
	GPIO_PinState state = HAL_GPIO_ReadPin(g_sw[name].GPIOx, g_sw[name].GPIO_Pin);
	if (state != g_sw[name].PressedLogic)
	{
		g_sw[name].State = SW_NOT_PRESSED;
		g_sw_time[name] = 0;
		return ;
	}
	g_sw_time[name]++;

	if ((g_sw_time[name]*SW_UPDATE_PERIOD) >=SW_MIN_SAMPLE_TIME_MS){
		g_sw[name].State = SW_PRESSED;
	}
}
