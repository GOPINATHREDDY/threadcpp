#include <vector>
#include "CsvReader.h"
using namespace std;

#ifndef DataFetcher_H
#define DataFetcher_H

#define INPUT_LIMIT 2
#define INPUT_FILEPATH "Battery_data.csv"

class DataFetcher {

public:
    DataFetcher(DataChannel* channel) {
        this->channel = channel;
        this->reader = new CsvReader(INPUT_FILEPATH, true);
    }

    void run() {
        vector<double> inputVector;

        cout << "reading data..." << endl;
        while (true) {
            if (reader->isEOF()) {
                cout << "end of file" << endl;
                break;
            }

            vector<double> row = reader->read();
            if (row.size() == 0) {
                break;
            }
            
            double input = row[0];
            inputVector.push_back(input);

            if (inputVector.size() == INPUT_LIMIT) {
                sendInputOverChannel(inputVector);
                inputVector.clear();
            }
        }

    }

private:
    void sendInputOverChannel(vector<double> input) {
        cout << "sending data over channel... ";
        for (int idx = 0; idx < input.size(); idx++) {
            cout << input[idx] << " ";
        }
        cout << endl;

        channel->sendData(input);
    }

protected:
    DataChannel* channel;

    CsvReader* reader;
};

#endif