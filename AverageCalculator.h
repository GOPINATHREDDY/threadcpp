#include <vector>
#include <chrono>
#include "DataChannel.h"
#include "CsvWriter.h"
using namespace std;

#ifndef AverageCalculator_H
#define AverageCalculator_H

#define THREAD_SLEEP_MILLIS 5000
#define OUTPUT_PATH "Battery_data_out.csv"

class AverageCalculator {

public:
    AverageCalculator(DataChannel* channel) {
        this->channel = channel;
        this->writer = new CsvWriter(OUTPUT_PATH);
    }

    ~AverageCalculator() {
        this->writer->close();
    }

    double calculateAverage(vector<double> inputs) {
        cout << "calculating average" << endl;
        int inputSize = inputs.size();
        if (inputSize == 0) {
            return 0.0;
        }

        double sum = 0;
        for (int idx = 0; idx < inputSize; idx++) {
            sum += inputs[idx];
        }
        return sum / inputSize;
    }

    void run() {
        while (true) {        
            if (!channel->hasData()) {
                this_thread::sleep_for(chrono::milliseconds(THREAD_SLEEP_MILLIS));
                continue;
            }

            vector<double> input = channel->recvData();
            double average = calculateAverage(input);
            chrono::milliseconds epochTime = chrono::duration_cast<chrono::milliseconds>(
                chrono::system_clock::now().time_since_epoch()
            );

            writer->write(average, epochTime.count());
        }
    }

protected:
    DataChannel* channel;
    CsvWriter* writer;
};

#endif