/******************************************************************************
 * @file        ew_road.c
 * @author      Eslam Shahin
 * @date        2025-01-03
 * @brief       ew road task
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/

/******************************** Includes ************************************/
/* Default libs */
#include "my_types.h"
/* Lower Layer */
#include "mcu.h"
/* Module */
#include "tl_common.h"
#include "pedestrian.h"
#include "ns_road.h"
#include "os.h"
#include "ew_road.h"
/******************************* Macros and Enums *****************************/

/********************************** Structs ***********************************/

/***************************** Global Variables *******************************/
extern UART_HandleTypeDef huart1;
/************************** Static Global Variables ***************************/

static tl_states_t g_ew_state;

/************************** Static Function Prototypes ************************/

/****************************** Init Functions ********************************/

/*
 * @brief Initializes the East-West road traffic light.
 * 
 * This function sets the initial state of the East-West road traffic light to red.
 */
void EW_ROAD_Init(void)
{
	/* Init gpio (NA as done in the MX )*/
	g_ew_state = TL_RED;

}

/****************************** Update Functions ******************************/

/*
 * @brief Updates the state of the East-West road traffic light.
 * 
 * This function handles the state transitions of the traffic light based on the current state and time elapsed.
 */
void EW_ROAD_Update(void)
{
	static uint32_t ColorStartTime = 0;
	static uint32_t redColorStartTime ;

	switch (g_ew_state)
	{
	case TL_RED:
	{
		/* to sync with the NS road */
		if (TRUE == NS_ROAD_IsPedestrianActive())
		{
			g_ew_state = TL_PEDESTRIAN;
			redColorStartTime = ColorStartTime;
			ColorStartTime = OS_GetCurrentTick();
		}
		/* Turn on red led */
		HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_EW_RED_TIME_S * 1000)
		{
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, GPIO_PIN_RESET);
			g_ew_state = TL_RED_YELLOW;
			ColorStartTime = OS_GetCurrentTick();
		}

	}
		break;
	case TL_YELLOW:
	{
		/* Turn on yellow led */
		HAL_GPIO_WritePin(EW_YELLOW_GPIO_Port, EW_YELLOW_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_EW_YELLOW_TIME_S * 1000)
		{
			/* Turn off yellow and move to red state */
			HAL_GPIO_WritePin(EW_YELLOW_GPIO_Port, EW_YELLOW_Pin,
					GPIO_PIN_RESET);

			g_ew_state = TL_RED;
			/* save new colour start time */
			ColorStartTime = OS_GetCurrentTick();

		}
	}
		break;
	case TL_RED_YELLOW:
	{
		/* Turn on red and yellow leds */
		HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EW_YELLOW_GPIO_Port, EW_YELLOW_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_EW_RED_YELLOW_TIME_S * 1000)
		{
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EW_YELLOW_GPIO_Port, EW_YELLOW_Pin, GPIO_PIN_RESET);
			g_ew_state = TL_GREEN;
			ColorStartTime = OS_GetCurrentTick();
		}
	}
		break;
	case TL_GREEN:
	{
		/* Turn on green led */
		HAL_GPIO_WritePin(EW_GREEN_GPIO_Port, EW_GREEN_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_EW_GREEN_TIME_S * 1000)
		{
			/* Turn off green and move to yellow state */
			HAL_GPIO_WritePin(EW_GREEN_GPIO_Port, EW_GREEN_Pin, GPIO_PIN_RESET);
			g_ew_state = TL_YELLOW;

			/* save new colour start time */
			ColorStartTime = OS_GetCurrentTick();
		}
	}
		break;
	case TL_PEDESTRIAN:
	{
		/* Turn on red led */
		HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_PEDESTRIAN_TIME_S * 1000)
		{
			g_ew_state = TL_RED;
			ColorStartTime = redColorStartTime + (TLC_PEDESTRIAN_TIME_S * 1000/OS_TICK_TIME_MS);
		}

	}
		break;
	default:
		break;
	}
}

/****************************** Setter Functions ******************************/

/****************************** Getter Functions ******************************/

/************************** Static Function Implementation ********************/
