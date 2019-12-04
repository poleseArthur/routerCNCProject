################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\projLibraries\bibl_buttons.cpp \
..\projLibraries\bibl_driver.cpp \
..\projLibraries\bibl_lcd.cpp \
..\projLibraries\bibl_serial.cpp 

LINK_OBJ += \
.\projLibraries\bibl_buttons.cpp.o \
.\projLibraries\bibl_driver.cpp.o \
.\projLibraries\bibl_lcd.cpp.o \
.\projLibraries\bibl_serial.cpp.o 

CPP_DEPS += \
.\projLibraries\bibl_buttons.cpp.d \
.\projLibraries\bibl_driver.cpp.d \
.\projLibraries\bibl_lcd.cpp.d \
.\projLibraries\bibl_serial.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
projLibraries\bibl_buttons.cpp.o: ..\projLibraries\bibl_buttons.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\variants\mega" -I"C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

projLibraries\bibl_driver.cpp.o: ..\projLibraries\bibl_driver.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\variants\mega" -I"C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

projLibraries\bibl_lcd.cpp.o: ..\projLibraries\bibl_lcd.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\variants\mega" -I"C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

projLibraries\bibl_serial.cpp.o: ..\projLibraries\bibl_serial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.1\variants\mega" -I"C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


