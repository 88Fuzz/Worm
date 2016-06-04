#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

#include "Initialize.h"
#include "PWMDefinitions.h"
#include "Wheels.h"

void init()
{
    initClock();
    initPWM();
}

void initClock()
{
    //Set the clock speed to 3.2MHz
    SysCtlClockSet(SYSCTL_SYSDIV_6|SYSCTL_USE_OSC|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
}

void initPWM()
{
    //Enable PWM0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    //Enable ports 0-4 of PWM0
    GPIOPinConfigure(WHEELS[0].pwmInfo.gpioConfig |
            WHEELS[1].pwmInfo.gpioConfig |
            WHEELS[2].pwmInfo.gpioConfig |
            WHEELS[3].pwmInfo.gpioConfig);
    GPIOPinTypePWM(GPIO_PORTB_BASE, WHEELS[0].pwmInfo.gpioPin |
            WHEELS[1].pwmInfo.gpioPin |
            WHEELS[2].pwmInfo.gpioPin |
            WHEELS[3].pwmInfo.gpioPin);

    //Set the PWM0 run modes, since the motors will act on up ticks, these values don't matter too much
    PWMGenConfigure(PWM_BASE, WHEELS[0].pwmInfo.pwmOutPortBit |
            WHEELS[1].pwmInfo.pwmOutPortBit |
            WHEELS[2].pwmInfo.pwmOutPortBit |
            WHEELS[3].pwmInfo.pwmOutPortBit,
            PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    //Turn on PWM0
    PWMOutputState(PWM_BASE, PWM_OUT_0_BIT|PWM_OUT_1_BIT|PWM_OUT_2_BIT|PWM_OUT_3_BIT, true);
    PWMGenEnable(PWM_BASE, PWM_GEN_0);

    //Set all the PWM frequencies to 50Hz
    PWMGenPeriodSet(PWM_BASE, WHEELS[0].pwmInfo.pwmOutPort |
            WHEELS[1].pwmInfo.pwmOutPort |
            WHEELS[2].pwmInfo.pwmOutPort |
            WHEELS[3].pwmInfo.pwmOutPort, PWM_FREQUENCY);
}
