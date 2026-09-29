/*
 * Std_Macros.h
 *
 *  Created on: 22.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define BIT_SET(value, bit)				((value) |= (1ULL<<(bit)))
#define BIT_CLR(value, bit)				((value) &= ~(1ULL<<(bit)))
#define BIT_GET(value, bit)				(((value) >> (bit)) & 1ULL)

#endif /* STD_MACROS_H_ */
