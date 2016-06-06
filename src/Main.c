#include "driverlib/sysctl.h"

#include "Initialize.h"
#include "Wheels.h"

#define WAIT (SysCtlClockGet()/7)

void wait();

int main()
{
    init();
    
    while(1)
    {
        wait(WAIT);
        setDirection(FRONT, STOP);
        setDirection(BACK, FORWARD);

        wait(WAIT);
        setDirection(BACK, STOP);
        setDirection(FRONT, FORWARD);

        //wait();
        //setDirection(FRONT, STOP);
        //setDirection(BACK, STOP);
    }

    return 1;
}

void wait(uint32_t waitTime)
{
    SysCtlDelay(waitTime);
}
