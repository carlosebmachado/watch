#ifndef WATCH_H
#define WATCH_H

#include <time.h>

#define MILLISECOND 1
#define SECOND (1000 * MILLISECOND)
#define MINUTE (60 * SECOND)
#define HOUR (60 * MINUTE)
#define DAY (24 * HOUR)

class Stopwatch
{
private:
	clock_t elapsed;
	clock_t startTime;

public:
	Stopwatch();
	~Stopwatch();

public:
	void start();
	void stop();
	void reset();
	void restart();

public:
	clock_t getElapsed();
	clock_t getDay();
	clock_t getHour();
	clock_t getMinute();
	clock_t getSecond();
	clock_t getMillisecond();
};

class Timer
{
private:
	clock_t startTime;
	clock_t interval;

public:
	Timer();
	Timer(clock_t);
	~Timer();

public:
	void start();
	bool timeout();

public:
	void setInterval(clock_t);
	clock_t getInterval();
};


// Stopwatch
Stopwatch::Stopwatch()
{
	elapsed = 0;
	startTime = 0;
}

Stopwatch::~Stopwatch() {}

void Stopwatch::start()
{
	startTime = clock();
}

void Stopwatch::stop()
{
	elapsed = clock() - startTime;
}

void Stopwatch::reset()
{
	elapsed = 0;
	startTime = 0;
}

void Stopwatch::restart()
{
	reset();
	start();
}

clock_t Stopwatch::getElapsed()
{
	return elapsed;
}

clock_t Stopwatch::getDay()
{
	return elapsed / DAY;
}

clock_t Stopwatch::getHour()
{
	clock_t auxElapsed = elapsed;
	auxElapsed = auxElapsed % DAY;
	return auxElapsed / HOUR;
}

clock_t Stopwatch::getMinute()
{
	clock_t auxElapsed = elapsed;
	auxElapsed = auxElapsed % DAY;
	auxElapsed = auxElapsed % HOUR;
	return auxElapsed / MINUTE;
}

clock_t Stopwatch::getSecond()
{
	clock_t auxElapsed = elapsed;
	auxElapsed = auxElapsed % DAY;
	auxElapsed = auxElapsed % HOUR;
	auxElapsed = auxElapsed % MINUTE;
	return auxElapsed / SECOND;
}

clock_t Stopwatch::getMillisecond()
{
	clock_t auxElapsed = elapsed;
	auxElapsed = auxElapsed % DAY;
	auxElapsed = auxElapsed % HOUR;
	auxElapsed = auxElapsed % MINUTE;
	auxElapsed = auxElapsed % SECOND;
	return auxElapsed;
}

// Timer
Timer::Timer() {
	startTime = 0;
	interval = 0;
}

Timer::Timer(clock_t interval)
{
	startTime = 0;
	this->interval = interval;
}

Timer::~Timer() {}

void Timer::start()
{
	startTime = clock();
}

bool Timer::timeout()
{
	if (clock() - startTime > interval)
	{
		startTime = clock();
		return true;
	}
	return false;
}

void Timer::setInterval(clock_t interval) {
	this->interval = interval;
}

clock_t Timer::getInterval() {
	return interval;
}

#endif // WATCH_H
