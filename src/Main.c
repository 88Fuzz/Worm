#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"

#include "Initialize.h"
#include "PWMDefinitions.h"
#include "Wheels.h"

void wait();

int main()
{
    init();
    
    while(1)
    {
        wait();
        PWMPulseWidthSet(PWM0_BASE, WHEELS[0].pwmInfo.pwmOutPort, WHEELS[0].forwardDuty);
        wait();
        PWMPulseWidthSet(PWM0_BASE, WHEELS[0].pwmInfo.pwmOutPort, WHEELS[0].backwardDuty);
        wait();
        PWMPulseWidthSet(PWM0_BASE, WHEELS[0].pwmInfo.pwmOutPort, WHEELS[0].stopDuty);
    }

    return 1;
}

void wait()
{
    SysCtlDelay(SysCtlClockGet()/3);
}
