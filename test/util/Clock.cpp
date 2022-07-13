#include "Clock.h"

Clock* Clock::_instance;

Clock::Clock() {
	_startTimeMillis = _currentTimeInMilliseconds();
}

Clock& Clock::instance() {
	if (_instance == NULL) {
		_instance = new Clock();
	}
	return *_instance;
}

Clock::~Clock() {
	delete _instance;
}

void Clock::reset() {
	_startTimeMillis = _currentTimeInMilliseconds();
}

int64_t Clock::millis() {
	return _currentTimeInMilliseconds() - _startTimeMillis;
}

int64_t Clock::_currentTimeInMilliseconds() {
	auto timePoint = chrono::system_clock::now();
	return chrono::duration_cast<chrono::milliseconds>(timePoint.time_since_epoch()).count();
}