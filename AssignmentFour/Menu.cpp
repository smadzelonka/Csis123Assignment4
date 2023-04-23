//
//  Menu.cpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//
#include <iostream>
#include <cstdlib>
#include "menu.hpp"

using namespace std;


namespace Sean {


Menu::Menu() : count(0) {}

    Menu::~Menu() {}

    Menu& Menu::getInstance() {
        static Menu instance;
        return instance;
    }

    void Menu::addMenu(char* description, void(*func)()) {
        if (count < 20) {
            items[count].func = func;
            strcpy(items[count].description, description);
            count++;
        }
    }

    void Menu::runMenu() {
        for (;;) {
            system("CLS");
            for (int i = 0; i < count; i++) {
                cout << items[i].description << endl;
            }
            int select;
            cin >> select;
            if (select > 0 && select <= count) {
                items[select - 1].func();
            }
        }
    }

    void Menu::waitKey() {
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }

}
