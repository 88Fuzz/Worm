#include "driverlib/pwm.h"
#include "inc/hw_memmap.h"

#include "Initialize.h"
#include "PWMDefinitions.h"

int main()
{
    init();
    
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ONE_EIGHTY_DEGREES);
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ZERO_DEGREES);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, NINETY_DEGREES);

    while(1);

    return 1;
}
