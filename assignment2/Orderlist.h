//
//  Orderlist.h
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#ifndef Orderlist_h
#define Orderlist_h
#include "Order.h"

//This is a class that is used to create a linked list of orders
//it is pretty standard and doesnt need much explanation
class OrderList {
private:
    struct Node {
        Order *data;
        Node *prev;
        Node *next;
    };
    Node *head;
    Node *tail;
    float dailyTotal = 0;
    int size;
public:
    OrderList();
    bool isEmpty();
    void addToTail(Order &);
    void removeFront();//serve order
    void displayAll();
    float rtrndailyTotal();
};

#endif /* Orderlist_h */
