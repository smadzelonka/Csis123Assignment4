//
//  Menu.hpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
const int MAXCOUNT = 20;
struct menuItem
{
    void (*func) ();
    char decript [50];
};
class Menu
{ private:
    menuItem mi[MAXCOUNT];
    int count;
    void runSelection();
public:
    Menu();
    void addMenu(char *Description, void (*f) ());
    void runMenu();
    void waitKey(); // declare waitKey function
};


#endif /* Menu_hpp */
