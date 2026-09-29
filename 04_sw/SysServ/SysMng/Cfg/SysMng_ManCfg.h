/*
 * SysMng_ManCfg.h
 *
 *  Created on: 17.02.2023 г.
 *      Author: Vasil Angelov
 */

#ifndef SYSSERV_SYSMNG_CFG_SYSMNG_MANCFG_H_
#define SYSSERV_SYSMNG_CFG_SYSMNG_MANCFG_H_

/** Number of Users */
#define	SYSMNG_NO_COMM_USERS		(3u)
#define	SYSMNG_NO_ECUM_USERS		(2u)

/** BswM states */
#define	SYSMNG_NO_BSWM_STATES		(2u)

/** Numbers of wake-up reasons */
#define	SYSMNG_NO_WUP_REASONS		(5u)

/** States timings */
#define	SYSMNG_AFTERRUN_TIMEOUT		(200u)  /* cyclic_time*200 = 5*200 = 1s */
#define SYSMNG_RUN_TIMEOUT			(1000u) /* cyclic_time*1000 = 5*1000 = 5s */
#define SYSMNG_COMM_DBNC_TIMEOUT	(20u)	/* cyclic_time*20 = 20*5 = 100ms */

#endif /* SYSSERV_SYSMNG_CFG_SYSMNG_MANCFG_H_ */
