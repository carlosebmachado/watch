#include "watch.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void stopwatch_test()
{
	auto sw = Stopwatch();
	sw.start();
	system("pause");
	sw.stop();

	cout << "elapsed: " << sw.getElapsed() << endl;
	cout << "time: " << sw.getElapsedFormated() << endl;

	sw.restart();
	system("pause");
	sw.stop();

	cout << "elapsed: " << sw.getElapsed() << endl;
	cout << "time: " << sw.getElapsedFormated() << endl;
}

void chrono_test()
{
	auto sw = ChronoStopwatch();
	sw.start();
	system("pause");
	sw.stop();

	cout << "elapsed: " << sw.getElapsed() << endl;
	cout << sw.getElapsedFormated() << endl;

	sw.restart();
	system("pause");
	sw.stop();

	cout << "elapsed: " << sw.getElapsed() << endl;
	cout << sw.getElapsedFormated() << endl;
}

void timer_test()
{
	auto sw = Stopwatch();

	auto timer1 = Timer();
	timer1.setInterval(10 * SECOND);

	sw.start();
	timer1.start();
	do {
		if (timer1.timeout()) {
			break;
		}
	} while (true);
	sw.stop();
	cout << "elapsed: " << sw.getElapsed() << endl;


	auto timer2 = Timer(15 * SECOND);

	sw.restart();
	timer2.start();
	do {
		if (timer2.timeout()) {
			break;
		}
	} while (true);
	sw.stop();
	cout << "elapsed: " << sw.getElapsed() << endl;
}

int main() {
	stopwatch_test();
	//chrono_test();
	//timer_test();
	return 0;
}
