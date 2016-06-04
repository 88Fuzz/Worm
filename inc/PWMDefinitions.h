#ifndef __PWMCONSTANTS_H__
#define __PWMCONSTANTS_H__

#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"

#include <stdint.h>

#define PWM_BASE PWM0_BASE

//The PWM_FREQUENCY assume a clock speed of 3.2 MHz
#define PWM_FREQUENCY 64000
#define ONE_EIGHTY_DEGREES (PWM_FREQUENCY/10)
#define ZERO_DEGREES (PWM_FREQUENCY/20)
#define NINETY_DEGREES (PWM_FREQUENCY*3/4)

typedef struct PWMInfo 
{
    uint32_t gpioConfig;
    uint32_t gpioPin;
    uint32_t pwmOutPortBit;
    uint32_t pwmOutPort;
} PWMInfo;

#endif
