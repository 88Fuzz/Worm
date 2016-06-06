#include "driverlib/pwm.h"
#include "inc/hw_memmap.h"

#include "Wheels.h"
#include "PWMDefinitions.h"

const Wheel WHEELS[] =
{
    //Front left wheel
    {{GPIO_PB6_M0PWM0, GPIO_PIN_6, PWM_OUT_0_BIT, PWM_GEN_0, PWM_OUT_0},
            ONE_EIGHTY_DEGREES, ZERO_DEGREES, NINETY_DEGREES},
    //Front right wheel
    {{GPIO_PB7_M0PWM1, GPIO_PIN_7, PWM_OUT_1_BIT, PWM_GEN_1, PWM_OUT_1}, 
           ZERO_DEGREES, ONE_EIGHTY_DEGREES, NINETY_DEGREES},
    //Back left wheel
    {{GPIO_PB4_M0PWM2, GPIO_PIN_4, PWM_OUT_2_BIT, PWM_GEN_2, PWM_OUT_2},
            ONE_EIGHTY_DEGREES, ZERO_DEGREES, NINETY_DEGREES},
    //Back right wheel
    {{GPIO_PB5_M0PWM3, GPIO_PIN_5, PWM_OUT_3_BIT, PWM_GEN_3, PWM_OUT_3},
           ZERO_DEGREES, ONE_EIGHTY_DEGREES, NINETY_DEGREES}
};

void setDirection(const WheelSet wheelSet, const Direction direction)
{
    setDirectionForWheel(WHEELS[wheelSet], direction);
    setDirectionForWheel(WHEELS[wheelSet + 1], direction);
}

void setDirectionForWheel(const Wheel wheel, const Direction direction)
{
    switch(direction)
    {
        case FORWARD:
            setWheelDutyCycle(wheel.pwmInfo.pwmOutPort, wheel.forwardDuty);
            break;
        case BACKWARD:
            setWheelDutyCycle(wheel.pwmInfo.pwmOutPort, wheel.backwardDuty);
            break;
        case STOP:
            setWheelDutyCycle(wheel.pwmInfo.pwmOutPort, wheel.stopDuty);
            break;
    }
}

void setWheelDutyCycle(const uint32_t pwmPort, const uint32_t duty)
{
    PWMPulseWidthSet(PWM0_BASE, pwmPort, duty);
}
