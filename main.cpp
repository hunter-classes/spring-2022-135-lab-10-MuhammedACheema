#include <iostream>
#include "time.h"
#include "timeslot.h"
#include "movie.h"

int main(){
    
    //TASK A
    std::cout << "Task A: minutes since midnight" << std::endl;
    Time t = {14, 50};
    std::cout << "It has been " << minutesSinceMidnight(t) << " since midnight" << std::endl;

    //TASK A
    std::cout << "Task A: minutes until" << std::endl;
    Time earlier = {10, 30}; 
    Time later = {13, 40}; 
    std::cout << "The interval between the two times are " <<  minutesUntil(earlier,later) << std::endl; 

    //TASK B
    std::cout << "Task B: add minutes" << std::endl;
    Time addMin = {8,10}; 
    addMin = addMinutes(addMin, 75); 
    std::cout << "After 75 minutes, your new time is: "; 
    printTime(addMin); 

    //TASK C
    std::cout << "Task C: get time slot" << std::endl;
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 

    std::string morn = getTimeSlot(morning); 
    std::cout << morn << std::endl;
    std::string day = getTimeSlot(daytime); 
    std::cout << day << std::endl;

    std::string even = getTimeSlot(evening); 
    std::cout << even << std::endl;

    //TASK D 
    std::cout << "Task D: schedule after" << std::endl;
    Movie jumanji = {"Jumanji", ACTION, 104};
    Movie theory = {"The Theory of Everything", ROMANCE, 123};

    TimeSlot tslot1 = {jumanji, {13, 20}}; 
    TimeSlot tslot2;
    tslot2 = scheduleAfter(tslot1, theory); 
    std::cout << "Next movie scheduled after: " << getTimeSlot(tslot2) << std::endl; 

    //task E 
    std::cout << "Task E: overlapping time slots" << std::endl;
    Movie moana = {"Moana", DRAMA, 120};
    Movie tiana = {"The Princess and the Frog", ROMANCE, 160};
    TimeSlot mo = {moana, {20, 30}}; 
    TimeSlot ti = {tiana, {21, 45}}; 
    bool test = timeOverlap(mo, ti); 
    if (test) { 
        std::cout << "true" << std::endl; 
    }
    else { 
        std::cout << "false" << std::endl; 
    }

    Movie eternals = {"Eternals", ACTION, 100};
    Movie venom = {"Venom", ACTION, 120};
    TimeSlot eter = {eternals, {3, 18}}; 
    TimeSlot ven = {venom, {5, 58}}; 
    bool testing = timeOverlap(eter, ven); 
    if (testing) { 
        std::cout << "true" << std::endl; 
    }
    else { 
        std::cout << "false" << std::endl; 
    }


return 0;
}