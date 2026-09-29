/*
 * SysMng_Types.h
 *
 *  Created on: 17.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSSERV_SYSMNG_CORE_SYSMNG_TYPES_H_
#define SYSSERV_SYSMNG_CORE_SYSMNG_TYPES_H_

#include "Std_Types.h"
#include "Std_Macros.h"
#include "Autosar_Defines.h"

typedef enum {
	SYSMNG_UNINIT_STATE = 0,
	SYSMNG_RUN_ECU_STATE,
	SYSMNG_STARTUP_STATE,
	SYSMNG_RUN_COM_STATE,
	SYSMNG_AFTER_RUN_STATE,
	SYSMNG_RDY_SLEEP,
	SYSMNG_NO_STATES
} SysMng_TESysStateMachine;

#endif /* SYSSERV_SYSMNG_CORE_SYSMNG_TYPES_H_ */
