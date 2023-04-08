//
//  Menu.cpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#include <iostream>
#include <cstdlib>

using namespace std;

#include "menu.hpp"

Menu::Menu()
:count(0)
{
    
}
void Menu::addMenu(char *Description, void (*f) (void))
{
    if (count < MAXCOUNT) {
        this->mi[count].func = f;
        strcpy(this->mi[count].decript, Description);
        count++;
    }
}
void Menu::runMenu(){
    for(;;)
    {
        system("CLS");
        for(int i = 0; i <count; i++){
            cout << this->mi[i].decript << endl;
        }
        runSelection();
        
    }
}

void Menu::runSelection(){
    int select;
    cin >> select;
    if(select <= count)
        this->mi[select - 1].func();
}

void Menu::waitKey() {
    cout << "Press any key to continue...";
    cin.ignore(); // ignore any characters already in the input buffer
    cin.get(); // wait for the user to input a character
}


