/******************************************************************************
 * @file        pedestrian.h
 * @author      Eslam Shahin
 * @date        2025-01-04
 * @brief       pedestrian task APIs
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

/******************************** Includes ************************************/

#include "my_types.h"

/******************************* Macros and Enums *****************************/


/********************************** Structs ***********************************/


/***************************** Global Variables *******************************/


/************************** Static Global Variables ***************************/


/****************************** Init Functions ********************************/

/**
 * @brief Initializes the pedestrian traffic light and button.
 * 
 * This function sets up the GPIO pins for the pedestrian button and traffic light.
 */
void PEDESTRIAN_Init(void);

/****************************** Update Functions ******************************/

/**
 * @brief Updates the state of the pedestrian traffic light.
 * 
 * This function checks the pedestrian button state and updates the pedestrian traffic light accordingly.
 */
void PEDESTRIAN_Update(void);

/****************************** Setter Functions ******************************/

/*
 * @brief clear the pedestrian request status.
 */
void PEDESTRIAN_ClearRequest(void);

/****************************** Getter Functions ******************************/

/**
 * @brief Gets the pedestrian request status.
 * 
 * @return BOOL Returns TRUE if a pedestrian request is active, otherwise FALSE.
 */
BOOL PEDESTRIAN_GetRequest(void);

#endif // PEDESTRIAN_H
