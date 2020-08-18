/*
Kevin Jin

lab number: final project
authors: Kevin Jin, Lance Carrido, Jaymen Luther, Nguyen Nhat Cong Le
description: The project is a house listing service providing the address, price, beds, baths, type, and area of houses in San Jose, with options to filter by address and price.
*/

#include "House.h"

bool House::printPrice = false;

House::House() {
    address = "";
    price = 0;
    beds = 0;
    baths = 0;
    type = "";
    area = 0;
}

House::House(std::string adrs, long p, int bds, int bths, std::string t, int a) {
    address = adrs;
    price = p;
    beds = bds;
    baths = bths;
    type = t;
    area = a;
}

/*
Overloaded == operator returning boolean depending on compared house addresses.
Pre: this - left side house object of operator; the object calling the operator overload function
     right - right side house object of operator; the object taken in
Post: None
Return: true - House addresses compared are the same
        false - House addresses compared are different
*/
bool House::operator == (const House& right) const {
    if (address == right.getAddress())
        return true;
    else
        return false;
}

/*
Overloaded < operator returning boolean depending on compared house prices.
Pre: this - left side house object of operator; the object calling the operator overload function
     right - right side house object of operator; the object taken in
Post: None
Return: true - price of the House on the left is less than to the price of the House on the right
        false - price of the House on the left is not less than the price of the House on the right
*/
bool House::operator < (const House& right) const {
    if (!(price < right.getPrice()))
        return false;
    return true;
}

/*
Overloaded >= operator returning boolean depending on compared house prices.
Pre: this - left side house object of operator; the object calling the operator overload function
     right - right side house object of operator; the object taken in
Post: None
Return: true - price of the House on the left is greater than to the price of the House on the right
        false - price of the House on the left is not greater than the price of the House on the right
*/
bool House::operator > (const House& right) const {
    if (!(price > right.getPrice()))
        return false;
    return true;
}

/*
Overloaded <= operator returning boolean depending on compared house prices.
Pre: this - left side house object of operator; the object calling the operator overload function
     right - right side house object of operator; the object taken in
Post: None
Return: true - price of the House on the left is less than or equal to the price of the House on the right
        false - price of the House on the left is not less than or equal to the price of the House on the right
*/
bool House::operator <= (const House& right) const {
    if (!(price <= right.getPrice()))
        return false;
    return true;
}

/*
Overloaded >= operator returning boolean depending on compared house prices.
Pre: this - left side house object of operator; the object calling the operator overload function
     right - right side house object of operator; the object taken in
Post: None
Return: true - price of the House on the left is greater than or equal to the price of the House on the right
        false - price of the House on the left is not greater than or equal to the price of the House on the right
*/
bool House::operator >= (const House& right) const {
    if (!(price >= right.getPrice()))
        return false;
    return true;
}

/*
 Overloaded ostream operator printing the price or csv format depending on the printPrice boolean.
 Pre: printPrice == true - operator prints in the price format
      printPrice == false - operator prints in the csv format
 Post: data added to out object in either price or csv format
 Return: out object - contains the new output data
 */
std::ostream& operator << (std::ostream& out, const House& right) {
    if (House::printPrice) {
        out << "$" << right.getPrice() << ": "
        << right.getAddress() << ","
        << right.getBeds() << ","
        << right.getBaths() << ","
        << right.getType() << ","
        << right.getArea();
    }
    else {
        out << right.getAddress() << ","
            << right.getPrice() << ","
            << right.getBeds() << ","
            << right.getBaths() << ","
            << right.getType() << ","
            << right.getArea();
    }
    
    return out;
}
