/*
Folkert Stijnman
10475206
Assignment 2, Simple Compression

A compress and decompress program.

Used Ubuntu and G++ to test and compile
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

void compress(std::istream& fin, std::ostream& output) {
    std::string line;
    int line_count = 1;
    int char_in_input = 0;
    int char_in_output = 0;
    while (getline(fin, line)) {
        if (line.size() == 0) {
            line_count++;
            continue;
        }
        for(int i = 0; i < line.size(); i++) {
            char_in_input++;
            char_in_output++;
            if (line_count > 1) {
                output << line_count;
                line_count = 1;
            }
            int counter = 1;
            while (line[i] == line[i+1]) {
                counter++;
                char_in_input++;
                i++;
            }
            if (counter == 1) {
                if (isdigit(line[i]) || line[i] == '\\') {
                    output << '\\' << line[i];
                }
                else {
                output << line[i];
                }
            }
            else {
                if (isdigit(line[i]) || line[i] == '\\') {
                    output << '\\' << line[i] << counter;
                }
                else {
                    output << line[i] << counter;
                }
            }
        }
    output << "\n";
    }
    float compr_ratio = (float)char_in_output / (float)char_in_input;
    std::cerr << "\nCompression result: " << compr_ratio << '\n';
}

void decompress(std::istream& fin, std::ostream& output) {
    std::string line;
    std::string num_occ;
    std::string str1 ("\\");
    int char_in_input = 0;
    int char_in_output = 0;
    while (getline(fin, line)) {
        for(int i = 0; i < line.size(); i++) {
            if (isdigit(line[0]) && i == 0) {
                std::stringstream str;
                str << line[0];
                double x;
                str >> x;
                while (x > 1) {
                    output << "\n";
                    x--;
                }
                i++;
            }
            std::string temp;
            if (line[i] == '\\') {
                i++;
            }
            temp = line[i];
            while (isdigit(line[i + 1])) {
                i++;
                num_occ += line[i];
            }
            std::stringstream geek(num_occ);
            int repeat = 0;
            geek >> repeat;
            num_occ.clear();
            while (repeat > 1) {
                if (temp.find(str1) != std::string::npos) {
                    output << temp;
                }
                else {
                    output << temp;
                }
                char_in_output++;
                repeat--;
            }
            if (temp.find(str1) != std::string::npos) {
                output << temp;
            }
            else {
                output << temp;
            }
            char_in_input++;
            char_in_output++;
        }
        output << "\n";
    }
    float compr_ratio = (float)char_in_output / (float)char_in_input;
    std::cerr << "\nDecompression result: " << compr_ratio << '\n';
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 4 || strcmp(argv[1], "-h") == 0) {
        std::ifstream inFile("README.txt");
        std::string line;
        while (getline(inFile, line)) {
            std::cerr << line;
            std::cerr << "\n";
        }
        exit(0);
    }
    else if (strcmp(argv[1], "-c") == 0) {
        if(argc == 2) {
            compress(std::cin, std::cout);
        }
        else if (argc == 3) {
                std::ifstream inFile(argv[2]);
                compress(inFile, std::cout);
        }
        else if (argc == 4) {
                std::ifstream inFile(argv[2]);
                std::ofstream outFile(argv[3]);
                compress(inFile, outFile);
        }
    }
    else if (strcmp(argv[1], "-d") == 0) {
        if(argc == 2) {
            decompress(std::cin, std::cout);
        }
        else if (argc == 3) {
                std::ifstream inFile(argv[2]);
                decompress(inFile, std::cout);
        }
        else if (argc == 4) {
                std::ifstream inFile(argv[2]);
                std::ofstream outFile(argv[3]);
                decompress(inFile, outFile);
        }
    }
}
