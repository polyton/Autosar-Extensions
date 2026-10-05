/*
 * SleepCtrl.c
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#include "SleepCtrl.h"

#include "SbcDrv.h"

/** Defines */

/** Type definitions */

/** Local variables */
static SleepCtrl_TESleepStateMachine SleepCtrl_StateMachine = SLEEPCTRL_UNINIT_STATE;

/** Local functions */
static void SleepCtrl_ShutdownHw(void);
static void SleepCtrl_PerformSafeSleep(void);
static void SleepCtrl_PerformSleep(void);

/** Public function definitions */

/**
 *
 */
void SleepCtrl_Init(void)
{
	(void)SleepCtrl_SetSleepState(SLEEPCTRL_IDLE);
}

/**
 *
 */
void SleepCtrl_MainFunction(void)
{
	switch (SleepCtrl_StateMachine) {
		case SLEEPCTRL_IDLE:
			break;

		case SLEEPCTRL_WDG_TEST:
			/* ToDo: WdgMng_PerformTest(); */
			break;

		case SLEEPCTRL_GOTO_SLEEP:
			SleepCtrl_PerformSafeSleep();
			break;

		default:
			break;
	}
}

#if (ECUM_FIXED_BEHAVIOR == STD_ON)
/**
 *
 */
void SleepCtrl_GoToSleep(void)
{

}
#endif

/**
 *
 */
Std_ReturnType SleepCtrl_SetSleepState(SleepCtrl_TESleepStateMachine state)
{
	Std_ReturnType result = E_NOT_OK;

	if (SLEEPCTRL_NO_STATES > state) {
		SleepCtrl_StateMachine = state;
		result = E_OK;
	}

	return result;
}

/** Private function */

/**
 *
 */
static void SleepCtrl_PerformSafeSleep(void)
{
	SleepCtrl_ShutdownHw();
	SleepCtrl_PerformSleep();
}

/**
 *
 */
static void SleepCtrl_PerformSleep(void)
{
	if (E_OK == SbcDrv_GoToSleep()) {

	}
}

/**
 *
 */
static void SleepCtrl_ShutdownHw(void)
{

}
