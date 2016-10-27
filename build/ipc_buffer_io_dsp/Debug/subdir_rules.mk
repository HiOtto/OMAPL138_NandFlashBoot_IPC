################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main_dsp.obj: C:/ti/OMAPL138_StarterWare_1_10_04_01/examples/evmOMAPL138/ipc_buffer_io/main_dsp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g --define=omapl138 --include_path="C:/ti/ccsv5/tools/compiler/c6000_7.4.4/include" --include_path="../../../../../../../include" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include/c674x" --include_path="../../../../../../../include/c674x/omapl138" --include_path="../../../../../../../grlib/include" --include_path="../../../../../../../usblib/include" --include_path="../../../../../../../ipclite/include" --include_path="../../../../../../../nandlib/include" --diag_warning=225 --abi=eabi --preproc_with_compile --preproc_dependency="main_dsp.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myboot.obj: ../myboot.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g --define=omapl138 --include_path="C:/ti/ccsv5/tools/compiler/c6000_7.4.4/include" --include_path="../../../../../../../include" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include/c674x" --include_path="../../../../../../../include/c674x/omapl138" --include_path="../../../../../../../grlib/include" --include_path="../../../../../../../usblib/include" --include_path="../../../../../../../ipclite/include" --include_path="../../../../../../../nandlib/include" --diag_warning=225 --abi=eabi --preproc_with_compile --preproc_dependency="myboot.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


