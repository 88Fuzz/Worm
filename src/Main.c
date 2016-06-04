#include "driverlib/pwm.h"
#include "inc/hw_memmap.h"
#include "Initialize.h"

#define FIFTY_HZ 64000
#define ONE_EIGHTY_DEGREES (FIFTY_HZ/10)
#define ZERO_DEGREES (FIFTY_HZ/20)
#define NINETY_DEGREES (FIFTY_HZ*3/4)

int main()
{
    init();

    
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, FIFTY_HZ);
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ONE_EIGHTY_DEGREES);
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ZERO_DEGREES);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, NINETY_DEGREES);

    while(1);

    return 1;
}
