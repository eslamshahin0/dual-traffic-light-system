/******************************************************************************
 * @file        ew_road.h
 * @author      Eslam Shahin
 * @date        2025-01-03
 * @brief       ew road task APIs
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/
#ifndef EW_ROAD_H
#define EW_ROAD_H

/******************************** Includes ************************************/


/******************************* Macros and Enums *****************************/


/********************************** Structs ***********************************/


/***************************** Global Variables *******************************/


/************************** Static Global Variables ***************************/


/****************************** Init Functions ********************************/

/**
 * @brief Initializes the East-West road traffic light.
 * 
 * This function sets the initial state of the East-West road traffic light to red.
 */
void EW_ROAD_Init(void);

/****************************** Update Functions ******************************/

/**
 * @brief Updates the state of the East-West road traffic light.
 * 
 * This function handles the state transitions of the traffic light based on the current state and time elapsed.
 */
void EW_ROAD_Update(void);

/****************************** Setter Functions ******************************/


/****************************** Getter Functions ******************************/

#endif // EW_ROAD_H
