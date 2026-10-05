/*
 * SleepCtrl_Types.h
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSSERV_SLEEPCTRL_CORE_SLEEPCTRL_TYPES_H_
#define SYSSERV_SLEEPCTRL_CORE_SLEEPCTRL_TYPES_H_

#include "Std_Types.h"
#include "Std_Macros.h"
#include "Autosar_Defines.h"

typedef enum {
	SLEEPCTRL_UNINIT_STATE = 0,
	SLEEPCTRL_IDLE,
	SLEEPCTRL_WDG_TEST,
	SLEEPCTRL_GOTO_SLEEP,
	SLEEPCTRL_NO_STATES
} SleepCtrl_TESleepStateMachine;

#endif /* SYSSERV_SLEEPCTRL_CORE_SLEEPCTRL_TYPES_H_ */
