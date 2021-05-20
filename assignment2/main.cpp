//
//  main.cpp
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "Orderlist.h"
#include <iostream>
using namespace std;

//constants for order numbers mins and max
const int MinOrderNum = 100;
const int MaxOrderNum = 999;


//main routine
int main(){
    
    //create list
    OrderList List;
    //create pointer that can point
    //to objects that will be put into the list
    Order *Data;
    
    char userCommand = NULL;
    int orderNum = MinOrderNum;
    
    //introduction
    cout << "*** Welcome to Fast Food Ordering System ***" << endl << endl;
    cout << "Enter O to make a new order" << endl;
    cout << "or S to serve an order" << endl;
    cout << "or V to view all orders" << endl;
    cout << "or H for help (displays this menu)" << endl;
    cout << "or T to terminate this program" << endl << endl;
    
    //loop with conditions dependent on user command
    while (userCommand != 't' || userCommand != 'T') {
        
        cout << "------------------------------" << endl;
        cout << "Please enter your choice: ";
        cin >> userCommand;
        cout << "------------------------------";
        cout << endl << endl;
        
        //populate new order add to tail of list
        if (userCommand == 'o' || userCommand == 'O') {
            if (orderNum <= MaxOrderNum) {
                Data = new Order(orderNum);
                //if we couldnt open one of the text files END PROG
                int fileNotOk = Data -> rtrnZeroOrOne();
                if (fileNotOk == 0) {
                    //clean up dummy node
                    List.removeFront();
                    return 0;
                }
                //files opened and order was taken
                //so lets add the order to the list
                //as long as the user didnt enter
                //"none of the above" for all 3 order choices.
                int val = Data -> returnVal();
                if (val != 15){
                   List.addToTail(*Data);
                   orderNum ++;
                } else {
                    cout << endl << "Empty Order. Discard" << endl;
                }
            } else {
                //if maximum amount of orders have gone into the list
                cout << "Fast Food Ordering System cannot hold more than";
                cout << MaxOrderNum - MinOrderNum << "orders." << endl;
                cout << "Please serve an order before trying to add another one." << endl <<endl;
            }
            
            //serve order: display then removeFront
            //to delete item from list
        } else if (userCommand == 's' || userCommand == 'S') {
            if (List.isEmpty()){
                cout << "Error: There are currently no orders in the system." << endl;
                cout << endl;
            } else {
                List.removeFront();
                cout << endl;
            }
            //view orders: call display if list not empty, otherwise display error
        } else if (userCommand == 'v' || userCommand == 'V') {
            if (List.isEmpty() == false) {
                List.displayAll();
            } else {
                cout << "Error: There are currently no orders in the system." << endl << endl;
            }
            
            //help: display option menu
        } else if (userCommand == 'h' || userCommand == 'H') {
            cout << "Enter O to make a new order" << endl;
            cout << "or S to serve an order" << endl;
            cout << "or V to view all orders" << endl;
            cout << "or H for help (displays this menu)" << endl;
            cout << "or T to terminate this program" << endl << endl;
            
            //terminate: terminate the program if the list is NULL, otherwise display error
        } else if (userCommand == 't' || userCommand == 'T') {
            if (List.isEmpty() == false) {
                cout << "Error: there are currently orders in the system" << endl << endl;
            } else {
                //display total orders processed and the total sales
                cout << "The total number of orders processed is " << orderNum - MinOrderNum << endl;
                cout << "The total sales amount is $" << List.rtrndailyTotal() << endl;
                cout << endl;
                //delete dummy node
                List.removeFront();
                //end prog
                return 0;
            }
            
        }
        
    }
    
}

   
