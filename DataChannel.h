#include <queue>
#include <mutex>
#include <iostream>
using namespace std;

#ifndef DataChannel_H
#define DataChannel_H

class DataChannel {

public:
    void sendData(vector<double> input) {
        {
            lock_guard<mutex> lock(this->lock);
            cout << "adding data to buffer" << endl;
            buffer.push(input);
        }
    }

    vector<double> recvData() {
        {
            lock_guard<mutex> lock(this->lock);
            cout << "sending data from buffer" << endl;
            vector<double> front = buffer.front();
            buffer.pop();
            return front;
        }
    }

    bool hasData() {
        {
            lock_guard<mutex> lock(this->lock);
            return !buffer.empty();
        }
    }

private:
    queue<vector<double>> buffer;
    mutex lock;
};

#endif