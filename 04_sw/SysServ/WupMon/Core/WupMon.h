/*
 * WupMon.h
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSSERV_WUPMON_CORE_WUPMON_H_
#define SYSSERV_WUPMON_CORE_WUPMON_H_

#include "WupMon_Types.h"
#include "WupMon_ManCfg.h"

/**
 *
 */
void WupMon_Init(void);

/**
 *
 */
void WupMon_MainFunction(void);

/**
 *
 */
void WupMon_AnalyzeWupRsn(void);

/**
 *
 */
Std_ReturnType WupMon_GetWupRsn(uint32 *wupRsn);

/**
 *
 */
Std_ReturnType WupMon_SetWupState(WupMon_TEStateMachine state);

/**
 *
 */
void WupMon_SetPlayPrtc(uint32 cfg);

#endif /* SYSSERV_WUPMON_CORE_WUPMON_H_ */
