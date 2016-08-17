#include "Timer.h"
#include <cmath>

void Timer::start() {
	this->begin = std::chrono::system_clock::now();
}

double Timer::currTime() {
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapse = end - this->begin;
	std::ostringstream ss;
	ss << elapse.count();
	std::string timeStr = ss.str();
	return std::stod(timeStr);
}
