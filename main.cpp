#include <iostream>
#include "watch.h"

using namespace std;

int main() {
	Stopwatch sw = Stopwatch();

	sw.start();
	//system("pause");
	sw.stop();

	std::cout << "elapsed: " << sw.getElapsed() << std::endl;
	std::cout << "day: " << sw.getDay() << std::endl;
	std::cout << "hour: " << sw.getHour() << std::endl;
	std::cout << "minute: " << sw.getMinute() << std::endl;
	std::cout << "second: " << sw.getSecond() << std::endl;
	std::cout << "millisecond: " << sw.getMillisecond() << std::endl;

	return 0;
}
