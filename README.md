# Watch

## Description
Watch is a one file little library C++ that provides an easy interface for time control. The available functionalities are time measurement and timer.

## Usage

### Installing
The installation is easy, just download the latest release and put the watch.h file in your project.

### Getting Started
#### Measuring Time
To time measurement there are two classes that will provide the necessary functions. The Stopwatch class will be a millisecond precision and the ChronoStopwatch will be a nanosecond precision.

If you do not need a so precision measurement, you can use the Stopwatch class.
```cpp
void foo()
{
    Stopwach sw;
    sw.start();
    // The code to be measured
    sw.stop();
    std::cout << "Elapsed time in milliseconds: " << sw.getElapsed();
    std::cout << "Elapsed time formatted: " << sw.getElapsedFormatted();
    sw.restart();
    // More code
    sw.stop();
}
```
By the time you use ```sw.stop()``` the ```sw``` will calculate the elapsed time. The function ```sw.getElapsed();``` will return the raw millisecond precision time and ```sw.getElapsedFormatted();``` will return a string on format ```0d 0h 0m 0s 0mil```. If you do not will need more that value you can reuse the ```sw``` by using ```sw.restart();``` function.

Now if you need more precision, you should use the ChronoStopwatch class.
```cpp
void foo()
{
    ChronoStopwach csw;
    csw.start();
    // The code to be measured
    csw.stop();
    std::cout << "Elapsed time in nanosecond: " << csw.getElapsed();
    std::cout << "Elapsed time formatted: " << csw.getElapsedFormatted();
}
```
The ChronoStopwatch will work similarly to Stopwatch. The two differences are that the elapsed time will be in nanosecond precision and the formatted string will start in minutes instead of days ```0min 0sec 0mil 0mic 0mil 0nan```.

#### Timer
To handle events you can use the class Timer. The Timer class will let you activate events at a determined elapsed time.
```cpp
void foo()
{
    Timer timer(5 * SECOND);
    timer.start();
    while (true)
    {
        if (timer.timeout())
        {
            // Do something...
            timer.stop();
        }
    }
}
```
On the above example code, the timer is set to activate every 5 seconds. It will continue activating at the set time while it does not stopped. If you need that it stops to activate, you can use ```timer.stop();```.

## TODO
- [x] C++ implementation
- [ ] C implementation
