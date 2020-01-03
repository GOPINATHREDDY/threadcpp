#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#ifndef CsvReader_H
#define CsvReader_H

#define DELIMITER ','

class CsvReader {
public:
    CsvReader(string filePath, bool hasHeader = false) {
        this->rowId = 0;
        this->hasHeader = hasHeader;
        this->filePointer.open(filePath, ios::in);
    }

    vector<double> read() {
        vector<double> row;

        if (this->filePointer.eof()) {
            return row;
        }

        string line, word;
        getline(this->filePointer, line);
        if (this->rowId == 0 && this->hasHeader) {
            this->rowId++;
            getline(this->filePointer, line);
        }

        this->rowId++;
        istringstream ss(line);
        while (getline(ss, word, DELIMITER)) {
            row.push_back(atof(word));
        }

        return row;
    }

    bool isEOF() {
        return this->filePointer.eof();
    }

private:
    int rowId;

    bool hasHeader;

    fstream filePointer;
};

#endif