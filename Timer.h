// c++11
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#ifndef TIMER_H
#define TIMER_H
class Timer {
public:
	void start();	
	double currTime();
private:
	std::chrono::time_point<std::chrono::system_clock> begin;
};

#endif /* TIMER_H */
