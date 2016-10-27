IPC Examples Readme
===================
Notify via polling 

Description: 
=======

This example demonstrates the use of IPC to send data buffers back and forth
between the ARM and DSP cores.  First, the DSP side program will send a buffer
containing the string "Hello from DSP\n" to the ARM. The ARM side program will
print it to the UART console and then use the same buffer to send the string
"Hello from ARM" back to the DSP.

Set up for OMAP-L138 EVM development:
--------------------------------------------------
ARM side debug messages are printed via serial console so the UART port of the
EVM needs to be connected to the PC running a serial console application. The
DSP side messages are printed to the CCS console I/O (CIO). You can modify the
app so that both messages can be printed to the serial console, but the listing
could get garbled if not intermingled.
                
How to run the example in CCSv5
---------------------------------------------
1. Load and run the arm image on arm debugger first.
   
2. Load and run the dsp image on the dsp:
  
3. Communication start to go around in circles (dsp->arm->dsp->arm->dsp...)

Note: arm must be run first because it initializes the shared structures.  It
      also must be ran because arm must reach main() before dsp can be loaded
      and run.

Expected output
---------------------
UART serial console:
Hello from DSP

CCSv5 CIO console:
Hello from ARM
