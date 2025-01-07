/**
 * ***************************************************************
 *  @file      my_types.h
 *  @author    Eslam Shahin (eslamshahin552000@gmail.com)                          
 *  @version   v1.0                                            
 *  @date      8 Aug 2020, 19:37		                                   
 *  @brief     This file used to avoid the size change of the 
 *             variables in different compilers and arch	                                 
 *
 *  @attention This program is distributed in the hope  that it  
 * 	           will be useful,but WITHOUT ANY WARRANTY; without     
 *	           even the implied warranty of  MERCHANTABILITY or     
 *	           FITNESS FOR A PARTICULAR PURPOSE.  
 *                                                      
 * ***************************************************************                                                                
 */
#ifndef _STD_TYPES_
#define _STD_TYPES_

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char			BOOL;

/*!< @def NULLPTR  this typedef is null pointer  */
#define NULLPTR ((void*)0)               
#endif
