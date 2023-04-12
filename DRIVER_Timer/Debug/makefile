################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DRIVER_Timer.lss \

FLASH_IMAGE += \
DRIVER_Timer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DRIVER_Timer.elf secondary-outputs

# Tool invocations
DRIVER_Timer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DRIVER_Timer.map -mmcu=atmega32 -o "DRIVER_Timer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DRIVER_Timer.lss: DRIVER_Timer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DRIVER_Timer.elf  >"DRIVER_Timer.lss"
	@echo 'Finished building: $@'
	@echo ' '

DRIVER_Timer.hex: DRIVER_Timer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DRIVER_Timer.elf  "DRIVER_Timer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DRIVER_Timer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DRIVER_Timer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DRIVER_Timer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
