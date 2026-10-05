/*
 * WupMon.c
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#include "WupMon.h"

#include "SbcDrv.h"

/** Defines */

/** Type definitions */
typedef struct {
	uint32 wupRsn;
	Std_ReturnType wupRsnStatus;
} WupMon_TSWupRsnType;

/** Local variables */
static WupMon_TEStateMachine WupMon_StateMachine = WUPMON_UNINIT_STATE;
static WupMon_TSWupRsnType WupMon_Reason;

/** Local functions */
static void WupMon_ProcessRsn(void);

/** Public function definitions */

/**
 *
 */
void WupMon_Init(void)
{
	WupMon_SetWupState(WUPMON_IDLE_STATE);
}

/**
 *
 */
void WupMon_MainFunction(void)
{
	WupMon_ProcessRsn();
}

/**
 *
 */
void WupMon_AnalyzeWupRsn(void)
{
	uint32 wupRsn;

	if (E_OK == SbcDrv_GetWupRsn(&wupRsn)) {
		switch (wupRsn) {
			case SBCDRV_CAN_WUP_REASON:
				WupMon_Reason.wupRsnStatus = E_OK;
#if 0
				WupMon_Reason.wupRsn = ECUM_WKSOURCE_EcuMWakeupSource_CAN;
				EcuM_SetWakeupEvent(ECUM_WKSOURCE_EcuMWakeupSource_CAN);
#endif
				break;

			case SBCDRV_KL15_WUP_REASON:
				WupMon_Reason.wupRsnStatus = E_OK;
#if 0
				WupMon_Reason.wupRsn = ECUM_WKSOURCE_EcuMWakeupSource_KL15;
				EcuM_SetWakeupEvent(ECUM_WKSOURCE_EcuMWakeupSource_KL15);
#endif
				break;

			case SBCDRV_BTN_WUP_REASON:
				WupMon_Reason.wupRsnStatus = E_OK;
#if 0
				WupMon_Reason.wupRsn = ECUM_WKSOURCE_EcuMWakeupSource_BTN;
				EcuM_SetWakeupEvent(ECUM_WKSOURCE_EcuMWakeupSource_BTN);
#endif
				break;

			case SBCDRV_CP_WUP_REASON:
				WupMon_Reason.wupRsnStatus = E_OK;
#if 0
				WupMon_Reason.wupRsn = ECUM_WKSOURCE_EcuMWakeupSource_CP;
				EcuM_SetWakeupEvent(ECUM_WKSOURCE_EcuMWakeupSource_CP);
#endif
				break;

			case SBCDRV_PRX_WUP_REASON:
				WupMon_Reason.wupRsnStatus = E_OK;
#if 0
				WupMon_Reason.wupRsn = ECUM_WKSOURCE_EcuMWakeupSource_PRX;
				EcuM_SetWakeupEvent(ECUM_WKSOURCE_EcuMWakeupSource_PRX);
#endif
				break;

			default:
				WupMon_Reason.wupRsnStatus = E_NOT_OK;
				break;
		}
	} else {
		WupMon_Reason.wupRsnStatus = E_NOT_OK;
	}
}

/**
 *
 */
Std_ReturnType WupMon_GetWupRsn(uint32 *wupRsn)
{
	Std_ReturnType status = E_NOT_OK;

	if (NULL_PTR != wupRsn) {
		*wupRsn = WupMon_Reason.wupRsn;
		status = WupMon_Reason.wupRsnStatus;
	}

	return status;
}


/**
 *
 */
Std_ReturnType WupMon_SetWupState(WupMon_TEStateMachine state)
{
	Std_ReturnType result = E_NOT_OK;

	if (WUPMON_NO_STATES > state) {
		WupMon_StateMachine = state;
		result = E_OK;
	}

	return result;
}

/**
 *
 */
void WupMon_SetPlayPrtc(uint32 cfg)
{

}

/** Private functions */

/**
 *
 */
static void WupMon_ProcessRsn(void)
{
	switch (WupMon_StateMachine) {
		case WUPMON_ANALYZE_STATE:
			WupMon_AnalyzeWupRsn();
			break;

		case WUPMON_MONITOR_STATE:
			break;

		default :
			break;
	}
}
