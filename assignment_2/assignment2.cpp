/*
Folkert Stijnman
10475206
Assignment 2, Simple Compression

A compress and decompress program
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void compile_stdout(std::istream& fin) {
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
                cout << '\\' << 'n' << line_count;
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
    printf("\n");
    float compr_ratio = (float)char_in_output / (float)char_in_input;
    std::cerr << "Compression result: " << compr_ratio << '\n';
}

void compile_to_file(std::istream& fin, const std::string& output) {
    ofstream outfile(output);
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
        if (line_count == 0) {
            line_count++;
        }
    }
    float compr_ratio = (float)char_in_output / (float)char_in_input;
    std::cerr << "Compression result: " << compr_ratio << '\n';
}

void decompress_stdout(std::istream& fin) {
    std::string line;
    std::string num_occ;
    std::string str1 ("\\");
    std::string str2 ("\\n");
    while (getline(fin, line)) {
        for(int i = 0; i < line.size(); i++) {
            std::string temp;
            if (line[i] == '\\') {
                temp = line[i];
                i++;
            }
            temp += line[i];
            while (isdigit(line[i + 1])) {
                i++;
                num_occ += line[i];
            }
            stringstream geek(num_occ);
            int repeat = 0;
            geek >> repeat;
            num_occ.clear();
            while (repeat > 1) {
                if (temp.find(str2) != std::string::npos) {
                    cout << "\n";
                }
                else if (temp.find(str1) != std::string::npos) {
                    cout << temp[1];
                }
                else {
                    cout << temp;
                }
                repeat--;
            }
            if (temp == "\\n") {
                cout << '\n';
            }
            else if (temp.find(str1) != std::string::npos) {
                cout << temp[1];
            }
            else {
                cout << temp;
            }
        }
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    istream *in;
    ifstream ifn;

    if(argc == 1) {
        compile_stdout(std::cin);
    }
    else {
        if (argc == 3) {
            std::ifstream inFile(argv[1]);
            compile_to_file(inFile, argv[2]);
        }
        else {
            std::ifstream inFile(argv[1]);
            decompress_stdout(inFile);
        }
    }
}
