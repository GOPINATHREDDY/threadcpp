/*
Please implement a software with two threads. One thread reads out the values 
and sends them to the other thread once it read 10 data points. This thread 
should get the arithmetic average value of these data points and should store 
them with the UNIX timestamp in milliseconds in a second csv file.

The threads should work in parallel so I would recommend to implement some kind
of sleeps between two read values.
*/

#include <thread>
#include "include/DataChannel.h"
#include "include/AverageCalculator.h"
#include "include/DataFetcher.h"
using namespace std;

int main() {
    DataChannel* channel = new DataChannel();
    DataFetcher* fetcher = new DataFetcher(channel);
    AverageCalculator* calculator = new AverageCalculator(channel);

    thread t2 = thread(&AverageCalculator::run, calculator);
    fetcher->run();
    t2.join();
    
    return 0;
}