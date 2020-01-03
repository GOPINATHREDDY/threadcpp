#include "DataChannel.h"
#include "DataFetcher.h"
#include "AverageCalculator.h"
using namespace std;

#ifndef Dipatcher_H
#define Dispatcher_H

class Dispatcher {

public:
    Dispatcher() {
        channel = new DataChannel();

        calculator = new AverageCalculator(channel);
        fetcher = new DataFetcher(channel);
    }

    ~Dispatcher() {
        delete(fetcher);
        delete(calculator);

        delete(channel);
    }

    void dispatch() {
        cout << "dispatching data fetcher" << endl;
        thread t = thread(&DataFetcher::run, fetcher);
        
        cout << "dispatching calculator" << endl;
        thread t2 = thread(&AverageCalculator::run, calculator);

        t.join();
        t2.join();
    }

protected:
    DataChannel* channel;

    DataFetcher* fetcher;
    AverageCalculator* calculator;
};

#endif