/*
Folkert Stijnman
10475206
Assignment 2, Simple Compression


A yearsOld, monthsOld and DayofTheWeek calculator
**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compile(std::istream& fin) {
    char my_char ;

        while (!fin.eof()) {

        fin.get(my_char);
        cout << my_char;
        }
}

int main(int argc, char* argv[]) {
    istream *in;
    ifstream ifn;

    if(argc == 1) {
        compile(std::cin);
    }
    else {
        std::ifstream inFile(argv[1]);
        compile(inFile);
    }
}
