/**
 * \file  ipc_buffer_io.h
 *
 * \brief Shared header file for IPC buffer I/O example application
 */

/* Copyright (c) 2011, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#ifndef IPC_BUFFERIO_H_
#define IPC_BUFFERIO_H_

/* Generic C headers */
#include <stdio.h>
#include <stddef.h>

/* Common C6-ware headers */
#include "hw_types.h"
#include "hw_aintc.h"
#include "uart.h"
#include "uartStdio.h"
#include "interrupt.h"

/* No OS IPC headers */
#include "ipc.h"
#include "notify.h"

#define WAIT_HERE   while(1);

/* Allocate private IPC memories */
#ifdef __TI_COMPILER_VERSION__
    #pragma DATA_SECTION(ipcPvMemArm, "ipc_arm");
    IPC_notifyEvent ipcPvMemArm; /* space for event to ARM */
    #pragma DATA_SECTION(ipcPvMemDsp, "ipc_dsp");
    IPC_notifyEvent ipcPvMemDsp; /* space for event to DSP */
#else
    IPC_notifyEvent ipcPvMemArm __attribute__ ((section ("ipc_arm"))) = {0};
    IPC_notifyEvent ipcPvMemDsp __attribute__ ((section ("ipc_arm"))) = {0};
#endif

/* APP related definitions */
#define NUM_MAX_EVENT       1   /* Only one event needed */
#define EVENTID             0
#define AINTC_IPC_CHNL      3   /* AINTC INTERRUPT CHANNEL USED FOR IPC INT TO ARM CPU */
#define AINTC_UART2_CHNL    2   /*   "            "             "        UART */

#endif /* IPC_BUFFERIO_H_ */
