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
Timer_0_CompareMatch.lss \

FLASH_IMAGE += \
Timer_0_CompareMatch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer_0_CompareMatch.elf secondary-outputs

# Tool invocations
Timer_0_CompareMatch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer_0_CompareMatch.map -mmcu=atmega32 -o "Timer_0_CompareMatch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer_0_CompareMatch.lss: Timer_0_CompareMatch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer_0_CompareMatch.elf  >"Timer_0_CompareMatch.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer_0_CompareMatch.hex: Timer_0_CompareMatch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer_0_CompareMatch.elf  "Timer_0_CompareMatch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer_0_CompareMatch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer_0_CompareMatch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer_0_CompareMatch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
