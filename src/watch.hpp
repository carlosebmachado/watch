#ifndef WATCH_H
#define WATCH_H

#include <time.h>

#define MILLISECOND 1
#define SECOND (1000 * MILLISECOND)
#define MINUTE (60 * SECOND)
#define HOUR (60 * MINUTE)
#define DAY (24 * HOUR)


// Stopwatch class.
class Stopwatch
{
private:
	clock_t elapsed;
	clock_t startTime;

public:
	Stopwatch()
	{
		elapsed = 0;
		startTime = 0;
	}

	~Stopwatch() {}

public:
	void start()
	{
		startTime = clock();
	}

	void stop()
	{
		elapsed = clock() - startTime;
	}

	void reset()
	{
		elapsed = 0;
		startTime = 0;
	}

	void restart()
	{
		reset();
		start();
	}

public:
	clock_t getElapsed()
	{
		return elapsed;
	}

	clock_t getElapsedDay()
	{
		return elapsed / DAY;
	}

	clock_t getElapsedHour()
	{
		clock_t auxElapsed = elapsed;
		auxElapsed = auxElapsed % DAY;
		return auxElapsed / HOUR;
	}

	clock_t getElapsedMinute()
	{
		clock_t auxElapsed = elapsed;
		auxElapsed = auxElapsed % DAY;
		auxElapsed = auxElapsed % HOUR;
		return auxElapsed / MINUTE;
	}

	clock_t getElapsedSecond()
	{
		clock_t auxElapsed = elapsed;
		auxElapsed = auxElapsed % DAY;
		auxElapsed = auxElapsed % HOUR;
		auxElapsed = auxElapsed % MINUTE;
		return auxElapsed / SECOND;
	}

	clock_t getElapsedMillisecond()
	{
		clock_t auxElapsed = elapsed;
		auxElapsed = auxElapsed % DAY;
		auxElapsed = auxElapsed % HOUR;
		auxElapsed = auxElapsed % MINUTE;
		auxElapsed = auxElapsed % SECOND;
		return auxElapsed;
	}
};


// Timer class.
class Timer
{
private:
	clock_t startTime;
	clock_t interval;

public:
	Timer()
	{
		startTime = 0;
		interval = 0;
	}

	Timer(clock_t interval)
	{
		startTime = 0;
		this->interval = interval;
	}

	~Timer() {}

public:
	void start()
	{
		startTime = clock();
	}

	bool timeout()
	{
		if (clock() - startTime > interval)
		{
			startTime = clock();
			return true;
		}
		return false;
	}

public:
	void setInterval(clock_t interval)
	{
		this->interval = interval;
	}

	clock_t getInterval()
	{
		return interval;
	}
};

#endif // WATCH_H
