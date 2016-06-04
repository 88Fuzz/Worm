#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

#include "Initialize.h"

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
    GPIOPinConfigure(GPIO_PB6_M0PWM0|GPIO_PB7_M0PWM1|GPIO_PB4_M0PWM2|GPIO_PB5_M0PWM3);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_4|GPIO_PIN_2);

    //Set the PWM0 run modes, since the motors will act on up ticks, these values don't matter too much
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    //Turn on PWM0
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT|PWM_OUT_1_BIT|PWM_OUT_2_BIT|PWM_OUT_3_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
}
