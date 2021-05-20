//
//  Order.cpp
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "Order.h"
#include <iomanip>

//constructor that gets all the users order info when
//object is created
Order::Order(int ordNum){
    noneOfTheAbove = 0;
    zeroOrOne = 0;
    std::string restOfLine;
    ptr = new Menu;
    //load all the data from the text files
    //and then return a 0 or a 1 (0 being one of the files could not open)
    zeroOrOne = ptr -> loadData();
    //if the files all opened correctly then take in users order
    if (zeroOrOne != 0){
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Please enter your choice for burger: " << std::endl;
        std::cout << "-----------------------------------------" <<std::endl;
        //display menu options then get user choice
        ptr -> burgDisplay();
        std::cin.ignore();
        std::cin >> burgNum;
        getline(std::cin, restOfLine);
        if (burgNum == 6){
            noneOfTheAbove += burgNum;
        }
        //grabs item name (string) and price from menu and returns
        //them into variables that are part of this class, placing
        //them into the order
        //this is probably not the most efficient way... in retrospect
        //i could have made a search function or something
        if (burgNum == 1){
            burg = ptr -> burghead -> item;
            burgPrice = ptr -> burghead -> price;
        }
        if (burgNum == 2){
            burg = ptr -> burghead -> next -> item;
            burgPrice = ptr -> burghead -> next -> price;
        }
        if (burgNum == 3){
            burg = ptr -> burghead -> next -> next -> item;
            burgPrice = ptr -> burghead -> next -> next -> price;
        }
        if (burgNum == 4){
            burg = ptr -> burghead -> next -> next -> next -> item;
            burgPrice = ptr -> burghead -> next -> next -> next -> price;
        }
        if (burgNum == 5){
            burg = ptr -> burghead -> next -> next -> next-> next -> item;
            burgPrice = ptr -> burghead -> next -> next -> next-> next -> price;
        }
        
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Please enter your choice for side-dish: " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        //display menu items then get user choice
        ptr -> sideDisplay();
        std::cin >> sideNum;
        getline(std::cin, restOfLine);
        noneOfTheAbove += sideNum;
        //grabs item name (string) and price from menu and returns
        //them into variables that are part of this class, placing
        //them into the order
        //this is probably not the most efficient way... in retrospect
        //i could have made a search function or something
        if (sideNum == 1){
            side = ptr -> sidehead -> item;
            sidePrice = ptr -> sidehead -> price;
        }
        if (sideNum == 2){
            side = ptr -> sidehead -> next -> item;
            sidePrice = ptr -> sidehead -> next -> price;
        }
        if (sideNum == 3){
            side = ptr -> sidehead -> next -> next -> item;
            sidePrice =  ptr -> sidehead -> next -> next -> price;
        }
        if (sideNum == 4){
            side = ptr -> sidehead -> next -> next -> next -> item;
            sidePrice = ptr -> sidehead -> next -> next -> next -> price;
        }
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Please enter your choice for drink: " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        //display menu items then get user choice
        ptr -> drnkDisplay();
        std::cin >> drnkNum;
        getline(std::cin, restOfLine);
        noneOfTheAbove += drnkNum;
        //grabs item name (string) and price from menu and returns
        //them into variables that are part of this class, placing
        //them into the order
        //this is probably not the most efficient way... in retrospect
        //i could have made a search function or something
        if (drnkNum == 1){
            drnk = ptr -> drnkhead -> item;
            drnkPrice = ptr -> drnkhead -> price;
        }
        if (drnkNum == 2){
            drnk = ptr -> drnkhead -> next -> item;
            drnkPrice = ptr -> drnkhead -> next -> price;
        }
        if (drnkNum == 3){
            drnk = ptr -> drnkhead -> next -> next -> item;
            drnkPrice =  ptr -> drnkhead -> next -> next -> price;
        }
    
        if (noneOfTheAbove != 15) {
            orderNum = ordNum;
            std::cout << "Your order number is " << orderNum << std::endl << std::endl;
        }
    } else {
        std::cout << std::endl << "Program Terminated." << std::endl;
    }
}

//this is a display functino which will display an order
//including 5% sales tax
void Order::display(){
    std::cout << "Order Number: ";
    std::cout << orderNum << std::endl;
    std::cout << "      Burger: ";
    std::cout << burg << std::endl;
    std::cout << "        side: ";
    std::cout << side << std::endl;
    std::cout << "       drink: ";
    std::cout << drnk << std::endl;
    std::cout << " total price: ";
    float totalPrice = drnkPrice + burgPrice + sidePrice;
    totalPrice += totalPrice * (0.05);
    std::cout << std::setprecision(2) << std::fixed << "$" << totalPrice << std::endl;
    std::cout << std::endl;
}

//returns value to main which indicates if a user
//entered "none of the above" for a menu choice
//if they entered this for all choices, then the order
//will not be put to the list (main deals with this)
int Order::returnVal(){
    return noneOfTheAbove;
}

//returns a value to main that will end the program if text files
//did not open
int Order::rtrnZeroOrOne(){
    return zeroOrOne;
}

