/****************************************************************************/
/*v4.5.0 COMMAND FILE FOR LINKING TMS470 32BIS C/C++ PROGRAMS               */
/*                                                                          */
/*   Usage:  lnk470 <obj files...>    -o <out file> -m <map file> lnk32.cmd */
/*           cl470 <src files...> -z -o <out file> -m <map file> lnk32.cmd  */
/*                                                                          */
/*   Description: This file is a sample command file that can be used       */
/*                for linking programs built with the TMS470 C/C++          */
/*                Compiler.   Use it as a guideline; you may want to change */
/*                the allocation scheme according to the size of your       */
/*                program and the memory layout of your target system.      */
/*                                                                          */
/*   Notes: (1)   You must specify the directory in which run-time support  */
/*                library is located.  Either add a "-i<directory>" line to */
/*                this file, or use the system environment variable C_DIR   */
/*                to specify a search path for libraries.                   */
/*                                                                          */
/*          (2)   If the run-time support library you are using is not      */
/*                named below, be sure to use the correct name here.        */
/*                                                                          */
/****************************************************************************/
-stack  0x8000                             /* SOFTWARE STACK SIZE           */
-heap   0x2000                             /* HEAP AREA SIZE                */
-e Entry

/* SPECIFY THE SYSTEM MEMORY MAP */
#define	IPC_ARM_START			0x80000000
#define	IPC_ARM_SIZE			0x10
#define	IPC_DSP_START			0x80000010  // IPC_ARM_START + IPC_ARM_SIZE
#define	IPC_DSP_SIZE			0x10
#define	SHARED_IRAM_START		0x80000020  // IPC_ARM_START + IPC_ARM_SIZE + IPC_DSP_SIZE
#define SHARED_IRAM_SIZE		0x1FFDF     // 0x1FFFF - (IPC_ARM_SIZE + IPC_DSP_SIZE)

MEMORY
{
	IPC_ARM: o = IPC_ARM_START	l = IPC_ARM_SIZE	/* 16 bytes for ARM */
	IPC_DSP: o = IPC_DSP_START	l = IPC_DSP_SIZE	/* 16 bytes for DSP */
	shared_ram: o = SHARED_IRAM_START  l = SHARED_IRAM_SIZE		/* Remaining IntRAM	*/
		DDR_MEM    	: org = 0xC1080000  len = 0x02F7FFFF    /* 50MB of DDR2 RAM */
}

/* SPECIFY THE SECTIONS ALLOCATION INTO MEMORY */

SECTIONS
{
    .init 	 : { 
    			 system_config.lib<init.obj> (.text) 
    		   } load > 0xC1080000
  			
    .text    : load > DDR_MEM              /* CODE                              */
	.data    : load	> DDR_MEM
    .bss     : load > DDR_MEM              /* GLOBAL & STATIC VARS              */
    				RUN_START(bss_start),
					RUN_END(bss_end)
    .const   : load > DDR_MEM              /* SOFTWARE SYSTEM STACK             */
    .cinit   : load > DDR_MEM              /* SOFTWARE SYSTEM STACK             */
    .sysmem	 : load > DDR_MEM
    .stack   : load > DDR_MEM           	/* SOFTWARE SYSTEM STACK            */
    ipc_arm	 : load > IPC_ARM				/* memory dedicated to IPC module	*/
    ipc_dsp	 : load > IPC_DSP
}

