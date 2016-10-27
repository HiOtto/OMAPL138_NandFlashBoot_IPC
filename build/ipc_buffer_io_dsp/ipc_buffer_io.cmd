// ============================================================================
/* 
 * Linker Command File for Linking C6748 DSP Programs
 *
 * These linker options are for command line linking only. For IDE linking,
 * you should set your linker options in Project Properties.
 * 		-c					Link Using C Conventions
 *		-stack 	0x1000		Software Stack Size
 *		-heap	0x1000		Heap Area Size
*/
// ===========================================================================
-stack 0x1000
-heap 0x1000

// ============================================================================
// 						Specify the System Memory Map
// ============================================================================
#define	IPC_ARM_START			0x80000000
#define	IPC_ARM_SIZE			0x10
#define	IPC_DSP_START			IPC_ARM_START + IPC_ARM_SIZE
#define	IPC_DSP_SIZE			0x10
#define	SHARED_IRAM_START		IPC_ARM_START + IPC_ARM_SIZE + IPC_DSP_SIZE
#define SHARED_IRAM_SIZE		0x1FFFF - (IPC_ARM_SIZE + IPC_DSP_SIZE)

MEMORY
{
	L1P:	o = 0x11E00000		l = 0x00008000
	L1D:	o = 0x11F00000		l = 0x00008000
	L2:		o = 0x11800000		l = 0x00040000
	DDR2:	o = 0xC4000000		l = 0x04000000		/* 32MB of DDR2		*/		
	IPC_ARM: o = IPC_ARM_START	l = IPC_ARM_SIZE	/* 16 bytes for ARM */
	IPC_DSP: o = IPC_DSP_START	l = IPC_DSP_SIZE	/* 16 bytes for DSP */
	shared_ram: o = SHARED_IRAM_START  l = SHARED_IRAM_SIZE		/* Remaining IntRAM	*/
	
}

// ============================================================================
// 				Specify the Sections Allocation into Memory
// ============================================================================
SECTIONS
{
	my_boot_sect   >  L2

	GROUP (NEAR_DP_RELATIVE)
	{
	    .neardata
	    .rodata
	    .bss
	} > DDR2

	.cinit		>		DDR2				// Initialization Tables
	.pinit		>		DDR2				// Constructor Tables
    .init_array	>		DDR2
	.const		>		DDR2				// Constant Data
	.switch		>		DDR2				// Jump Tables
	.text		>		DDR2				// Executable Code
	.text:_c_int00: align=1024 > DDR2		// Entrypoint
	
	.far		>		DDR2				// Far Global & Static Variables
	.fardata	>		DDR2
	.stack		>		DDR2				// Software System Stack
	.sysmem		>		DDR2				// Dynamic Memory Allocation Area
	
	.cio		>		DDR2				// C I/O Buffer
	.vecs		>		DDR2				// Interrupt Vectors
	ipc_arm		> 		IPC_ARM
	ipc_dsp		> 		IPC_DSP
}
