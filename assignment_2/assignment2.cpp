/*
Folkert Stijnman
10475206
Assignment 2, Simple Compression


A yearsOld, monthsOld and DayofTheWeek calculator
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compile_stdin(std::istream& fin) {
    std::string line;
    while (getline(fin, line)) {
        for(int i = 0; i < line.size(); i++) {
            int counter = 1;
            while (line[i] == line[i+1]) {
                counter++;
                i++;
            }
            if (counter == 1) {
                if (isdigit(line[i]) || line[i] == '\\') {
                    cout << '\\' << line[i];
                }
                else {
                cout << line[i];
                }
            }
            else {
                if (isdigit(line[i]) || line[i] == '\\') {
                    cout << '\\' << line[i] << counter;
                }
                else {
                    cout << line[i] << counter;
                }
            }
        }
    }
}

void compile_file(std::istream& fin) {
    ofstream outfile("output.txt");
    std::string line;
    int line_count = 0;
    int char_in_input = 0;
    int char_in_output = 0;
    while (getline(fin, line)) {
        if (line.size() == 0) {
            line_count++;
        }
        for(int i = 0; i < line.size(); i++) {
            char_in_input++;
            char_in_output++;
            if (line_count > 0) {
                outfile << '\\' << 'n' << line_count;
                line_count = 0;
            }
            int counter = 1;
            while (line[i] == line[i+1]) {
                counter++;
                char_in_input++;
                i++;
            }
            if (counter == 1) {
                if (isdigit(line[i]) || line[i] == '\\') {
                    outfile << '\\' << line[i];
                }
                else {
                outfile << line[i];
                }
            }
            else {
                if (isdigit(line[i]) || line[i] == '\\') {
                    outfile << '\\' << line[i] << counter;
                }
                else {
                    outfile << line[i] << counter;
                }
            }
        }
    }
    float compr_ratio = (float)char_in_output / (float)char_in_input;
    std::cerr << "Compression result: " << compr_ratio << '\n';
}

int main(int argc, char* argv[]) {
    istream *in;
    ifstream ifn;

    if(argc == 1) {
        compile_stdin(std::cin);
    }
    else {
        std::ifstream inFile(argv[1]);
        compile_file(inFile);
    }
}
