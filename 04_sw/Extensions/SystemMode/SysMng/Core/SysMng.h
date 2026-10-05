/*
 * SysMng.h
 *
 *  Created on: 17.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSSERV_SYSMNG_CORE_SYSMNG_H_
#define SYSSERV_SYSMNG_CORE_SYSMNG_H_

#include "SysMng_Types.h"
#include "SysMng_ManCfg.h"

/**
 *
 */
void SysMng_Init(void);

/**
 *
 */
void SysMng_MainFunction(void);

/**
 *
 */
Std_ReturnType SysMng_GetSysState(SysMng_TESysStateMachine *state);

/**
 *
 */
Std_ReturnType SysMng_SetSysState(SysMng_TESysStateMachine state);

/**
 *
 */
Std_ReturnType SysMng_GetActiveComUsr(uint32 *comUsr);

/**
 *
 */
Std_ReturnType SysMng_GetActiveEcuUsr(uint32 *ecuUsr);

/**
 *
 */
Std_ReturnType SysMng_ComRunRq(uint32 user);

/**
 *
 */
Std_ReturnType SysMng_ComReleaseRq(uint32 user);

/**
 *
 */
Std_ReturnType SysMng_EcuRunRq(uint32 user);

/**
 *
 */
Std_ReturnType SysMng_EcuReleaseRq(uint32 user);

#endif /* SYSSERV_SYSMNG_CORE_SYSMNG_H_ */
