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

typedef enum WheelSet
{
    FRONT = 0,
    BACK = 2
}WheelSet;

typedef enum Direction
{
    FORWARD,
    BACKWARD,
    STOP
} Direction;

extern const Wheel WHEELS[];

/*
 * Sets the WheelSet to move in mode specified by direction
 */
void setDirection(const WheelSet wheelSet, const Direction direction);

/*
 * Sets the Wheel to move in mode specified by direction
 */
void setDirectionForWheel(const Wheel wheel, const Direction direction);

/*
 * Sets the pwmPort to have the duty cycle passed in.
 */
void setWheelDutyCycle(const uint32_t pwmPort, const uint32_t duty);
#endif
