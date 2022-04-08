#include <iostream>
#include <cmath>
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

void printTime(Time time) {
    if (time.h < 10)
        std::cout << "0" << time.h << ":" << time.m;
    else if (time.m < 10) 
        std::cout << time.h << ":" << "0" << time.m;
    else
        std::cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time) {
    return (time.h * 60) + time.m;
}

int minutesUntil (Time earlier, Time later) {
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min) {
    Time time;
    if(time0.m + min >= 60){
        time.h = time0.h + ((time0.m + min)/60);
        time.m = (time0.m + min) % 60;
    }
    else
        time.m = time0.m + min;
    
    return time;
}

std::string printMovie(Movie mv) {
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title;
}

std::string getTimeSlot(TimeSlot ts){
    std::string movie = printMovie(ts.movie);
    std::string time = "[Starts at" + return printTime(ts.startTime) + ", ends by" + printTime(addMinutes(ts.startTime, ts.movie.duration)) + "]";
    return movie + time;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot newSlot;
    newSlot.movie = nextMovie;
    newSlot.startTime = endTime;

    return newSlot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    Time slot1 = ts1.startTime, slot2 = ts2.startTime;
    int duration1 = ts1.movie.duration, duration2 = ts2.movie.duration, min = minutesUntil(slot1, slot2);
    if (min > 0)
    {
        if (min < duration1){
            return true;
        }
    }
    else if (abs(min) < duration2) {
        return true;
    }
    return false;
}