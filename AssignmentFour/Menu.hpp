//
//  Menu.hpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#ifndef Menu_hpp
#define Menu_hpp
#include <stdio.h>

namespace Sean
{
    struct menuItem {
        void (*func)();
        char description[50];
    };

    class Menu {
    private:
        menuItem items[20];
        int count;
        Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        ~Menu();
    public:
        static Menu& getInstance();
        void addMenu(char* description, void(*func)());
        void runMenu();
        void waitKey();
    };

}


#endif /* Menu_hpp */
