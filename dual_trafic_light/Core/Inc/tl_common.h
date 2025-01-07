/******************************************************************************
 * @file        tl_common.h
 * @author      Eslam Shahin
 * @date        2025-01-03
 * @brief       Configuration and state machines
 * @details     Detailed description of the file, including its role in the
 *              system, key features, and usage guidelines.
 ******************************************************************************/
#ifndef TL_H
#define TL_H

#include "my_types.h"
/******************************** Includes ************************************/


/******************************* Macros and Enums *****************************/

/**< Time for each colour in seconds */
#define TLC_NS_RED_TIME_S 			(22)
#define TLC_NS_RED_YELLOW_TIME_S 	(2)
#define TLC_NS_GREEN_TIME_S 		(14)
#define TLC_NS_YELLOW_TIME_S 		(2)


/**< Time for each colour in seconds */
#define TLC_EW_RED_YELLOW_TIME_S 	(2)
#define TLC_EW_GREEN_TIME_S 		(18)
#define TLC_EW_YELLOW_TIME_S 		(2)
#define TLC_EW_RED_TIME_S 			(18)

/**< Time for pedestrian in seconds */
#define TLC_PEDESTRIAN_TIME_S 	(20)
/**<  State machine for the trafic light system */
typedef enum
{
	TL_RED,
	TL_YELLOW,
	TL_RED_YELLOW,
	TL_GREEN,
	TL_PEDESTRIAN,
	TL_MAX_STATE
}tl_states_t;

/********************************** Structs ***********************************/


/***************************** Global Variables *******************************/
#define OS_TICK_TIME_MS 20

/************************** Static Global Variables ***************************/


/****************************** Init Functions ********************************/


/****************************** Update Functions ******************************/


/****************************** Setter Functions ******************************/


/****************************** Getter Functions ******************************/

#endif // TL
