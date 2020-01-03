#include <string>
#include <vector>
#include <fstream>
using namespace std;

#ifndef CsvWriter_H
#define CsvWriter_H

class CsvWriter {
public:
    CsvWriter(string filepath) {
        filePointer.open(filepath, ios::out | ios::app);
    }

    void write(double result, long timestamp) {
        filePointer << result << "," << timestamp << endl;
    }

    void close() {
        filePointer.close();
    }

private:
    fstream filePointer;
};

#endif