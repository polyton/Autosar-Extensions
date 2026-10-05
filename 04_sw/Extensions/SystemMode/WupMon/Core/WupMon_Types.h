/*
 * WupMon_Types.h
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#include "Std_Types.h"
#include "Std_Macros.h"
#include "Autosar_Defines.h"

/** Type definitions */
typedef enum {
	WUPMON_UNINIT_STATE = 0,
	WUPMON_IDLE_STATE,
	WUPMON_ANALYZE_STATE,
	WUPMON_MONITOR_STATE,
	WUPMON_NO_STATES
} WupMon_TEStateMachine;
