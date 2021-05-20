//
//  Menu.cpp
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "Menu.h"

#include <fstream>

//constructor to start 3 new lists
Menu::Menu(){
    burghead = new Burger;
    burghead -> next = NULL;
    sidehead = new Sidedish;
    sidehead -> next = NULL;
    drnkhead = new Drink;
    drnkhead -> next = NULL;
}

//adds burger menu choices into list after the files
//have been opened and read
void Menu::addToFront(Burger *ptr){
    Burger *tmp;
    tmp = ptr;
    tmp -> next = burghead;
    burghead = tmp;
}

//adds sidedish menu items into list after the files
//have been opened and read
void Menu::addToFront(Sidedish *ptr){
    Sidedish *tmp;
    tmp = ptr;
    tmp -> next = sidehead;
    sidehead = tmp;
}

//adds drinks menu items into list after the files
//have been opened and read
void Menu::addToFront(Drink *ptr){
    Drink *tmp;
    tmp = ptr;
    tmp -> next = drnkhead;
    drnkhead = tmp;
}

//attempts to open 3 text files, but returns a 0 if one of them fails
//or a 1 if they are all successful in opening. This returned integer
//is passed around to terminate the program immediately.
int Menu::loadData(){
    int rtrnVal = 0;
    std::ifstream fin;
    std::string filename = "burger.txt";
    fin.open(filename.c_str());
    if (fin.fail()){
        std::cout << "failed to open a file." << std::endl;
        return rtrnVal;
    }
    int number;
    fin >> number;
    std::string restofline;
    getline(fin, restofline);
    for (int i = 0; i < number; i++){
        Burger *ptr = new Burger;
        getline(fin, ptr -> item);
        fin >> ptr -> price;
        getline(fin, restofline);
        addToFront(ptr);
    }
    
    fin.close();
    
    fin.open("sidedish.txt");
    if (fin.fail()){
        std::cout << "failed to open a file." << std::endl;
        return rtrnVal;
    }

    fin >> number;
    getline(fin, restofline);
    for (int i = 0; i < number; i++){
        Sidedish *ptr = new Sidedish;
        getline(fin, ptr -> item);
        fin >> ptr -> price;
        getline(fin, restofline);
        addToFront(ptr);
    }
    
    fin.close();
    
    fin.open("drink.txt");
    if (fin.fail()){
        std::cout << "failed to open a file." << std::endl;
        return rtrnVal;
    }
    
    fin >> number;
    getline(fin,restofline);
    for (int i = 0; i < number; i++){
        Drink *ptr = new Drink;
        getline(fin, ptr -> item);
        fin >> ptr -> price;
        getline(fin, restofline);
        addToFront(ptr);
    }
    
    fin.close();
    return rtrnVal + 1;
}

//The following three methods display the menu options.
void Menu::burgDisplay(){
    int count = 1;
    Burger *ptr = burghead;
    while (ptr -> next != NULL) {
        std::cout << count << ". " << ptr -> item << std::endl;
        std::cout << "   $" << ptr -> price << std::endl;
        ptr = ptr -> next;
        count++;
    }
    std::cout << count << ". None of the above" << std::endl;
    
}
void Menu::drnkDisplay(){
    int count = 1;
    Drink *ptr = drnkhead;
    while (ptr -> next != NULL) {
        std::cout << count << ". " << ptr -> item << std::endl;
        std::cout << "   $" << ptr -> price << std::endl;
        ptr = ptr -> next;
        count++;
    }
    std::cout << count << ". None of the above" << std::endl;
}
void Menu::sideDisplay(){
    int count = 1;
    Sidedish *ptr = sidehead;
    while (ptr -> next != NULL) {
        std::cout << count << ". " << ptr -> item << std::endl;
        std::cout << "   $" << ptr -> price << std::endl;
        ptr = ptr -> next;
        count++;
    }
    std::cout << count << ". None of the above" << std::endl;
}

Menu::~Menu(){
    Burger *burgcur = burghead;
    Burger *burgtmp;
    Sidedish *sidecur = sidehead;
    Sidedish *sidetmp;
    Drink *drnkcur = drnkhead;
    Drink *drnktmp;
    while (burgcur != 0) {
        burgtmp = burgcur->next;
        delete burgcur;
        burgcur = burgtmp;
    }
    while (sidecur != 0) {
        sidetmp = sidecur->next;
        delete sidecur;
        sidecur = sidetmp;
    }
    while (drnkcur != 0) {
        drnktmp = drnkcur->next;
        delete drnkcur;
        drnkcur = drnktmp;
    }
    
}




