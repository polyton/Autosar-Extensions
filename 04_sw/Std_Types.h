/*
 * Std_Types.h
 *
 *  Created on: 17.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Global datatypes */
typedef signed char 			sint8;
typedef unsigned char 			uint8;

typedef unsigned short 		uint16;
typedef signed short 			sint16;

typedef unsigned long 			uint32;
typedef signed long				sint32;

typedef unsigned long long		uint64;
typedef signed long long    sint64;

/** Return type */
typedef uint8 					Std_ReturnType;
typedef uint8 					boolean;

/** Definition of states */
#define E_OK					0u
#define E_NOT_OK			1u
#define E_BUSY				2u

#define STD_OFF			0u
#define STD_ON      		1u

#define FALSE					0u
#define TRUE					1u

#define NULL_PTR			((void*)0)

#endif /* STD_TYPES_H_ */
