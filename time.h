#pragma once

class Time {
    public:
        int h; //hours
        int m; //minutes
};

void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);