#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

#define FIFTY_HZ 64000
#define ONE_EIGHTY_DEGREES (FIFTY_HZ/10)
#define ZERO_DEGREES (FIFTY_HZ/20)
#define NINETY_DEGREES (FIFTY_HZ*3/4)

int main()
{
    //Set the clock speed to 3.2MHz
    SysCtlClockSet(SYSCTL_SYSDIV_6|SYSCTL_USE_OSC|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinConfigure(GPIO_PB6_M0PWM0);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);

    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, FIFTY_HZ);
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ONE_EIGHTY_DEGREES);
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ZERO_DEGREES);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, NINETY_DEGREES);
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);

    while(1);

    return 1;
}
