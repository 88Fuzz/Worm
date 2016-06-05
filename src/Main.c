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
        PWMPulseWidthSet(PWM0_BASE, WHEELS[1].pwmInfo.pwmOutPort, WHEELS[1].backwardDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[2].pwmInfo.pwmOutPort, WHEELS[2].forwardDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[3].pwmInfo.pwmOutPort, WHEELS[3].backwardDuty);

        wait();
        PWMPulseWidthSet(PWM0_BASE, WHEELS[0].pwmInfo.pwmOutPort, WHEELS[0].backwardDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[1].pwmInfo.pwmOutPort, WHEELS[1].forwardDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[2].pwmInfo.pwmOutPort, WHEELS[2].backwardDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[3].pwmInfo.pwmOutPort, WHEELS[3].forwardDuty);

        wait();
        PWMPulseWidthSet(PWM0_BASE, WHEELS[0].pwmInfo.pwmOutPort, WHEELS[0].stopDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[1].pwmInfo.pwmOutPort, WHEELS[1].stopDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[2].pwmInfo.pwmOutPort, WHEELS[2].stopDuty);
        PWMPulseWidthSet(PWM0_BASE, WHEELS[3].pwmInfo.pwmOutPort, WHEELS[3].stopDuty);
    }

    return 1;
}

void wait()
{
    SysCtlDelay(SysCtlClockGet()/3);
}
