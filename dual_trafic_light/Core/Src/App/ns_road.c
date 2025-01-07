/******************************************************************************
 * @file        ns_road.c
 * @author      Eslam Shahin
 * @date        2025-01-03
 * @brief       ns road task
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
#include "os.h"
#include "pedestrian.h"
#include "ns_road.h"
/******************************* Macros and Enums *****************************/

/********************************** Structs ***********************************/

/***************************** Global Variables *******************************/
extern UART_HandleTypeDef huart1;
/************************** Static Global Variables ***************************/

static tl_states_t g_ns_state;

/************************** Static Function Prototypes ************************/

/****************************** Init Functions ********************************/

/*
 * @brief Initializes the North-South road traffic light.
 * 
 * This function sets the initial state of the North-South road traffic light to green.
 */
void NS_ROAD_Init(void)
{
	/* Init gpio (NA as done in the MX )*/
	g_ns_state = TL_RED_YELLOW;

}

/****************************** Update Functions ******************************/

/*
 * @brief Updates the state of the North-South road traffic light.
 * 
 * This function handles the state transitions of the traffic light based on the current state and time elapsed.
 */
void NS_ROAD_Update(void)
{
	static uint32_t ColorStartTime = 0;

	switch (g_ns_state)
	{
	case TL_RED:
	{
		/* Turn on red led */
		HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_NS_RED_TIME_S * 1000)
		{
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, GPIO_PIN_RESET);
			g_ns_state = TL_RED_YELLOW;
			ColorStartTime = OS_GetCurrentTick();
		}
	}
		break;
	case TL_YELLOW:
	{
		/* Turn on yellow led */
		HAL_GPIO_WritePin(NS_YELLOW_GPIO_Port, NS_YELLOW_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_NS_YELLOW_TIME_S * 1000)
		{
			/* Turn off yellow and move to red state */
			HAL_GPIO_WritePin(NS_YELLOW_GPIO_Port, NS_YELLOW_Pin,
					GPIO_PIN_RESET);

			if (TRUE == PEDESTRIAN_GetRequest())
			{
				g_ns_state = TL_PEDESTRIAN;
			}
			else
			{
				g_ns_state = TL_RED;
			}
			/* save new colour start time */
			ColorStartTime = OS_GetCurrentTick();

		}
	}
		break;
	case TL_RED_YELLOW:
	{
		/* Turn on red and yellow leds */
		HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(NS_YELLOW_GPIO_Port, NS_YELLOW_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_NS_RED_YELLOW_TIME_S * 1000)
		{
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(NS_YELLOW_GPIO_Port, NS_YELLOW_Pin, GPIO_PIN_RESET);
			g_ns_state = TL_GREEN;
			ColorStartTime = OS_GetCurrentTick();
		}
	}
		break;
	case TL_GREEN:
	{
		/* Turn on green led */
		HAL_GPIO_WritePin(NS_GREEN_GPIO_Port, NS_GREEN_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_NS_GREEN_TIME_S * 1000)
		{
			/* Turn off green and move to yellow state */
			HAL_GPIO_WritePin(NS_GREEN_GPIO_Port, NS_GREEN_Pin, GPIO_PIN_RESET);
			g_ns_state = TL_YELLOW;

			/* save new colour start time */
			ColorStartTime = OS_GetCurrentTick();
		}
	}
		break;
	case TL_PEDESTRIAN:
	{
		/* Turn on red led */
		HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, GPIO_PIN_SET);
		if ((uint32_t)((OS_GetCurrentTick() - ColorStartTime ) * OS_TICK_TIME_MS)
				>= TLC_PEDESTRIAN_TIME_S * 1000)
		{
			g_ns_state = TL_RED;
			ColorStartTime = OS_GetCurrentTick();
			PEDESTRIAN_ClearRequest();
		}

	}
		break;
	default:
		break;
	}
}

/****************************** Setter Functions ******************************/

/****************************** Getter Functions ******************************/

/*
 * @brief Checks if the pedestrian mode is active on the North-South road.
 * 
 * @return BOOL Returns TRUE if the pedestrian mode is active, otherwise FALSE.
 */
BOOL NS_ROAD_IsPedestrianActive(void)
{
	return (TL_PEDESTRIAN == g_ns_state);
}
/************************** Static Function Implementation ********************/
