/**
 * \file  main_dsp.c
 *
 * https://github.com/HiOtto/OMAPL138_NandFlashBoot_IPC
 *
 * 1. my_boot.asm
 * 2. *.cmd 	(my_boot_sect>L2)
 * 3. build/C600Linker/SymbolManagement/SepcifyProgramEntrypointFortheOutputModule
 *
 *
 * \ DSP is Waked  	(spruh77c\13.2 DSP Wake up)
 * \ IPC buffer passing between CPUs (DSP side)
 *
 *
 * Copyright (c) 2014, Siqi Liu
 *
 *
 */

#include "ipc_buffer_io.h"
#include "hw_types.h"				// HWREG（x）
#include "hw_syscfg0_OMAPL138.h"	// SYSCFG0_PINMUX(x)
#include "soc_OMAPL138.h"			// SOC_GPIO_0_REGS
#include "gpio.h"					// GPIO_DIR_OUTPUT
#include "psc.h"                    // 电源与睡眠控制宏及设备抽象层函数声明

//#include "psc_init.h"

/* Globals */
int    volatile evtRcvd;
UInt32 volatile myPayload;

/* Declarations */
void IPCInit(void);
void iAssert (int);
void wait_event(void);

/****************************************************************************/
/****************************************************************************/
// 外设使能配置
void PSCInit(void);
// GPIO 管脚复用配置
void GPIOBankPinMuxSet();
// GPIO 管脚初始化
void GPIOBankPinInit();
// 延时
void Delay(unsigned int n);
/****************************************************************************/
/****************************************************************************/

/* Event Call back function */
void cbFxnEvent(UInt16 procId, UInt16 lineId,
                UInt32 eventId, UArg arg, UInt32 payload)
{
    myPayload = payload; /* Transfer payload */
    evtRcvd = 1;         /* Flag event to background app */
}
void main (void)
{
	//Set_Core_456MHz();

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    // 外设使能配置
    PSCInit();
    // GPIO 管脚复用配置
    GPIOBankPinMuxSet();
    // GPIO 管脚初始化
    GPIOBankPinInit();
    GPIOPinWrite(SOC_GPIO_0_REGS, 109, GPIO_PIN_HIGH);    // D10 灭 GPIO6[12]
    GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_HIGH);   // D7  亮 GPIO6[13]


    char *str_buf;
    evtRcvd = 0;
     /* Initialize */
    IPCInit();
    //printf("DSP subsystem ready\n");

    /* Allocate I/O buffer and init with string */
    str_buf = (char *) malloc(80);
    str_buf = "Hello from DSP\n";

    GPIOPinWrite(SOC_GPIO_0_REGS, 109, GPIO_PIN_LOW);    // D10 灭 GPIO6[12]
    GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_HIGH);   // D7  亮 GPIO6[13]

    /* Send buffer to remote CPU */
    iAssert (Notify_sendEvent(IPC_ARM_HOST,IPC_HOST_INTLINE, EVENTID, (UInt32) str_buf, TRUE));

    GPIOPinWrite(SOC_GPIO_0_REGS, 109, GPIO_PIN_HIGH);    // D10 灭 GPIO6[12]
    GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_LOW);   // D7  亮 GPIO6[13]
//
//    wait_event();
    //printf((char *) myPayload);//
    //WAIT_HERE;
    for(;;)
    {
    		// 延时
    		Delay(0x000FFFFF);
        	GPIOPinWrite(SOC_GPIO_0_REGS, 109, GPIO_PIN_LOW);    // D10 灭 GPIO6[12]
    		GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_HIGH);   // D7  亮 GPIO6[13]

    		// 延时
    		Delay(0x000FFFFF);
    		GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_LOW);    // D7  灭 GPIO6[13]
    		GPIOPinWrite(SOC_GPIO_0_REGS, 109, GPIO_PIN_HIGH);   // D6  亮 GPIO0[12]


    }
}

/* Initialization */
void IPCInit(void)
{
    /* Structure to initialize IPC (see Ipc.h for definitions) */
    struct IPC_cfg ipcCfg = {
            IPC_DSP0,             /* local processor Id */
            IPC_ARM_HOST,         /* remote processor Id */
            IPC_HOST_INTLINE,     /* ID of interrupt line to remote CPU */
            IPC_INTERRUPT_METHOD, /* Method to receive from remote processor */
            NUM_MAX_EVENT,        /* maximum number of events to be created */
            &ipcPvMemDsp,         /* local side private IPC memory */
            &ipcPvMemArm          /* remote side private IPC memory */
    };
    IntDSPINTCInit();
    IPC_init(&ipcCfg);
    IPC_intRegister(C674X_MASK_INT5);
    iAssert (Notify_registerEvent(IPC_ARM_HOST, IPC_HOST_INTLINE, EVENTID, cbFxnEvent, 0xc0de));

    /*  Enabling interrupts for DSP C674x CPU */
    IntGlobalEnable();        /* Enable C674x global interrupt */
    iAssert (Notify_start()); /* This will enable IPC interrupt */


}

/* Trap for errors */
void    iAssert (int status)
{
    if (status != Notify_S_SUCCESS)
    {
        //printf("Notify failed %d\n", status);
        WAIT_HERE;
    }
}

void    wait_event(void)
{
    int i = 0;  /* can be used as a time out check */
    while (!evtRcvd)
        i++;
/* evtRcvd = 0; */
}




///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/****************************************************************************/
/*                                                                          */
/*              PSC 初始化                                                  */
/*                                                                          */
/****************************************************************************/
void PSCInit(void)
{
	// 使能 GPIO 模块
	// 对相应外设模块的使能也可以在 BootLoader 中完成
    PSCModuleControl(SOC_PSC_1_REGS, HW_PSC_GPIO, PSC_POWERDOMAIN_ALWAYS_ON, PSC_MDCTL_NEXT_ENABLE);
}

/****************************************************************************/
/*                                                                          */
/*              GPIO 管脚复用配置                                           */
/*                                                                          */
/****************************************************************************/
void GPIOBankPinMuxSet(void)
{
	// 配置相应的 GPIO 口功能为普通输入输出口
	// 底板 LED
	//GPIOBank0Pin0PinMuxSetup();
	//GPIOBank0Pin1PinMuxSetup();
	//GPIOBank0Pin2PinMuxSetup();
	//GPIOBank0Pin5PinMuxSetup();

	//volatile unsigned int PINMUX5VAL = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(8));
	//PINMUX5VAL = PINMUX5VAL | 0X88888888;

	// 底板 LED GPIO0[0，1，2，5]
	//HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) = 0x88800800;
	// 核心板   GPIO6[12，13]
	HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) = 0x00008800;
}

/****************************************************************************/
/*                                                                          */
/*              GPIO 管脚初始化                                             */
/*                                                                          */
/****************************************************************************/
void GPIOBankPinInit(void)
{
	// 配置 LED 对应管脚为输出管脚
    // OMAPL138 及 DSP C6748 共有 144 个 GPIO
	// 以下为各组 GPIO BANK 起始管脚对应值
    // 范围 1-144
	// GPIO0[0] 1
    // GPIO1[0] 17
	// GPIO2[0] 33
    // GPIO3[0] 49
	// GPIO4[0] 65
    // GPIO5[0] 81
	// GPIO6[0] 97
	// GPIO7[0] 113
	// GPIO8[0] 129

	// 核心板 LED
    GPIODirModeSet(SOC_GPIO_0_REGS, 109, GPIO_DIR_OUTPUT);  // GPIO6[12]
    GPIODirModeSet(SOC_GPIO_0_REGS, 110, GPIO_DIR_OUTPUT);  // GPIO6[13]

    // 底板 LED
    //GPIODirModeSet(SOC_GPIO_0_REGS, 1, GPIO_DIR_OUTPUT);    // D7  GPIO0[0]
    //GPIODirModeSet(SOC_GPIO_0_REGS, 2, GPIO_DIR_OUTPUT);    // D9  GPIO0[1]
    //GPIODirModeSet(SOC_GPIO_0_REGS, 3, GPIO_DIR_OUTPUT);    // D10 GPIO0[2]
   // GPIODirModeSet(SOC_GPIO_0_REGS, 6, GPIO_DIR_OUTPUT);    // D6  GPIO0[5]
}

/****************************************************************************/
/*                                                                          */
/*              延时                                                        */
/*                                                                          */
/****************************************************************************/
void Delay(volatile unsigned int delay)
{
    while(delay--);
}

