#ifndef __WHEELS_H__
#define __WHEELS_H__

#include "PWMDefinitions.h"

#include <stdint.h>

#define NUMBER_OF_WHEELS 4
#define FRONT_LEFT 0
#define FRONT_RIGHT 1
#define BACK_LEFT 2
#define BACK_RIGHT 3

typedef struct Wheel
{
    PWMInfo pwmInfo;
    uint32_t forwardDuty;
    uint32_t backwardDuty;
    uint32_t stopDuty;
} Wheel;

extern const Wheel WHEELS[];

#endif
