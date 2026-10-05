/*
 * SysMng.c
 *
 *  Created on: 17.02.2023 г.
 *      Author: Vasil Angelov
 */

#include "SysMng.h"

#include "WupMon.h"
#include "SleepCtrl.h"

/** Defines */

/** Type definitions */
typedef struct {
	uint32 	comUsers;
	uint32 	ecuUsers;
	uint8 	wupReasons[SYSMNG_NO_WUP_REASONS];
	uint8 	bswStates[SYSMNG_NO_BSWM_STATES];
} SysMng_TSSystemParams;

/** Local variables */
static SysMng_TESysStateMachine SysMng_SystemState = SYSMNG_UNINIT_STATE;
static SysMng_TSSystemParams	SysMng_SysParams;
/* System timers */
static uint16 SysMng_RunEcuTimer = SYSMNG_RUN_TIMEOUT;
static uint16 SysMng_AfterRunTimer = SYSMNG_AFTERRUN_TIMEOUT;

/** Local functions */
static void SysMng_StateMachine(void);
static Std_ReturnType SysMng_GetSysTriggers(void);
/* State processing */
static void SysMng_StartUpProcess(void);
static void SysMng_RunEcuProcess(void);
static void SysMng_RunComProcess(void);
static void SysMng_AfterRunProcess(void);
static void SysMng_RdySleepProcess(void);
/* Support function */
static boolean SysMng_isComMActive(void);
static boolean SysMng_isRunUsrActive(void);
static boolean SysMng_isComUsrActive(void);
static boolean SysMng_isWdgTstPassed(void);

/** Public function implementation */

/**
 *
 */
void SysMng_Init(void)
{
	/* Initialize system state machine */
	(void)SysMng_SetSysState(SYSMNG_STARTUP_STATE);
}

/**
 *
 */
void SysMng_MainFunction(void)
{
	/* Read input parameters */
	if (E_OK == SysMng_GetSysTriggers()) {
		/* Executes system state machine */
		SysMng_StateMachine();
	}
	/* Send information to SWCs */
}

/**
 *
 */
Std_ReturnType SysMng_GetSysState(SysMng_TESysStateMachine *state)
{
	Std_ReturnType result = E_OK;

	if (NULL_PTR != state) {
		*state = SysMng_SystemState;
	}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_SetSysState(SysMng_TESysStateMachine state)
{
	Std_ReturnType result = E_NOT_OK;

	if (state < SYSMNG_NO_STATES) {
		SysMng_SystemState = state;
		result = E_OK;
	}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_GetActiveComUsr(uint32 *comUsr)
{
	Std_ReturnType result = E_NOT_OK;

	if (NULL_PTR != comUsr) {
		*comUsr = SysMng_SysParams.comUsers;
		result = E_OK;
	}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_GetActiveEcuUsr(uint32 *ecuUsr)
{
	Std_ReturnType result = E_NOT_OK;

	if (NULL_PTR != ecuUsr) {
		*ecuUsr = SysMng_SysParams.ecuUsers;
		result = E_OK;
	}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_ComRunRq(uint32 user)
{
	Std_ReturnType result = E_NOT_OK;

	//if () {
		BIT_SET(SysMng_SysParams.comUsers, user);
		result = E_OK;
	//}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_ComReleaseRq(uint32 user)
{
	Std_ReturnType result = E_NOT_OK;

	//if () {
		BIT_CLR(SysMng_SysParams.comUsers, user);
		result = E_OK;
	//}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_EcuRunRq(uint32 user)
{
	Std_ReturnType result = E_NOT_OK;

	//if () {
		BIT_SET(SysMng_SysParams.ecuUsers, user);
		result = E_OK;
	//}

	return result;
}

/**
 *
 */
Std_ReturnType SysMng_EcuReleaseRq(uint32 user)
{
	Std_ReturnType result = E_NOT_OK;

	//if () {
		BIT_CLR(SysMng_SysParams.ecuUsers, user);
		result = E_OK;
	//}

	return result;
}

/** Private Functions implementation */

/**
 *
 */
static void SysMng_StateMachine(void)
{
	switch (SysMng_SystemState) {
		case SYSMNG_STARTUP_STATE:
			SysMng_StartUpProcess();
			break;

		case SYSMNG_RUN_ECU_STATE:
			SysMng_RunEcuProcess();
			break;

		case SYSMNG_RUN_COM_STATE:
			SysMng_RunComProcess();
			break;

		case SYSMNG_AFTER_RUN_STATE:
			SysMng_AfterRunProcess();
			break;

		case SYSMNG_RDY_SLEEP:
			SysMng_RdySleepProcess();
			break;

		default:
		case SYSMNG_UNINIT_STATE:
			break;
	}
}

/**
 *
 */
static Std_ReturnType SysMng_GetSysTriggers(void)
{

}

/**
 *
 */
static void SysMng_StartUpProcess(void)
{
	if (TRUE == SysMng_isComMActive()) {
		/* If communication occurs then goes to RUN_COM_STATE */
		(void)SysMng_SetSysState(SYSMNG_RUN_COM_STATE);
		/* Stops Wup monitoring */
		(void)WupMon_SetWupState(WUPMON_IDLE_STATE);
	} else if (TRUE == SysMng_isWdgTstPassed()) {
		/* Wdg has passed then skip all states and goes to RDY_SLEEP */
		(void)SysMng_SetSysState(SYSMNG_RDY_SLEEP);
		/* Monitors Wup reason during sleep */
		(void)WupMon_SetWupState(WUPMON_MONITOR_STATE);
		/* Release RUN */
#if (ECUM_FIXED_BEHAVIOR == STD_ON)
		/** EcuM fixed */
		/* EcuM_ReleasetRUN(user); */
#else
		/** EcuM flex */
		/* Rte_Write_XXX_BswMRunRequest_requestedMode(RELEASED); */
#endif
	} else {
		/* if communication is not on the bus then goes to RUN_ECU_STATE */
		(void)SysMng_SetSysState(SYSMNG_RUN_ECU_STATE);
		/* Stops Wup monitoring */
		(void)WupMon_SetWupState(WUPMON_IDLE_STATE);
		/* Reload RUN timer */
		SysMng_RunEcuTimer = SYSMNG_RUN_TIMEOUT;
	}
}

/**
 *
 */
static void SysMng_RunEcuProcess(void)
{
	/* Request RUN */
#if (ECUM_FIXED_BEHAVIOR == STD_ON)
	/** EcuM fixed */
	/* EcuM_RequestRUN(user); */
#else
	/** EcuM flex */
	/* Rte_Write_XXX_BswMRunRequest_requestedMode(REQUESTED); */
#endif

	if (TRUE == SysMng_isComMActive()) {
		/* If communication occurs then pass to RUN_COM_STATE */
		(void)SysMng_SetSysState(SYSMNG_RUN_COM_STATE);
	} else if ((FALSE == SysMng_isRunUsrActive()) && (0 == SysMng_RunEcuTimer)) {
		/* Release RUN */
#if (ECUM_FIXED_BEHAVIOR == STD_ON)
		/** EcuM fixed */
		/* EcuM_ReleasetRUN(user); */
#else
		/** EcuM flex */
		/* Rte_Write_XXX_BswMRunRequest_requestedMode(RELEASED); */
#endif
		/* If has no RUN request or communication for SYSMNG_RUN_TIMEOUT then goes to AFTER_RUN_STATE */
		(void)SysMng_SetSysState(SYSMNG_AFTER_RUN_STATE);
		/* Reload AfterRun timer */
		SysMng_AfterRunTimer = SYSMNG_AFTERRUN_TIMEOUT;
	} else {
		if (0 != SysMng_RunEcuTimer) {
			SysMng_RunEcuTimer--;
		}
	}
}

/**
 *
 */
static void SysMng_RunComProcess(void)
{
	/* Request RUN */
#if (ECUM_FIXED_BEHAVIOR == STD_ON)
	/** EcuM fixed */
	/* EcuM_RequestRUN(user); */
#else
	/** EcuM flex */
	/* Rte_Write_XXX_BswMRunRequest_requestedMode(REQUESTED); */
#endif

	if (TRUE == SysMng_isComUsrActive()) {
		/* Request FULL_COM to ComM */
#if (ECUM_FIXED_BEHAVIOR == STD_ON)
		/** EcuM fixed */
		ComM_RequestComMode(USER, COMM_FULL_COMMUNICATION);
#else
		/** EcuM flex */
		/* Rte_Write_XXX_ComMRquest_RequestMode(REQ_FULL_COMM) */
#endif
	} else {
		/* Request NO_COM to ComM */
#if (ECUM_FIXED_BEHAVIOR == STD_ON)
		/** EcuM fixed */
		ComM_RequestComMode(USER, COMM_NO_COMMUNICATION);
#else
		/** EcuM flex */
		/* Rte_Write_XXX_ComMRquest_RequestMode(REQ_NO_COMM) */
#endif
		if (FALSE == SysMng_isComMActive()) {
			if (TRUE == SysMng_isRunUsrActive()) {
				/* if communication is not on the bus but RUN users are there then goes to RUN_ECU_STATE */
				(void)SysMng_SetSysState(SYSMNG_RUN_ECU_STATE);
				/* Reload RUN timer */
				SysMng_RunEcuTimer = SYSMNG_RUN_TIMEOUT;
			} else {
				/* If has no RUN request and communication then goes to AFTER_RUN_STATE */
				(void)SysMng_SetSysState(SYSMNG_AFTER_RUN_STATE);
				/* Reload AfterRun timer */
				SysMng_AfterRunTimer = SYSMNG_AFTERRUN_TIMEOUT;
			}
		}
	}
}

/**
 *
 */
static void SysMng_AfterRunProcess(void)
{
	if (TRUE == SysMng_isComMActive()) {
		/* If communication occurs then pass to RUN_COM_STATE */
		(void)SysMng_SetSysState(SYSMNG_RUN_COM_STATE);
	} else if (TRUE == SysMng_isRunUsrActive()) {
		/* if communication is not on the bus but RUN users are there then goes to RUN_ECU_STATE */
		(void)SysMng_SetSysState(SYSMNG_RUN_ECU_STATE);
		/* Reload RUN timer */
		SysMng_RunEcuTimer = SYSMNG_RUN_TIMEOUT;
	} else {
		if (0 != SysMng_AfterRunTimer) {
			SysMng_AfterRunTimer--;
		} else {
			(void)SysMng_SetSysState(SYSMNG_RDY_SLEEP);
			/* Monitors Wup reason during sleep */
			(void)WupMon_SetWupState(WUPMON_MONITOR_STATE);
		}
	}
}

/**
 *
 */
static void SysMng_RdySleepProcess(void)
{
	if ((TRUE == SysMng_isComMActive()) ||
		(TRUE == SysMng_isRunUsrActive()) ) {
		/* Go back to startup */
		(void)SysMng_SetSysState(SYSMNG_STARTUP_STATE);
		/* Analyze Wup reason */
		(void)WupMon_SetWupState(WUPMON_ANALYZE_STATE);
	} else {
		if (TRUE == SysMng_isWdgTstPassed()) {
			(void)SleepCtrl_SetSleepState(SLEEPCTRL_GOTO_SLEEP);
		} else {
			(void)SleepCtrl_SetSleepState(SLEEPCTRL_WDG_TEST);
		}
	}
}

/**
 *
 */
static boolean SysMng_isComMActive(void)
{
	boolean isActive = FALSE;

#if (ECUM_FIXED_BEHAVIOR == STD_ON)
	/* EcuM fixed */
	/* ComM_GetCurrentComMode(user, &mode); */
#else
	/* EcuM flex */
	if ((SysMng_SysParams.bswStates[0] == RTE_MODE_BswM_RteComMStateIndication_FULL_COMMUNICATION) ||
		(SysMng_SysParams.bswStates[0] == RTE_MODE_BswM_RteComMStateIndication_SILENT_COMMUNICATION))	{
		isActive = TRUE;
	}
#endif

	return isActive;
}

/**
 *
 */
static boolean SysMng_isRunUsrActive(void)
{
	boolean isRunUsr = FALSE;

	for (uint8 usr=0; usr<SYSMNG_NO_ECUM_USERS; usr++) {
		isRunUsr = BIT_GET(SysMng_SysParams.ecuUsers, usr);
	}

	return isRunUsr;
}

/**
 *
 */
static boolean SysMng_isComUsrActive(void)
{
	boolean isComUsr = FALSE;

	for (uint8 usr=0; usr<SYSMNG_NO_COMM_USERS; usr++) {
		isComUsr = BIT_GET(SysMng_SysParams.comUsers, usr);
	}

	return isComUsr;
}

/**
 *
 */
static boolean SysMng_isWdgTstPassed(void)
{
	boolean isWdgTst = FALSE;

	/* ToDo: Add function from WdgMng which gives info wdg test */
	if (0) {
		isWdgTst = TRUE;
	}

	return isWdgTst;
}
