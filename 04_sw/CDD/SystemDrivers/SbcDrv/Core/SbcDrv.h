/*
 * SbcDrv.h
 *
 *  Created on: 27.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSDRV_SBCDRV_CORE_SBCDRV_H_
#define SYSDRV_SBCDRV_CORE_SBCDRV_H_

#include "SbcDrv_Types.h"

/**
 *
 */
void SbcDrv_PreInit(void);

/**
 *
 */
void SbcDrv_Init(void);

/**
 *
 */
void SbcDrv_MainFunction(void);

/**
 *
 */
void SbcDrv_ResetMcu(void);

/**
 *
 */
Std_ReturnType SbcDrv_GetRstRsn(uint32 *rstRsn);

/**
 *
 */
Std_ReturnType SbcDrv_GetWupRsn(uint32 *wupRsn);

/**
 *
 */
Std_ReturnType SbcDrv_WdgTrigger(void);

/**
 *
 */
Std_ReturnType SbcDrv_SendSyncCmd(uint32 *cmd);

/**
 *
 */
Std_ReturnType SbcDrv_SendASyncCmd(uint32 *cmd);

/**
 *
 */
Std_ReturnType SbcDrv_GoToSleep(void);

#endif /* SYSDRV_SBCDRV_CORE_SBCDRV_H_ */
