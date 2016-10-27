/*
 * sys_init.h
 *
 *  Created on: 2016-10-25
 *      Author: Siqi Liu
 */

#ifndef SYS_INIT_H_
#define SYS_INIT_H_



#define PLL0_BASE       0x01C11000                              /*SYSTEM PLL BASE ADDRESS*/
#define PLL0_PID        *(unsigned int*) (PLL0_BASE + 0x00)     /*PID*/
#define PLL0_RSTYPE     *(unsigned int*) (PLL0_BASE + 0xE4)     /*Reset Type status Reg*/
#define PLL0_PLLCTL     *(unsigned int*) (PLL0_BASE + 0x100)    /*PLL Control Register*/
#define PLL0_OCSEL      *(unsigned int*) (PLL0_BASE + 0x104)    /*OBSCLK Select Register*/
#define PLL0_SECCTL     *(unsigned int*) (PLL0_BASE + 0x108)    /*PLL Secondary Control Register*/
#define PLL0_PLLM       *(unsigned int*) (PLL0_BASE + 0x110)    /*PLL Multiplier*/
#define PLL0_PREDIV     *(unsigned int*) (PLL0_BASE + 0x114)    /*Pre divider*/
#define PLL0_PLLDIV1    *(unsigned int*) (PLL0_BASE + 0x118)    /*Divider-1*/
#define PLL0_PLLDIV2    *(unsigned int*) (PLL0_BASE + 0x11C)    /*Divider-2*/
#define PLL0_PLLDIV3    *(unsigned int*) (PLL0_BASE + 0x120)    /*Divider-3*/
#define PLL0_OSCDIV1    *(unsigned int*) (PLL0_BASE + 0x124)    /*Oscilator Divider*/
#define PLL0_POSTDIV    *(unsigned int*) (PLL0_BASE + 0x128)    /*Post Divider*/
#define PLL0_BPDIV      *(unsigned int*) (PLL0_BASE + 0x12C)    /*Bypass Divider*/
#define PLL0_WAKEUP     *(unsigned int*) (PLL0_BASE + 0x130)    /*Wakeup Reg*/
#define PLL0_PLLCMD     *(unsigned int*) (PLL0_BASE + 0x138)    /*Command Reg*/
#define PLL0_PLLSTAT    *(unsigned int*) (PLL0_BASE + 0x13C)    /*Status Reg*/
#define PLL0_ALNCTL     *(unsigned int*) (PLL0_BASE + 0x140)    /*Clock Align Control Reg*/
#define PLL0_DCHANGE    *(unsigned int*) (PLL0_BASE + 0x144)    /*PLLDIV Ratio Chnage status*/
#define PLL0_CKEN       *(unsigned int*) (PLL0_BASE + 0x148)    /*Clock Enable Reg*/
#define PLL0_CKSTAT     *(unsigned int*) (PLL0_BASE + 0x14C)    /*Clock Status Reg*/
#define PLL0_SYSTAT     *(unsigned int*) (PLL0_BASE + 0x150)    /*Sysclk status reg*/
#define PLL0_PLLDIV4    *(unsigned int*) (PLL0_BASE + 0x160)    /*Divider 4*/
#define PLL0_PLLDIV5    *(unsigned int*) (PLL0_BASE + 0x164)    /*Divider 5*/
#define PLL0_PLLDIV6    *(unsigned int*) (PLL0_BASE + 0x168)    /*Divider 6*/
#define PLL0_PLLDIV7    *(unsigned int*) (PLL0_BASE + 0x16C)    /*Divider 7*/
#define PLL0_PLLDIV8    *(unsigned int*) (PLL0_BASE + 0x170)    /*Divider 8*/
#define PLL0_PLLDIV9    *(unsigned int*) (PLL0_BASE + 0x174)    /*Divider 9*/
#define PLL0_PLLDIV10   *(unsigned int*) (PLL0_BASE + 0x178)    /*Divider 10*/
#define PLL0_PLLDIV11   *(unsigned int*) (PLL0_BASE + 0x17C)    /*Divider 11*/
#define PLL0_PLLDIV12   *(unsigned int*) (PLL0_BASE + 0x180)    /*Divider 12*/
#define PLL0_PLLDIV13   *(unsigned int*) (PLL0_BASE + 0x184)    /*Divider 13*/
#define PLL0_PLLDIV14   *(unsigned int*) (PLL0_BASE + 0x188)    /*Divider 14*/
#define PLL0_PLLDIV15   *(unsigned int*) (PLL0_BASE + 0x18C)    /*Divider 15*/
#define PLL0_PLLDIV16   *(unsigned int*) (PLL0_BASE + 0x190)    /*Divider 16*/

#define PLL1_BASE       0x01E1A000                              /*SYSTEM PLL1 BASE ADDRESS*/
#define PLL1_PID        *(unsigned int*) (PLL1_BASE + 0x00)     /*PID*/
#define PLL1_RSTYPE     *(unsigned int*) (PLL1_BASE + 0xE4)     /*Reset Type status Reg*/
#define PLL1_PLLCTL     *(unsigned int*) (PLL1_BASE + 0x100)    /*PLL Control Register*/
#define PLL1_OCSEL      *(unsigned int*) (PLL1_BASE + 0x104)    /*OBSCLK Select Register*/
#define PLL1_SECCTL     *(unsigned int*) (PLL1_BASE + 0x108)    /*PLL Secondary Control Register*/
#define PLL1_PLLM       *(unsigned int*) (PLL1_BASE + 0x110)    /*PLL Multiplier*/
#define PLL1_PREDIV     *(unsigned int*) (PLL1_BASE + 0x114)    /*Pre divider*/
#define PLL1_PLLDIV1    *(unsigned int*) (PLL1_BASE + 0x118)    /*Divider-1*/
#define PLL1_PLLDIV2    *(unsigned int*) (PLL1_BASE + 0x11C)    /*Divider-2*/
#define PLL1_PLLDIV3    *(unsigned int*) (PLL1_BASE + 0x120)    /*Divider-3*/
#define PLL1_OSCDIV1    *(unsigned int*) (PLL1_BASE + 0x124)    /*Oscilator Divider*/
#define PLL1_POSTDIV    *(unsigned int*) (PLL1_BASE + 0x128)    /*Post Divider*/
#define PLL1_BPDIV      *(unsigned int*) (PLL1_BASE + 0x12C)    /*Bypass Divider*/
#define PLL1_WAKEUP     *(unsigned int*) (PLL1_BASE + 0x130)    /*Wakeup Reg*/
#define PLL1_PLLCMD     *(unsigned int*) (PLL1_BASE + 0x138)    /*Command Reg*/
#define PLL1_PLLSTAT    *(unsigned int*) (PLL1_BASE + 0x13C)    /*Status Reg*/
#define PLL1_ALNCTL     *(unsigned int*) (PLL1_BASE + 0x140)    /*Clock Align Control Reg*/
#define PLL1_DCHANGE    *(unsigned int*) (PLL1_BASE + 0x144)    /*PLLDIV Ratio Chnage status*/
#define PLL1_CKEN       *(unsigned int*) (PLL1_BASE + 0x148)    /*Clock Enable Reg*/
#define PLL1_CKSTAT     *(unsigned int*) (PLL1_BASE + 0x14C)    /*Clock Status Reg*/
#define PLL1_SYSTAT     *(unsigned int*) (PLL1_BASE + 0x150)    /*Sysclk status reg*/
#define PLL1_PLLDIV4    *(unsigned int*) (PLL1_BASE + 0x160)    /*Divider 4*/
#define PLL1_PLLDIV5    *(unsigned int*) (PLL1_BASE + 0x164)    /*Divider 5*/
#define PLL1_PLLDIV6    *(unsigned int*) (PLL1_BASE + 0x168)    /*Divider 6*/
#define PLL1_PLLDIV7    *(unsigned int*) (PLL1_BASE + 0x16C)    /*Divider 7*/
#define PLL1_PLLDIV8    *(unsigned int*) (PLL1_BASE + 0x170)    /*Divider 8*/
#define PLL1_PLLDIV9    *(unsigned int*) (PLL1_BASE + 0x174)    /*Divider 9*/
#define PLL1_PLLDIV10   *(unsigned int*) (PLL1_BASE + 0x178)    /*Divider 10*/
#define PLL1_PLLDIV11   *(unsigned int*) (PLL1_BASE + 0x17C)    /*Divider 11*/
#define PLL1_PLLDIV12   *(unsigned int*) (PLL1_BASE + 0x180)    /*Divider 12*/
#define PLL1_PLLDIV13   *(unsigned int*) (PLL1_BASE + 0x184)    /*Divider 13*/
#define PLL1_PLLDIV14   *(unsigned int*) (PLL1_BASE + 0x188)    /*Divider 14*/
#define PLL1_PLLDIV15   *(unsigned int*) (PLL1_BASE + 0x18C)    /*Divider 15*/
#define PLL1_PLLDIV16   *(unsigned int*) (PLL1_BASE + 0x190)    /*Divider 16*/

/*PSC Module Related Registers*/
#define PSC0_BASE       0x01C10000
#define PSC1_BASE       0x01E27000

#define PSC0_MDCTL      (PSC0_BASE+0xA00)
#define PSC0_MDSTAT     (PSC0_BASE+0x800)
#define PSC0_PTCMD      *(unsigned int*) (PSC0_BASE + 0x120)
#define PSC0_PTSTAT     *(unsigned int*) (PSC0_BASE + 0x128)

#define PSC1_MDCTL      (PSC1_BASE+0xA00)
#define PSC1_MDSTAT     (PSC1_BASE+0x800)
#define PSC1_PTCMD      *(unsigned int*) (PSC1_BASE + 0x120)
#define PSC1_PTSTAT     *(unsigned int*) (PSC1_BASE + 0x128)

#define PSC_TIMEOUT      200 // This value can be optimized by the user

#define LPSC_EDMA_CC0    0
#define LPSC_EDMA_TC0    1
#define LPSC_EDMA_TC1    2
#define LPSC_EMIFA       3   /*PSC0*/
#define LPSC_SPI0        4   /*PSC0*/
#define LPSC_MMCSD0      5   /*PSC0*/
#define LPSC_ARM_AINTC   6
#define LPSC_ARM_RAMROM  7   /*PSC0*/
// LPSC #8 not used
#define LPSC_UART0       9   /*PSC0*/
#define LPSC_SCR0        10
#define LPSC_SCR1        11
#define LPSC_SCR2        12
#define LPSC_PRU         13  /*PSC0*/
#define LPSC_ARM         14  /*PSC0*/
#define LPSC_DSP         15  /*PSC0*/

#define LPSC_EDMA_CC1    0
#define LPSC_USB20       1   /*PSC1*/
#define LPSC_USB11       2   /*PSC1*/
#define LPSC_GPIO        3   /*PSC1*/
#define LPSC_UHPI        4   /*PSC1*/
#define LPSC_EMAC        5   /*PSC1*/
#define LPSC_DDR         6   /*PSC1*/
#define LPSC_MCASP0      7   /*PSC1*/
#define LPSC_SATA        8   /*PSC1*/
#define LPSC_VPIF        9   /*PSC1*/
#define LPSC_SPI1        10  /*PSC1*/
#define LPSC_I2C1        11  /*PSC1*/
#define LPSC_UART1       12  /*PSC1*/
#define LPSC_UART2       13  /*PSC1*/
#define LPSC_MCBSP0      14  /*PSC1*/
#define LPSC_MCBSP1      15  /*PSC1*/
#define LPSC_LCDC        16  /*PSC1*/
#define LPSC_EPWM        17  /*PSC1*/
#define LPSC_MMCSD1      18
#define LPSC_UPP         19
#define LPSC_ECAP        20
#define LPSC_EDMA_TC2    21
// LPSC #22-23 not used
#define LPSC_SCR_F0      24
#define LPSC_SCR_F1      25
#define LPSC_SCR_F2      26
#define LPSC_SCR_F6      27
#define LPSC_SCR_F7      28
#define LPSC_SCR_F8      29
#define LPSC_BR_F7       30
#define LPSC_SHARED_RAM  31

/*DDR MMR Declaration*/
#define VTPIO_CTL           *(unsigned int*)(0x01E2C000)                  // VTPIO_CTL Register
#define EMIFDDR_SDRAM_CFG   0xB0000000
#define EMIFDDR_REVID       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x00)      //EMIF Module ID and Revision Register
#define EMIFDDR_SDRSTAT     *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x04)      //SDRAM Status Register
#define EMIFDDR_SDCR        *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x08)      //SDRAM Bank Config Register
#define EMIFDDR_SDRCR       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x0C)      //SDRAM Refresh Control Register
#define EMIFDDR_SDTIMR1     *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x10)      //SDRAM Timing Register1
#define EMIFDDR_SDTIMR2     *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x14)      //SDRAM Timing Register2
#define EMIFDDR_SDCR2       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x1C)      //SDRAM Config Register2
#define EMIFDDR_PBBPR       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x20)      //VBUSM Burst Priority Register
#define EMIFDDR_VBUSMCFG1   *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x28)      //VBUSM config Value1 Register
#define EMIFDDR_VBUSMCFG2   *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x2C)      //VBUSM config Value2 Register
#define EMIFDDR_IRR         *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xC0)      //Interrupt Raw Register
#define EMIFDDR_IMR         *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xC4)      //Interrupt Masked Register
#define EMIFDDR_IMSR        *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xC8)      //Interrupt Mask Set Register
#define EMIFDDR_IMCR        *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xCC)      //Interrupt Mask Clear Register
#define DDRPHYREV           *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xE0)      //DDR PHY ID and Revision Register
#define DRPYC1R             *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xE4)      //DDR PHY Control 1 Register

#define DDR2 0              // Do not change this value
#define MDDR 1              // Do not change this value
#define VTP_TIMEOUT 200     // This value can be optimized by the user
#define DDR_DEBUG 0         // Set this to "1" to program DDR with more timing slack

#define EMIFDDR_BASE_ADDR       0xC0000000
#define EMIFA_BASE_ADDR         0x40000000
#define EMIFA_CS2_BASE_ADDR     0x60000000
#define EMIFA_CS3_BASE_ADDR     0x62000000
#define EMIFA_CS4_BASE_ADDR     0x64000000
#define EMIFA_CS5_BASE_ADDR     0x66000000

/*EMIF2.5 MMR Declaration*/
#define EMIFA             0x68000000

#define EMIFA_AWAITCFG    *(unsigned int*)(EMIFA + 0x04)
#define EMIFA_SDCFG       *(unsigned int*)(EMIFA + 0x08)
#define EMIFA_SDREF       *(unsigned int*)(EMIFA + 0x0C)
#define EMIFA_ACFG2       *(unsigned int*)(EMIFA + 0x10)    //Async Bank1 Config Register
#define EMIFA_ACFG3       *(unsigned int*)(EMIFA + 0x14)    //Async Bank2 Config Register
#define EMIFA_ACFG4       *(unsigned int*)(EMIFA + 0x18)    //Async Bank3 Config Register
#define EMIFA_ACFG5       *(unsigned int*)(EMIFA + 0x1C)    //Async Bank4 Config Register
#define EMIFA_SDTIM       *(unsigned int*)(EMIFA + 0x20)    //SDRAM Timing Register
#define EMIFA_SRPD        *(unsigned int*)(EMIFA + 0x3C)
#define EMIFA_NANDFCR     *(unsigned int*)(EMIFA + 0x60)


/*System MMR Declaration*/
#define SYS_BASE           0x01C14000
#define HOST0CFG           *(unsigned int*)(SYS_BASE + 0x040)  //ARM HOST0CFG
#define HOST1CFG           *(unsigned int*)(SYS_BASE + 0x044)  //ARM HOST1CFG
#define KICK0R             *(unsigned int*)(SYS_BASE + 0x038)
#define KICK1R             *(unsigned int*)(SYS_BASE + 0x03c)
#define PINMUX0            *(unsigned int*)(SYS_BASE + 0x120)  //PINMUX0
#define PINMUX1            *(unsigned int*)(SYS_BASE + 0x124)  //PINMUX1
#define PINMUX2            *(unsigned int*)(SYS_BASE + 0x128)  //PINMUX2
#define PINMUX3            *(unsigned int*)(SYS_BASE + 0x12C)  //PINMUX3
#define PINMUX4            *(unsigned int*)(SYS_BASE + 0x130)  //PINMUX4
#define PINMUX5            *(unsigned int*)(SYS_BASE + 0x134)  //PINMUX5
#define PINMUX6            *(unsigned int*)(SYS_BASE + 0x138)  //PINMUX6
#define PINMUX7            *(unsigned int*)(SYS_BASE + 0x13C)  //PINMUX7
#define PINMUX8            *(unsigned int*)(SYS_BASE + 0x140)  //PINMUX8
#define PINMUX9            *(unsigned int*)(SYS_BASE + 0x144)  //PINMUX9
#define PINMUX10           *(unsigned int*)(SYS_BASE + 0x148)  //PINMUX10
#define PINMUX11           *(unsigned int*)(SYS_BASE + 0x14C)  //PINMUX11
#define PINMUX12           *(unsigned int*)(SYS_BASE + 0x150)  //PINMUX12
#define PINMUX13           *(unsigned int*)(SYS_BASE + 0x154)  //PINMUX13
#define PINMUX14           *(unsigned int*)(SYS_BASE + 0x158)  //PINMUX14
#define PINMUX15           *(unsigned int*)(SYS_BASE + 0x15C)  //PINMUX15
#define PINMUX16           *(unsigned int*)(SYS_BASE + 0x160)  //PINMUX16
#define PINMUX17           *(unsigned int*)(SYS_BASE + 0x164)  //PINMUX17
#define PINMUX18           *(unsigned int*)(SYS_BASE + 0x168)  //PINMUX18
#define PINMUX19           *(unsigned int*)(SYS_BASE + 0x16C)  //PINMUX19
#define CFGCHIP0           *(unsigned int*)(SYS_BASE + 0x17C)
#define CFGCHIP2           *(unsigned int*)(SYS_BASE + 0x184)
#define CFGCHIP3           *(unsigned int*)(SYS_BASE + 0x188)
#define PD0                0   /*Power Domain-0*/
#define PD1                1   /*Power Domain-1*/

#define PLLEN_MUX_SWITCH         4
#define PLL_LOCK_TIME_CNT        2400
#define PLL_STABILIZATION_TIME   2000
#define PLL_RESET_TIME_CNT       200



/**************************************************************************************************************************************************
   Device_PLL0 init:

   CLKMODE -  0---->On Chip Oscilator  1---->External Oscilator
   PLL0_SYSCLK1 - Fixed ratio /1
   PLL0_SYSCLK2 - Fixed ratio /2
   PLL0_SYSCLK3 - Variable Divider (EMIFA)
   PLL0_SYSCLK4 - Fixed ratio /4
   PLL0_SYSCLK5 - Not used -- do nothing
   PLL0_SYSCLK6 - Fixed ratio /1
   PLL0_SYSCLK7 - Variable Divider (RMII)
******************************************************************************************************************************************************/
void device_PLL0(unsigned int CLKMODE, unsigned int PLLM, unsigned int POSTDIV,unsigned int PLLDIV1, unsigned int PLLDIV2, unsigned int PLLDIV3, unsigned int PLLDIV7 ) {

    unsigned int i=0;

    /* Clear PLL lock bit */
    CFGCHIP0 &= ~(0x00000010);

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    PLL0_PLLCTL &= ~(0x00000020);

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
    PLL0_PLLCTL &= ~(0x00000200);

    /* Set PLLEN=0 to put in bypass mode*/
    PLL0_PLLCTL &= ~(0x00000001);

    /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
    for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}

    /* Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
    PLL0_PLLCTL &= 0xFFFFFEFF;
    PLL0_PLLCTL |= (CLKMODE << 8);

    /*Clear PLLRST bit to reset the PLL */
    PLL0_PLLCTL &= ~(0x00000008);

    /* Disable the PLL output*/
    PLL0_PLLCTL |= (0x00000010);

    /* PLL initialization sequence
    Power up the PLL by setting PWRDN bit set to 0 */
    PLL0_PLLCTL &= ~(0x00000002);

    /* Enable the PLL output*/
    PLL0_PLLCTL &= ~(0x00000010);

    /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
    for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}

    /*Program the required multiplier value in PLLM*/
    PLL0_PLLM    = PLLM;

    /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
    PLL0_POSTDIV = 0x8000 | POSTDIV;

    /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
    while(PLL0_PLLSTAT & 0x1==1){}

    /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    PLL0_PLLDIV1 = 0x8000 | PLLDIV1;             // Fixed Ratio /1
    PLL0_PLLDIV2 = 0x8000 | PLLDIV2;             // Fixed Ratio /2
    PLL0_PLLDIV4 = 0x8000 | (((PLLDIV1+1)*4)-1); // Fixed Ratio /4
    PLL0_PLLDIV6 = 0x8000 | PLLDIV1;             // Fixed Ratio /1
    PLL0_PLLDIV3 = 0x8000 | PLLDIV3;             // Variable Ratio (EMIF)
    PLL0_PLLDIV7 = 0x8000 | PLLDIV7;             // Variable Ratio (RMII)


    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    PLL0_PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(PLL0_PLLSTAT & 0x1==1) { }

    /*Wait for PLL to reset properly.*/
    for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}

    /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
    PLL0_PLLCTL |= 0x8;

    /*Wait for PLL to lock.*/
    for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;}

    /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
    PLL0_PLLCTL |=  0x1;
}

/**********************************************************************************
DDR PLL1 init:

***********************************************************************************/
void device_PLL1(unsigned int PLLM,unsigned int POSTDIV,unsigned int PLLDIV1, unsigned int PLLDIV2, unsigned int PLLDIV3 ) {

    unsigned int i=0;

    /* Clear PLL lock bit */
    CFGCHIP3 &= ~(0x00000020);

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    PLL1_PLLCTL &= ~(0x00000020);

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
    PLL1_PLLCTL &= ~(0x00000200);

    /* Set PLLEN=0 to put in bypass mode*/
    PLL1_PLLCTL &= ~(0x00000001);

    /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
    for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}

    /*Clear PLLRST bit to reset the PLL */
    PLL1_PLLCTL &= ~(0x00000008);

    /* Disable the PLL output*/
    PLL1_PLLCTL |= (0x00000010);

    /* PLL initialization sequence
    Power up the PLL by setting PWRDN bit set to 0 */
    PLL1_PLLCTL &= ~(0x00000002);

    /* Enable the PLL output*/
    PLL1_PLLCTL &= ~(0x00000010);

    /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
    for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}

    /*Program the required multiplier value in PLLM*/
    PLL1_PLLM    = PLLM;

    /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
    PLL1_POSTDIV = 0x8000 | POSTDIV;

    /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
    while(PLL1_PLLSTAT & 0x1==1){}

    /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    PLL1_PLLDIV1 = 0x8000 | PLLDIV1;   // DDR frequency (aka 2X_CLK)
    PLL1_PLLDIV2 = 0x8000 | PLLDIV2;   // Optional CFGCHIP3[ASYNC3_CLKSRC] clock source
    PLL1_PLLDIV3 = 0x8000 | PLLDIV3;   // Optional PLL0 clock source

    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    PLL1_PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(PLL1_PLLSTAT & 0x1==1) { }

    /*Wait for PLL to reset properly */
    for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}

    /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
    PLL1_PLLCTL |= 0x8;

    /*Wait for PLL to lock. See PLL spec for PLL lock time*/
    for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;}

    /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
    PLL1_PLLCTL |=  0x1;
}

/**********************************************************************************
  PSC Common functions :

***********************************************************************************/
/*Force module state without handshaking */
void PSC1_LPSC_force(unsigned int LPSC_num) {
    *(unsigned int*) (PSC1_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC1_MDCTL+4*LPSC_num) | 0x80000000);
}

/*SyncReset Function for PSC1*/
void PSC1_LPSC_SyncReset(unsigned int PD, unsigned int LPSC_num) {
    unsigned int j;

    if( (*(unsigned int*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) != 0x1 ) {
      *(unsigned int*) (PSC1_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC1_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0001;
      PSC1_PTCMD = 0x1<<PD;

      j = 0;
      /*Wait for power state transition to finish*/
      while( (PSC1_PTSTAT & (0x1<<PD) ) !=0) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC1 Sync Reset Transition Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }

      j = 0;
      while( (*(unsigned int*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) !=0x1) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC1 Sync Reset Verify Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }
    }
}

/*Enable Function for PSC1*/
void PSC1_LPSC_enable(unsigned int PD, unsigned int LPSC_num) {
    unsigned int j;

    if( (*(unsigned int*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) != 0x3 ) {
      *(unsigned int*) (PSC1_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC1_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0003;
      PSC1_PTCMD = 0x1<<PD;

      j = 0;
      /*Wait for power state transition to finish*/
      while( (PSC1_PTSTAT & (0x1<<PD) ) !=0) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC1 Enable Transition Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }

      j = 0;
      while( (*(unsigned int*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) !=0x3) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC1 Enable Verify Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }
    }
}

/*LPSC Enable Function for ARM or DSP*/
void PSC0_LPSC_enableCore(unsigned int PD, unsigned int LPSC_num) {
    unsigned int j;

    if( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x11F) != 0x103 ) {
      *(unsigned int*) (PSC0_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC0_MDCTL+4*LPSC_num) & 0xFFFFFEE0) | 0x0103;
      PSC0_PTCMD = 0x1<<PD;

      j = 0;
      /*Wait for power state transition to finish*/
      while( (PSC0_PTSTAT & (0x1<<PD) ) !=0) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC0 Enable Core Transition Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }

      j = 0;
      while( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x11F) !=0x103) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC0 Enable Core Verify Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }
    }
}

/*SyncReset Function for PSC0*/
void PSC0_LPSC_SyncReset(unsigned int PD, unsigned int LPSC_num) {
    unsigned int j;

    if( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) != 0x1 ) {
      *(unsigned int*) (PSC0_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC0_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0001;
      PSC0_PTCMD = 0x1<<PD;

      j = 0;
      /*Wait for power state transition to finish*/
      while( (PSC0_PTSTAT & (0x1<<PD) ) !=0) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC0 Sync Reset Transition Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }

      j = 0;
      while( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) !=0x1) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC0 Sync Reset Verify Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }
    }
}

/*Enable Function for PSC0*/
void PSC0_LPSC_enable(unsigned int PD, unsigned int LPSC_num) {
    unsigned int j;

    if( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) != 0x3 ) {
      *(unsigned int*) (PSC0_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC0_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0003;
      PSC0_PTCMD = 0x1<<PD;

      j = 0;
      /*Wait for power state transition to finish*/
      while( (PSC0_PTSTAT & (0x1<<PD) ) !=0) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC0 Enable Transition Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }

      j = 0;
      while( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) !=0x3) {
        if( j++ > PSC_TIMEOUT ) {
          printf("\tPSC0 Enable Verify Timeout on Domain %d, LPSC %d\n","Output",1,1,1,PD,LPSC_num);
          break;
        }
      }
    }
}


/**********************************************************************************
  DDR Configuration routine:
    1. DDR Enable
    2. VTP calibration
    3. Configure DDR
    4. Set to self-refresh, enable mclkstop and DDR Sync Reset
    5. Enable DDR and disable self-refresh

  int freq is MHz

  DDR2 = 0
  MDDR = 1

  A DDR configuration spreadsheet tool is located here:
    http://processors.wiki.ti.com/index.php/Programming_mDDR/DDR2_EMIF_on_OMAP-L1x/C674x

***********************************************************************************/
// 0xB000 0008 SDCR    0x00134632
// 0xB000 000C SDRCR   0xC0000260
// 0xB000 0010 SDTIMR1 0x264A2A09
// 0xB000 0014 SDTIMR2 0x4412C722
// 0xB000 001C SDCR2   0x00000000
// 0xB000 00E4 DRPYC1R 0x000000C3
void DEVICE_DDRConfig()
{
    unsigned int j;
    unsigned int tmp_SDCR;

    // Enable the Clock to EMIFDDR SDRAM
    PSC1_LPSC_enable(PD0, LPSC_DDR);

    // Begin VTP Calibration
    VTPIO_CTL &= ~0x00000040;       // Clear POWERDN
    VTPIO_CTL &= ~0x00000080;       // Clear LOCK
    VTPIO_CTL |=  0x00002000;       // Set CLKRZ in case it was cleared before (VTP looks for CLKRZ edge transition)
    VTPIO_CTL &= ~0x00002000;       // Clear CLKRZ (Use read-modify-write to ensure 1 VTP cycle wait for previous instruction)
    VTPIO_CTL |=  0x00002000;       // Set CLKRZ (Use read-modify-write to ensure 1 VTP cycle wait for previous instruction)

    j = 0;
    // Polling READY bit to see when VTP calibration is done
    while((VTPIO_CTL & 0x00008000) == 0) {
      if( j++ > VTP_TIMEOUT ) {
        printf("\tVTP Ready timeout\n","Output",1,1,1);
        break;
      }
    }

    VTPIO_CTL |= 0x00000080;       // Set LOCK bit for static calibration mode
    VTPIO_CTL |= 0x00000040;       // Set POWERDN bit to power down VTP module
    // End VTP Calibration

    VTPIO_CTL |= 0x00004000;       // Set IOPWRDN to allow powerdown of input receivers when PWRDNEN is set

    // **********************************************************************************************
    // Setting based 1Gb DDR2 Samsung K4T1G164QF-BCF8
    // Config DDR timings
    DRPYC1R     = (0x0               << 8)   |  // Reserved
                  (0x1               << 7)   |  // EXT_STRBEN
                  (0x1               << 6)   |  // PWRDNEN
                  (0x0               << 3)   |  // Reserved
                  (0x3               << 0);     // RL
    // DRPYC1R Value = 0x000000C3

    if( DDR_DEBUG ) {
      // Configure EMIF with max timings for more slack
      // Try this if memory is not stable
      DRPYC1R  |=  0x7; // RL
    }

    EMIFDDR_SDCR |= 0x00800000; // Set BOOTUNLOCK

    // Settings depending on DDR2
      tmp_SDCR = (0x0               << 25)  |  // MSDRAMEN
                 (0x1               << 20);    // DDR2EN
      printf("\tUsing DDR2 settings\n","Output",1,1,1);

	EMIFDDR_SDCR = tmp_SDCR                    |  // Settings that change depending on DDR2 or MDDR
				   (EMIFDDR_SDCR & 0xF0000000) |  // Reserved
				   (0x0               << 27)   |  // DDR2TERM1
				   (0x0               << 26)   |  // IBANK_POS
				   (0x0               << 24)   |  // DDRDRIVE1
				   (0x0               << 23)   |  // BOOTUNLOCK
				   (0x0               << 22)   |  // DDR2DDQS
				   (0x0               << 21)   |  // DDR2TERM0
				   (0x0               << 19)   |  // DDRDLL_DIS
				   (0x0               << 18)   |  // DDRDRIVE0
				   (0x1               << 17)   |  // DDREN
				   (0x1               << 16)   |  // SDRAMEN
				   (0x1               << 15)   |  // TIMUNLOCK
				   (0x1               << 14)   |  // NM
				   (0x0               << 12)   |  // Reserved
				   (0x3               << 9)    |  // CL
				   (0x0               << 7)    |  // Reserved
				   (0x3               << 4)    |  // IBANK
				   (0x0               << 3)    |  // Reserved
				   (0x2               << 0);      // PAGESIZE

    EMIFDDR_SDCR2   = 0x00000000; // IBANK_POS set to 0 so this register does not apply

    if( DDR_DEBUG ) {
      // Configure EMIF with max timings for more slack
      // Try this if memory is not stable

      EMIFDDR_SDTIMR1 = (0x7F << 25)             |  // tRFC
                        (0x07 << 22)             |  // tRP
                        (0x07 << 19)             |  // tRCD
                        (0x07 << 16)             |  // tWR
                        (0x1F << 11)             |  // tRAS
                        (0x1F << 6)              |  // tRC
                        (0x07 << 3)              |  // tRRD
                        (EMIFDDR_SDTIMR1 & 0x4)  |  // Reserved
                        (0x03 << 0);                // tWTR

      EMIFDDR_SDTIMR2 = (EMIFDDR_SDTIMR2 & 0x80000000)                       |  // Reserved
                        (((unsigned int) ((70000 / 3400) - 0.5))  << 27)   |  // tRASMAX (original 7812.5)
                        (0x3                                        << 25)   |  // tXP
                        (0x0                                        << 23)   |  // tODT (Not supported)
                        (0x7F                                       << 16)   |  // tXSNR
                        (0xFF                                       << 8)    |  // tXSRD
                        (0x07                                       << 5)    |  // tRTP (1 Cycle)
                        (0x1F                                       << 0);      // tCKE

      printf("\tDDR Timings Configured for Debug\n","Output",1,1,1);
    }
    else {
      // Let float -> integer truncate handle minus 1; Safer to round up for timings
	  EMIFDDR_SDTIMR1 = (19                                      << 25)  |  // tRFC
						(1                                       << 22)  |  // tRP
						(1                                       << 19)  |  // tRCD
						(2                                       << 16)  |  // tWR
						(5                                       << 11)  |  // tRAS
						(8                                       <<  6)  |  // tRC
						(1                                       <<  3)  |  // tRRD
						(0                                       <<  2)  |  // Reserved
						(1                                       <<  0);    // tWTR

	  EMIFDDR_SDTIMR2 = (EMIFDDR_SDTIMR2 & 0x80000000)                   |  // Reserved
						(8                                       << 27)  |  // tRASMAX
						(2                                       << 25)  |  // tXP
						(0                                       << 23)  |  // tODT (Not supported)
						(18                                      << 16)  |  // tXSNR (tXSR for mDDR)
						(199                                     << 8)   |  // tXSRD (tXSR for mDDR)
						(1                                       << 5)   |  // tRTP
						(2                                       << 0);     // tCKE
    }

    EMIFDDR_SDCR    &= ~0x00008000; // Clear TIMUNLOCK

    // Let float -> integer truncate handle RR round-down; Safer to round down for refresh rate
    EMIFDDR_SDRCR   = (0x1                                  << 31)  |  // LPMODEN (Required for LPSC SyncReset/Enable)
                      (0x1                                  << 30)  |  // MCLKSTOPEN (Required for LPSC SyncReset/Enable)
                      (0x0                                  << 24)  |  // Reserved
                      (0x0                                  << 23)  |  // SR_PD
                      (0x0                                  << 16)  |  // Reserved
                      (0x260                                << 0);     // RR

    // SyncReset the Clock to EMIFDDR SDRAM
    PSC1_LPSC_SyncReset(PD0, LPSC_DDR);

    // Enable the Clock to EMIFDDR SDRAM
    PSC1_LPSC_enable(PD0, LPSC_DDR);

    // Disable self-refresh
    EMIFDDR_SDRCR &= ~0xC0000000;

    EMIFDDR_PBBPR = 0x10;
}


/****************************************************************************
	PSC inits
****************************************************************************/

void Wake_DSP()
{
	//spruh77c
	//13.2 DSP Wake up
	//
	KICK0R = 0x83e70b13;
	KICK1R = 0x95a4f1e0;
    // Entry point
	HOST1CFG = 0x11800000;
	//
    PSC0_LPSC_enableCore(1, LPSC_DSP);

}

void Wake_PRU()
{
    PSC0_LPSC_enableCore(0, LPSC_PRU);

}

void Set_Core_456MHz() {
    device_PLL0(0,18,0,0,1,3,9);
}

void Set_DDRPLL_156MHz() {
    device_PLL1(12,0,0,1,2);
}

void Set_DDR2_156MHz() {
    Set_DDRPLL_156MHz();
    DEVICE_DDRConfig();
}

void Core_456MHz_DDR2_156MHz() {
    Set_Core_456MHz();
    Set_DDR2_156MHz();
}

void PSC_All_On() {
    // PSC0
    PSC0_LPSC_enable(0, LPSC_EDMA_CC0);
    PSC0_LPSC_enable(0, LPSC_EDMA_TC0);
    PSC0_LPSC_enable(0, LPSC_EDMA_TC1);
    PSC0_LPSC_enable(0, LPSC_EMIFA);
    PSC0_LPSC_enable(0, LPSC_SPI0);
    PSC0_LPSC_enable(0, LPSC_MMCSD0);
    PSC0_LPSC_enable(0, LPSC_ARM_AINTC);
    PSC0_LPSC_enable(0, LPSC_ARM_RAMROM);
    PSC0_LPSC_enable(0, LPSC_UART0);
    PSC0_LPSC_enable(0, LPSC_SCR0);
    PSC0_LPSC_enable(0, LPSC_SCR1);
    PSC0_LPSC_enable(0, LPSC_SCR2);

    // PSC1
    PSC1_LPSC_enable(0, LPSC_EDMA_CC1);
    PSC1_LPSC_enable(0, LPSC_USB20);
    PSC1_LPSC_enable(0, LPSC_USB11);
    CFGCHIP2 = 0x09F2;                 //Enable USB clock, PHY_PLLON, glue logic mux(USB2 ref clk input)
    PSC1_LPSC_enable(0, LPSC_GPIO);
    PSC1_LPSC_enable(0, LPSC_UHPI);
    PSC1_LPSC_enable(0, LPSC_EMAC);
    PSC1_LPSC_enable(0, LPSC_MCASP0);
    PSC1_LPSC_force(LPSC_SATA);
    PSC1_LPSC_enable(0, LPSC_SATA);
    PSC1_LPSC_enable(0, LPSC_VPIF);
    PSC1_LPSC_enable(0, LPSC_SPI1);
    PSC1_LPSC_enable(0, LPSC_I2C1);
    PSC1_LPSC_enable(0, LPSC_UART1);
    PSC1_LPSC_enable(0, LPSC_UART2);
    PSC1_LPSC_enable(0, LPSC_MCBSP0);
    PSC1_LPSC_enable(0, LPSC_MCBSP1);
    PSC1_LPSC_enable(0, LPSC_LCDC);
    PSC1_LPSC_enable(0, LPSC_EPWM);
    PSC1_LPSC_enable(0, LPSC_MMCSD1);
    PSC1_LPSC_enable(0, LPSC_UPP);
    PSC1_LPSC_enable(0, LPSC_ECAP);
    PSC1_LPSC_enable(0, LPSC_EDMA_TC2);
    PSC1_LPSC_enable(0, LPSC_SCR_F0);
    PSC1_LPSC_enable(0, LPSC_SCR_F1);
    PSC1_LPSC_enable(0, LPSC_SCR_F2);
    PSC1_LPSC_enable(0, LPSC_SCR_F6);
    PSC1_LPSC_enable(0, LPSC_SCR_F7);
    PSC1_LPSC_enable(0, LPSC_SCR_F8);
    PSC1_LPSC_enable(0, LPSC_BR_F7);
    PSC1_LPSC_enable(0, LPSC_SHARED_RAM);

}

void CPU_PLL_PSC_DDR_Init()
{

    PSC_All_On();
    Core_456MHz_DDR2_156MHz();

    Wake_DSP();
	Wake_PRU();
}






#endif /* SYS_INIT_H_ */
