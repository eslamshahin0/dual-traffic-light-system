/******************************************************************************
 * @file        ns_road.h
 * @author      Eslam Shahin
 * @date        2025-01-03
 * @brief       ns road task APIs
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/
#ifndef NS_ROAD_H
#define NS_ROAD_H

/******************************** Includes ************************************/

#include "my_types.h"
/******************************* Macros and Enums *****************************/


/********************************** Structs ***********************************/


/***************************** Global Variables *******************************/


/************************** Static Global Variables ***************************/


/****************************** Init Functions ********************************/

/**
 * @brief Initializes the North-South road traffic light.
 * 
 * This function sets the initial state of the North-South road traffic light to green.
 */
void NS_ROAD_Init(void);

/****************************** Update Functions ******************************/

/**
 * @brief Updates the state of the North-South road traffic light.
 * 
 * This function handles the state transitions of the traffic light based on the current state and time elapsed.
 */
void NS_ROAD_Update(void);

/****************************** Setter Functions ******************************/


/****************************** Getter Functions ******************************/

/**
 * @brief Checks if the pedestrian mode is active on the North-South road.
 * 
 * @return BOOL Returns TRUE if the pedestrian mode is active, otherwise FALSE.
 */
BOOL NS_ROAD_IsPedestrianActive(void);

#endif // NS_ROAD_H
