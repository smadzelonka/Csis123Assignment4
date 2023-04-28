//
//  main.cpp
//  Assignment 9
//  ID 0266099
//  Created by Sean Madzelonka on 4/28/23.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "Byte.hpp"

using namespace std;
using namespace Sean;

void generateRandom();
void parseFile();
void waitKey();
void Exit();

int main() {
    srand(time(NULL));

    while (true) {
        cout << "Menu:\n";
        cout << "1. Generate 100 random double numbers\n";
        cout << "2. Parse file and write binary\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                generateRandom();
                break;
            case 2:
                parseFile();
                break;
            case 3:
                Exit();
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    }

    return 0;
}

void generateRandom() {
    ofstream file("Numbers.txt");

    if (!file.is_open()) {
        cerr << "Error: Unable to create file." << endl;
        return;
    }

    for (int i = 0; i < 100; i++) {
        double r = (((double)rand() / (double)RAND_MAX) * (250 - 1)) + 1;
        file << fixed << setprecision(5) << r << endl;
    }

    file.close();
    cout << "Generated 100 random double numbers and saved to 'Numbers.txt'.\n";
    waitKey();
}

void parseFile() {
    ifstream inFile("Numbers.txt");
    ofstream outFile("binary.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    vector<int> numbers;
    string line;

    while (getline(inFile, line)) {
        double number = stod(line);
        numbers.push_back(static_cast<int>(number));
    }

    for (int number : numbers) {
        Byte byteNumber(number);
        outFile << number << " - binary: " << byteNumber.toString() << endl;
    }

    inFile.close();
    outFile.close();
    cout << "Parsed 'Numbers.txt' and wrote binary to 'binary.txt'.\n";
    waitKey();
}

void waitKey() {
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void Exit() {
    cout << "Goodbye!" << endl;
    exit(0);
}
