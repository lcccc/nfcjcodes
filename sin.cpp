#include "windows.h"
#include "stdlib.h"
#include "math.h"

const double split = 0.01;
const int count = 200;
const double pi = 3.14159265;
const int interval = 300;

int main()
{
    DWORD busySpan[count];
    DWORD idleSpan[count];
    int half = interval / 2;
    double radian = 0.0;
    for(int i = 0; i < count; i++)
    {
        busySpan[i] = (DWORD)(half + (sin(pi*radian)*half));
        idleSpan[i] = interval - busySpan[i];
        radian += split;
    }
    DWORD startTime = 0;
    int j =  0 ;
    while ( true )
    {
        j = j % count;
        startTime = GetTickCount();
        while((GetTickCount()- startTime) <= busySpan[j]);
        Sleep(idleSpan[j]);
        j++;
    }
    return 0;
    }

