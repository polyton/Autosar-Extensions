/*
 * SleepCtrl.h
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSSERV_SLEEPCTRL_CORE_SLEEPCTRL_H_
#define SYSSERV_SLEEPCTRL_CORE_SLEEPCTRL_H_

#include "SleepCtrl_Types.h"
#include "SleepCtrl_ManCfg.h"

/**
 *
 */
void SleepCtrl_Init(void);

/**
 *
 */
void SleepCtrl_MainFunction(void);

/**
 *
 */
Std_ReturnType SleepCtrl_SetSleepState(SleepCtrl_TESleepStateMachine state);

#if (ECUM_FIXED_BEHAVIOR == STD_ON)
/**
 *
 */
void SleepCtrl_GoToSleep(void);
#endif

#endif /* SYSSERV_SLEEPCTRL_CORE_SLEEPCTRL_H_ */
