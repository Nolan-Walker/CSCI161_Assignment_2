//
//  Order.h
//  assignment2
//
//  Created by Nolan Caissie on 2017-02-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#ifndef Order_h
#define Order_h
#include "Menu.h"

//This is the order class which contains
//all of the nessecary attributes to hold
//users orders.
class Order {
private:
    int orderNum;
    std::string burg;
    std::string side;
    std::string drnk;
    float burgPrice;
    float drnkPrice;
    float sidePrice;
    int burgNum;
    int sideNum;
    int drnkNum;
    int noneOfTheAbove;
    int zeroOrOne;
    Menu *ptr;
public:
    Order(int ordNum);
    void display();
    int returnVal();
    int rtrnZeroOrOne();
    //this is here to allow OrderList to access
    //some of the attributes in the order objects
    //through the Order *data pointer in the struct blow
    //(this struct located in OrderList)
    // struct Node {
    //    Order *data;
    //    Node *prev;
    //    Node *next;
    // };
    friend class OrderList;
};

#endif /* Order_h */
