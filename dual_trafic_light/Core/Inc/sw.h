/******************************************************************************
 * @file        sw.h
 * @author      Eslam Shahin
 * @date        2025-01-04
 * @brief       Switch task APIs
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/
#ifndef SW_H
#define SW_H

/******************************** Includes ************************************/


/******************************* Macros and Enums *****************************/
#define SW_UPDATE_PERIOD 			(20)
#define SW_MIN_SAMPLE_TIME_MS       (100)

typedef enum
{
	SW_NOT_PRESSED,
	SW_PRESSED,

}sw_state_t;

typedef enum
{
	SW_PEDESTRIAN,
	SW_MAX_NUM_
}sw_name_t;

/********************************** Structs ***********************************/

typedef struct
{
	sw_name_t Name;
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	GPIO_PinState PressedLogic;
	sw_state_t State;
}sw_t;

/***************************** Global Variables *******************************/

extern sw_t g_sw[SW_MAX_NUM_];
/************************** Static Global Variables ***************************/


/****************************** Init Functions ********************************/

/**
 * @brief Initializes the switch module.
 * 
 * This function is intended to initialize the GPIO pins for the switches.
 */
void SW_Init(void);

/****************************** Update Functions ******************************/

/**
 * @brief Updates the state of all switches.
 * 
 * This function monitors the state of each switch and updates its status.
 */
void SW_Update(void);

/****************************** Setter Functions ******************************/


/****************************** Getter Functions ******************************/

/**
 * @brief Gets the current state of a specific switch.
 * 
 * @param name The name of the switch to check.
 * @return sw_state_t The current state of the switch (PRESSED or NOT_PRESSED).
 */
sw_state_t SW_GetState(sw_name_t name );

#endif // NS_ROAD_H
