################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main_arm.obj: C:/ti/OMAPL138_StarterWare_1_10_04_01/examples/evmOMAPL138/ipc_buffer_io/main_arm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.1.1/bin/armcl" -mv5e -g --define=omapl138 --include_path="C:/ti/ccsv5/tools/compiler/arm_5.1.1/include" --include_path="../../../../../../../include" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include/armv5" --include_path="../../../../../../../include/armv5/omapl138" --include_path="../../../../../../../grlib/include" --include_path="../../../../../../../usblib/include" --include_path="../../../../../../../ipclite/include" --include_path="../../../../../../../nandlib/include" --diag_warning=225 -me --abi=eabi --code_state=32 --preproc_with_compile --preproc_dependency="main_arm.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


