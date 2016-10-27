/**
 * \file  main_arm.c
 *
 *  https://github.com/HiOtto/OMAPL138_NandFlashBoot_IPC
 *
 * \ Boot from NandFlash
 * \ Wake DSP 	(spruh77c\13.2 DSP Wake up http://www.ti.com/lit/pdf/spruh77)
 * \ IPC buffer passing between CPUs (ARM side)
 *
 * ! ! ! ! ! !
 * \ @Note: IPC initialization should be placed after waking up DSP, never place any other steps like GPIO test !!!!
 *
 *
 * Copyright (c) 2014, Siqi Liu
 *
 *
 */


#include "ipc_buffer_io.h"
#include "soc_OMAPL138.h"              // OMAPL138 外设寄存器
#include "uart.h"                   // 通用异步串口宏及设备抽象层函数声明
#include "psc.h"                    // 电源与睡眠控制宏及设备抽象层函数声明


#include "hw_types.h"               // 宏命令
#include "hw_syscfg0_OMAPL138.h"       // 系统配置模块寄存器
#include "soc_OMAPL138.h"              // OMAPL138 外设寄存器

#include "gpio.h"                   // 通用输入输出口宏及设备抽象层函数声明

///////////////
#include "psc_init.h"

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


int main(void)
{
	//Set_Core_456MHz();
	//Set_DDR2_156MHz();


	/** GPIO PSC使能 */
	PSCModuleControl(SOC_PSC_1_REGS, HW_PSC_GPIO, PSC_POWERDOMAIN_ALWAYS_ON, PSC_MDCTL_NEXT_ENABLE);
    /** GPIO 管脚复用配置 */
    GPIOBankPinMuxSet();
    /** GPIO 管脚初始化 */
    GPIOBankPinInit();

    // 1. ARM启动
    GPIOPinWrite(SOC_GPIO_0_REGS, 1, GPIO_PIN_HIGH);   // D7  亮 GPIO0[0]
    GPIOPinWrite(SOC_GPIO_0_REGS, 6, GPIO_PIN_HIGH);   // D6  亮 GPIO0[5]
    GPIOPinWrite(SOC_GPIO_0_REGS, 2, GPIO_PIN_HIGH);   // D9  亮 GPIO0[1]
    GPIOPinWrite(SOC_GPIO_0_REGS, 3, GPIO_PIN_HIGH);   // D10 亮 GPIO0[2]

    /** 唤醒C6748 */
    Wake_DSP();

    /** 唤醒DSP与IPC初始化之间不可以有操作 */
//    // 2. DSP唤醒
//    GPIOPinWrite(SOC_GPIO_0_REGS, 1, GPIO_PIN_HIGH);   // D7  亮 GPIO0[0]
//    GPIOPinWrite(SOC_GPIO_0_REGS, 6, GPIO_PIN_LOW);   // D6  亮 GPIO0[5]
//    GPIOPinWrite(SOC_GPIO_0_REGS, 2, GPIO_PIN_LOW);   // D9  亮 GPIO0[1]
//    GPIOPinWrite(SOC_GPIO_0_REGS, 3, GPIO_PIN_LOW);   // D10 亮 GPIO0[2]

    evtRcvd = 0;
    /** IPC Initialize */
    IPCInit();


    // 3. IPC ARM端初始化完成
    GPIOPinWrite(SOC_GPIO_0_REGS, 1, GPIO_PIN_LOW);   // D7  亮 GPIO0[0]
    GPIOPinWrite(SOC_GPIO_0_REGS, 6, GPIO_PIN_HIGH);   // D6  亮 GPIO0[5]
    GPIOPinWrite(SOC_GPIO_0_REGS, 2, GPIO_PIN_LOW);   // D9  亮 GPIO0[1]
    GPIOPinWrite(SOC_GPIO_0_REGS, 3, GPIO_PIN_LOW);   // D10 亮 GPIO0[2]


    /* Wait for event and process it */
    wait_event();

    // 4. 接收DSP端信息
    GPIOPinWrite(SOC_GPIO_0_REGS, 1, GPIO_PIN_LOW);   // D7  亮 GPIO0[0]
    GPIOPinWrite(SOC_GPIO_0_REGS, 6, GPIO_PIN_HIGH);   // D6  亮 GPIO0[5]
    GPIOPinWrite(SOC_GPIO_0_REGS, 2, GPIO_PIN_LOW);   // D9  亮 GPIO0[1]
    GPIOPinWrite(SOC_GPIO_0_REGS, 3, GPIO_PIN_LOW);   // D10 亮 GPIO0[2]

    /* Wait for event and process it */
    myPayload = (UInt32) "Hello from ARM\n";
    iAssert (Notify_sendEvent(IPC_DSP0,IPC_DSP0_INTLINE, EVENTID, myPayload, TRUE));

    //WAIT_HERE;
	for(;;)
	{
		// 延时
		Delay(0x000FFFFF);
    	GPIOPinWrite(SOC_GPIO_0_REGS, 3, GPIO_PIN_LOW);    // D10 灭 GPIO0[2]
		GPIOPinWrite(SOC_GPIO_0_REGS, 1, GPIO_PIN_HIGH);   // D7  亮 GPIO0[0]

		// 延时
		Delay(0x000FFFFF);
		GPIOPinWrite(SOC_GPIO_0_REGS, 1, GPIO_PIN_LOW);    // D7  灭 GPIO0[0]
		GPIOPinWrite(SOC_GPIO_0_REGS, 6, GPIO_PIN_HIGH);   // D6  亮 GPIO0[5]

		// 延时
		Delay(0x000FFFFF);
		GPIOPinWrite(SOC_GPIO_0_REGS, 6, GPIO_PIN_LOW);    // D6  灭 GPIO0[5]
		GPIOPinWrite(SOC_GPIO_0_REGS, 2, GPIO_PIN_HIGH);   // D9  亮 GPIO0[1]

		// 延时
		Delay(0x000FFFFF);
		GPIOPinWrite(SOC_GPIO_0_REGS, 2, GPIO_PIN_LOW);    // D9  灭 GPIO0[1]
		GPIOPinWrite(SOC_GPIO_0_REGS, 3, GPIO_PIN_HIGH);   // D10 亮 GPIO0[2]
	}
}




/* Initialize everything */
void IPCInit(void)
{
    int i;
    /* Data structure allocation and init */
    /* IPC data structure */
    char *p = (char *) &ipcPvMemArm;
    struct IPC_cfg ipcCfg = {
                    IPC_ARM_HOST,            /* local processor Id */
                    IPC_DSP0,                /* remote processor Id */
                    IPC_DSP0_INTLINE,        /* ID of interrupt line to remote CPU */
                    IPC_INTERRUPT_METHOD,    /* Method to receive from remote processor */
                    NUM_MAX_EVENT,           /* maximum number of events to be created */
                    &ipcPvMemArm,            /* local side private IPC memory */
                    &ipcPvMemDsp             /* remote side private IPC memory */
            };

    for (i=0; i<32; i++) *p++ = 0;

    /* Init MMU and caches */

    /* Init interrupt structure */
    IntAINTCInit();

    /* Init IPC */
    IPC_init(&ipcCfg);
    IPC_intRegister(AINTC_IPC_CHNL);                   /* set IPC AINTC channel */
    iAssert (Notify_registerEvent(IPC_DSP0, IPC_DSP0_INTLINE, EVENTID, cbFxnEvent, 0xc0de));

    /*  Enabling the system interrupt for HOST (ARM) CPU and sync IPC */
    IntMasterIRQEnable();
    IntGlobalEnable();
    IntIRQEnable();
    iAssert (Notify_start());



}

/* Trap for errors */
void iAssert (int status)
{
    if (status != Notify_S_SUCCESS)
    {
       // UARTPrintd("Notify failed ", status);
        WAIT_HERE;
    }
}


void wait_event(void)
{
    int i = 0;
    while (!evtRcvd)
        i++;
    evtRcvd = 0;
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
	HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) = 0x88800800;
	// 核心板   GPIO6[12，13]
	//HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) = 0x00008800;
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
//    GPIODirModeSet(SOC_GPIO_0_REGS, 109, GPIO_DIR_OUTPUT);  // GPIO6[12]
//    GPIODirModeSet(SOC_GPIO_0_REGS, 110, GPIO_DIR_OUTPUT);  // GPIO6[13]

    // 底板 LED
    GPIODirModeSet(SOC_GPIO_0_REGS, 1, GPIO_DIR_OUTPUT);    // D7  GPIO0[0]
    GPIODirModeSet(SOC_GPIO_0_REGS, 2, GPIO_DIR_OUTPUT);    // D9  GPIO0[1]
    GPIODirModeSet(SOC_GPIO_0_REGS, 3, GPIO_DIR_OUTPUT);    // D10 GPIO0[2]
    GPIODirModeSet(SOC_GPIO_0_REGS, 6, GPIO_DIR_OUTPUT);    // D6  GPIO0[5]
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

