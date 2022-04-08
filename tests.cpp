#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include <iostream>

TEST_CASE("Task A: minutesSinceMidnight") {
    CHECK(minutesSinceMidnight({4, 10}) == 250);
	CHECK(minutesSinceMidnight({15, 24}) == 924);
	CHECK(minutesSinceMidnight({6, 5}) == 365);
}

TEST_CASE("Task A: minutesUntil"){
    CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
	CHECK(minutesUntil({2, 25}, {3, 45}) == 80);
	CHECK(minutesUntil({2, 0}, {4, 0}) == 120);
}

TEST_CASE("Task B") {
    Time t1;
    t1.h = 9;
    t1.m = 45;
    Time t2;
    t2.h = 2;
    t2.m = 25;
    CHECK(printTime(addMinutes(t1, 30)) == "10:15");
    CHECK(printTime(addMinutes(t2, 20)) == "2:45");

}

TEST_CASE("task C") {

    Movie avatar = {"Avatar", ACTION, 220};
    TimeSlot morn = {avatar, {8, 15}}; 

    std::string a = getTimeSlot(morn); 
    CHECK(a == "Avatar ACTION (220 min) [starts at 8:15, ends by 11:55]");

    Movie nemo = {"Finding Nemo", DRAMA, 160};
    TimeSlot daytime = {nemo, {12, 02}}; 
    std::string b = getTimeSlot(daytime);
    
    CHECK(b == "Finding Nemo DRAMA (160 min) [starts at 12:02, ends by 14:42]");

    Movie naruto = {"Naruto", COMEDY, 90};
    TimeSlot evening = {naruto, {16, 05}}; 
    std::string c = getTimeSlot(evening);
    
    CHECK(c == "Naruto COMEDY (90 min) [starts at 16:05, ends by 17:35]");

}

TEST_CASE("task D") {

    Movie movie1 = {"Fatherhood", DRAMA, 220};
    Movie movie2 = {"Adrift", ACTION, 160};

    TimeSlot morning = {movie1, {8, 15}}; 
    Time endTime = addMinutes(morning.startTime, movie1.duration); 

    TimeSlot next = scheduleAfter(morning, movie2);
    std::string s = getTimeSlot(next);
    CHECK(s == "Adrift ACTION (160 min) [starts at 11:55, ends by 14:35]");
}

TEST_CASE("task E") { 

    Movie movie1 = {"Cloudy with a Chance of Meatballs", COMEDY, 220};
    Movie movie2 = {"Cloudy with a Chance of Meatballs 2", COMEDY, 100};
    TimeSlot time1 = {movie1, {9, 25}}; 
    TimeSlot time2 = {movie2, {9, 30}}; 
    CHECK(timeOverlap(time1, time2) == true); 

}
