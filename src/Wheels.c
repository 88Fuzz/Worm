#include "Wheels.h"
#include "PWMDefinitions.h"
#include "driverlib/pwm.h"

const Wheel WHEELS[] =
{
    //Front left wheel
    {{GPIO_PB6_M0PWM0, GPIO_PIN_6, PWM_OUT_0_BIT, PWM_GEN_0, PWM_OUT_0},
            ONE_EIGHTY_DEGREES, ZERO_DEGREES, NINETY_DEGREES},
    //Front right wheel
    {{GPIO_PB7_M0PWM1, GPIO_PIN_7, PWM_OUT_1_BIT, PWM_GEN_1, PWM_OUT_1}, 
            ONE_EIGHTY_DEGREES, ZERO_DEGREES, NINETY_DEGREES},
    //Back left wheel
    {{GPIO_PB4_M0PWM2, GPIO_PIN_4, PWM_OUT_2_BIT, PWM_GEN_2, PWM_OUT_2},
            ONE_EIGHTY_DEGREES, ZERO_DEGREES, NINETY_DEGREES},
    //Back right wheel
    {{GPIO_PB5_M0PWM3, GPIO_PIN_5, PWM_OUT_3_BIT, PWM_GEN_3, PWM_OUT_3},
            ONE_EIGHTY_DEGREES, ZERO_DEGREES, NINETY_DEGREES}
};
