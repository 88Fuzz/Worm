#ifndef __INITIALIZE_H__
#define __INITIALIZE_H__

/*
 * Initializes the system clock and PWM module.
 */
void init();

/*
 * Initializes the system clock to 3.2 MHz.
 */
void initClock();

/*
 * Initializes the PWM0 base with port 0, 1, 2, and 3 ready to be controlled.
 */
void initPWM();
#endif
