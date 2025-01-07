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
#include "sw.h"
#include "ns_road.h"
#include "pedestrian.h"
/******************************* Macros and Enums *****************************/

/********************************** Structs ***********************************/

/***************************** Global Variables *******************************/
extern UART_HandleTypeDef huart1;

/************************** Static Global Variables ***************************/
static sw_name_t pedestrianBtn = SW_PEDESTRIAN;
static BOOL pedestrianReq = FALSE;

/************************** Static Function Prototypes ************************/

/****************************** Init Functions ********************************/

/*
 * @brief Initializes the pedestrian traffic light and button.
 * 
 * This function sets up the GPIO pins for the pedestrian button and traffic light.
 */
void PEDESTRIAN_Init(void)
{

	g_sw[pedestrianBtn].GPIOx = PEDESTRIAN_BUTTON_GPIO_Port;
	g_sw[pedestrianBtn].GPIO_Pin = PEDESTRIAN_BUTTON_Pin;
	g_sw[pedestrianBtn].PressedLogic = GPIO_PIN_SET;
	g_sw[pedestrianBtn].Name = pedestrianBtn;

}

/****************************** Update Functions ******************************/

/*
 * @brief Updates the state of the pedestrian traffic light.
 * 
 * This function checks the pedestrian button state and updates the pedestrian traffic light accordingly.
 */
void PEDESTRIAN_Update(void)
{

	if (SW_PRESSED == SW_GetState(pedestrianBtn))
	{
		pedestrianReq = TRUE;
	}

	if (TRUE == NS_ROAD_IsPedestrianActive())
	{
		/* Turn on green Pedestrian led */
		HAL_GPIO_WritePin(PEDESTRIAN_GREEN_GPIO_Port, PEDESTRIAN_GREEN_Pin,
				GPIO_PIN_SET);
		HAL_GPIO_WritePin(PEDESTRIAN_RED_GPIO_Port, PEDESTRIAN_RED_Pin,
				GPIO_PIN_RESET);
	}
	else
	{
		/* Turn on red Pedestrian led */
		HAL_GPIO_WritePin(PEDESTRIAN_RED_GPIO_Port, PEDESTRIAN_RED_Pin,
				GPIO_PIN_SET);
		HAL_GPIO_WritePin(PEDESTRIAN_GREEN_GPIO_Port, PEDESTRIAN_GREEN_Pin,
				GPIO_PIN_RESET);

	}
}

/****************************** Setter Functions ******************************/


/****************************** Getter Functions ******************************/

/*
 * @brief Gets the pedestrian request status.
 * 
 * @return BOOL Returns TRUE if a pedestrian request is active, otherwise FALSE.
 */
 BOOL PEDESTRIAN_GetRequest(void)
{
	return pedestrianReq;
}


 /*
  * @brief clear the pedestrian request status.
  */
void PEDESTRIAN_ClearRequest(void)
 {
 	pedestrianReq = FALSE;
 }
/************************** Static Function Implementation ********************/
