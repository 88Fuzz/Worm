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
    GPIOPinConfigure(WHEELS[0].pwmInfo.gpioConfig);
    GPIOPinConfigure(WHEELS[1].pwmInfo.gpioConfig);
    GPIOPinConfigure(WHEELS[2].pwmInfo.gpioConfig);
    GPIOPinConfigure(WHEELS[3].pwmInfo.gpioConfig);
    //GPIOPinTypePWM(GPIO_PORTB_BASE, WHEELS[0].pwmInfo.gpioPin |
    //        WHEELS[1].pwmInfo.gpioPin |
    //        WHEELS[2].pwmInfo.gpioPin |
    //        WHEELS[3].pwmInfo.gpioPin);
    GPIOPinTypePWM(GPIO_PORTB_BASE, WHEELS[0].pwmInfo.gpioPin);
    GPIOPinTypePWM(GPIO_PORTB_BASE, WHEELS[1].pwmInfo.gpioPin);
    GPIOPinTypePWM(GPIO_PORTB_BASE, WHEELS[2].pwmInfo.gpioPin);
    GPIOPinTypePWM(GPIO_PORTB_BASE, WHEELS[3].pwmInfo.gpioPin);

    //Set the PWM0 run modes, since the motors will act on up ticks, these values don't matter too much
    //PWMGenConfigure(PWM_BASE, WHEELS[0].pwmInfo.pwmGenPort |
    //        WHEELS[1].pwmInfo.pwmGenPort |
    //        WHEELS[2].pwmInfo.pwmGenPort |
    //        WHEELS[3].pwmInfo.pwmGenPort,
    //        PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM_BASE, WHEELS[0].pwmInfo.pwmGenPort,
            PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM_BASE, WHEELS[1].pwmInfo.pwmGenPort,
            PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM_BASE, WHEELS[2].pwmInfo.pwmGenPort,
            PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM_BASE, WHEELS[3].pwmInfo.pwmGenPort,
            PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    //Set all the PWM frequencies to 50Hz
    //PWMGenPeriodSet(PWM_BASE, WHEELS[0].pwmInfo.pwmGenPort |
    //        WHEELS[1].pwmInfo.pwmGenPort |
    //        WHEELS[2].pwmInfo.pwmGenPort |
    //        WHEELS[3].pwmInfo.pwmGenPort, PWM_FREQUENCY);
    PWMGenPeriodSet(PWM_BASE, WHEELS[0].pwmInfo.pwmGenPort, PWM_FREQUENCY);
    PWMGenPeriodSet(PWM_BASE, WHEELS[1].pwmInfo.pwmGenPort, PWM_FREQUENCY);
    PWMGenPeriodSet(PWM_BASE, WHEELS[2].pwmInfo.pwmGenPort, PWM_FREQUENCY);
    PWMGenPeriodSet(PWM_BASE, WHEELS[3].pwmInfo.pwmGenPort, PWM_FREQUENCY);

    //Turn on PWM0
    //PWMOutputState(PWM_BASE, WHEELS[0].pwmInfo.pwmOutPortBit |
    //        WHEELS[1].pwmInfo.pwmOutPortBit |
    //        WHEELS[2].pwmInfo.pwmOutPortBit |
    //        WHEELS[3].pwmInfo.pwmOutPortBit, true);
    PWMOutputState(PWM_BASE, WHEELS[0].pwmInfo.pwmOutPortBit, true);
    PWMOutputState(PWM_BASE, WHEELS[1].pwmInfo.pwmOutPortBit, true);
    PWMOutputState(PWM_BASE, WHEELS[2].pwmInfo.pwmOutPortBit, true);
    PWMOutputState(PWM_BASE, WHEELS[3].pwmInfo.pwmOutPortBit, true);

    //PWMGenEnable(PWM_BASE, WHEELS[0].pwmInfo.pwmGenPort |
    //        WHEELS[1].pwmInfo.pwmGenPort |
    //        WHEELS[2].pwmInfo.pwmGenPort |
    //        WHEELS[3].pwmInfo.pwmGenPort);
    PWMGenEnable(PWM_BASE, WHEELS[0].pwmInfo.pwmGenPort);
    PWMGenEnable(PWM_BASE, WHEELS[1].pwmInfo.pwmGenPort);
    PWMGenEnable(PWM_BASE, WHEELS[2].pwmInfo.pwmGenPort);
    PWMGenEnable(PWM_BASE, WHEELS[3].pwmInfo.pwmGenPort);
}
