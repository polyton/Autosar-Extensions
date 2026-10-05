/*
 * RstMng.h
 *
 *  Created on: 21.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSDRV_RSTMNG_CORE_RSTMNG_H_
#define SYSDRV_RSTMNG_CORE_RSTMNG_H_

#include "RstMng_Types.h"
#include "RstMng_ManCfg.h"

/**
 *
 */
void RstMng_Init(void);

/**
 *
 */
void RstMng_MainFunction(void);

/**
 *
 */
Std_ReturnType RstMng_ResetRq(uint8 module, uint8 rsn);

/**
 *
 */
Std_ReturnType RstMng_SaveRstRsn(uint8 module, uint8 rsn);

#endif /* SYSDRV_RSTMNG_CORE_RSTMNG_H_ */
