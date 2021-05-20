//
//  Menu.h
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#ifndef Menu_h
#define Menu_h
#include <iostream>
//This is the menu class.
//it contains 3 structs and methods to
//create 3 linked lists to hold all the menu
//items
class Menu {
private:
    struct Burger{
        std::string item;
        float price;
        Burger *next;
    };
    
    struct Sidedish{
        std::string item;
        float price;
        Sidedish *next;
    };
    
    struct Drink{
        std::string item;
        float price;
        Drink *next;
    };
    Burger *burghead;
    Sidedish *sidehead;
    Drink *drnkhead;
public:
    Menu();
    ~Menu();
    int loadData();
    void addToFront(Burger*);
    void addToFront(Sidedish*);
    void addToFront(Drink*);
    void burgDisplay();
    void drnkDisplay();
    void sideDisplay();
    //this makes Order a friend class
    //so that it can access menu choices and
    //store them into an order object
    friend class Order;

};


#endif /* Menu_h */
