//
//  Orderlist.cpp
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "Orderlist.h"
#include <iomanip>
OrderList::OrderList(){
    //make dummy's next and prev point to itself
    head = new Node;
    head -> next = head;
    head -> prev = head;
    size = 0;
}

//return true if list empty
bool OrderList::isEmpty(){
    return (head -> next == head);
}

void OrderList::addToTail(Order &record){
    Node *ptr = new Node;
    //put new order into list
    ptr -> data = &record;
    //connect circular link on last nodes next back to head
    ptr -> next = head;
    //make new node point to second last node in list
    ptr -> prev = head -> prev;
    //connect circular link on dummy's prev back to tail
    head -> prev = ptr;
    //make second last node point to last
    ptr -> prev -> next = ptr;
    size++;
}

//serve an order (display it then delete it)
void OrderList::removeFront(){
    if (head -> next != head) {
        std::cout << "Order Number: ";
        std::cout << head -> next -> data -> orderNum << std::endl;
        std::cout << "      Burger: ";
        std::cout << head -> next -> data -> burg << std::endl;
        std::cout << "        side: ";
        std::cout << head -> next -> data -> side << std::endl;
        std::cout << "       drink: ";
        std::cout << head -> next -> data -> drnk << std::endl;
        float totalPrice = head -> next -> data -> sidePrice;
        totalPrice += head -> next -> data -> drnkPrice;
        totalPrice += head -> next -> data -> burgPrice;
        totalPrice += totalPrice * (0.05);
        std::cout << " total Price: ";
        std::cout << std::setprecision(2) << std::fixed << '$' << totalPrice << std::endl;
        dailyTotal += totalPrice;
        
        //create victim pointer, make it point to front of list
        //(after dummy)
        Node *victim = head -> next;
        head -> next = victim -> next;
        head -> next -> prev = head;
        delete victim -> data;
        delete victim;
        //if the list is empty then delete the dummy
    } else if (head -> next == head){
        delete head;
    }
    size--;
}

//traverse list and use display method in order class
void OrderList::displayAll(){
    Node *ptr = head -> next;
    while (ptr != head) {
        ptr -> data -> display();
        ptr = ptr -> next;
    }
}

//return the total sales to main
float OrderList::rtrndailyTotal(){
    return dailyTotal;
}


