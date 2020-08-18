/*
Kevin Jin

lab number: final project
authors: Kevin Jin, Lance Carrido, Jaymen Luther, Nguyen Nhat Cong Le
description: The project is a house listing service providing the address, price, beds, baths, type, and area of houses in San Jose, with options to filter by address and price.
*/

#ifndef HOUSE_H
#define HOUSE_H

#include <string>
#include <iostream>
#include <iomanip>

class House {
private:
    std::string address;
    long price;
    int beds, baths;
    std::string type;
    int area;
    
    static bool printPrice;
    
public:
    House();
    House(std::string, long, int, int, std::string, int);
    
    /*
     Static function to set the print mode of price or csv format.
     Pre: None
     Post: boolean printPrice set to printP
            - setting to true means price format
            - setting to false means csv format
     Return: None
     */
    static void setPrintMode(bool printP) {
        printPrice = printP;
    }
    
    /*
    Setter for the address.
    Pre: a - string value setting the house address
    Post: value of a set to House address attribute
    Return: None
    */
    void setAddress(std::string a) {
        address = a;
    }
    
    /*
    Getter for the address.
    Pre: None
    Post: None
    Return: address - string representing house address
    */
    std::string getAddress() const {
        return address;
    }
    
    /*
    Setter for the price.
    Pre: p - int value setting the house price
    Post: value of b set to House price attribute
    Return: None
    */
    void setPrice(long p) {
        price = p;
    }
    
    /*
    Getter for the price.
    Pre: None
    Post: None
    Return: price - long representing house price
    */
    long getPrice() const {
        return price;
    }
    
    /*
    Setter for the number of beds.
    Pre: b - int value setting the number of beds
    Post: value of b set to House beds attribute
    Return: None
    */
    void setBeds(int b) {
        beds = b;
    }
    
    /*
    Getter for the number of beds.
    Pre: None
    Post: None
    Return: baths - int representing number of house beds
    */
    int getBeds() const {
        return beds;
    }
    
    /*
    Setter for the number of baths.
    Pre: b - int value setting the number of baths
    Post: value of b set to House baths attribute
    Return: None
    */
    void setBaths(int b) {
        baths = b;
    }
    
    /*
    Getter for the number of baths.
    Pre: None
    Post: None
    Return: baths - int representing number of house baths
    */
    int getBaths() const {
        return baths;
    }
    
    /*
    Setter for the type.
    Pre: t - string value setting the type of the House
    Post: value of t set to House type attribute
    Return: None
    */
    void setType(std::string t) {
        type = t;
    }
    
    /*
    Getter for the area.
    Pre: None
    Post: None
    Return: type - string representing house type
    */
    std::string getType() const {
        return type;
    }
    
    /*
    Setter for the area.
    Pre: a - int value setting the area of the House
    Post: value of a set to House area attribute
    Return: None
    */
    void setArea(int a) {
        area = a;
    }
    
    /*
     Getter for the area.
     Pre: None
     Post: None
     Return: area - int representing house arae
     */
    int getArea() const {
        return area;
    }
    
    /*
    Overloaded == operator returning boolean depending on compared house addresses.
    Pre: this - left side house object of operator; the object calling the operator overload function
         right - right side house object of operator; the object taken in
    Post: None
    Return: true - House addresses compared are the same
            false - House addresses compared are different
    */
    bool operator == (const House&) const;
    
    /*
    Overloaded < operator returning boolean depending on compared house prices.
    Pre: this - left side house object of operator; the object calling the operator overload function
         right - right side house object of operator; the object taken in
    Post: None
    Return: true - price of the House on the left is less than to the price of the House on the right
            false - price of the House on the left is not less than the price of the House on the right
    */
    bool operator < (const House&) const;
    
    /*
    Overloaded >= operator returning boolean depending on compared house prices.
    Pre: this - left side house object of operator; the object calling the operator overload function
         right - right side house object of operator; the object taken in
    Post: None
    Return: true - price of the House on the left is greater than to the price of the House on the right
            false - price of the House on the left is not greater than the price of the House on the right
    */
    bool operator > (const House&) const;
    
    /*
    Overloaded <= operator returning boolean depending on compared house prices.
    Pre: this - left side house object of operator; the object calling the operator overload function
         right - right side house object of operator; the object taken in
    Post: None
    Return: true - price of the House on the left is less than or equal to the price of the House on the right
            false - price of the House on the left is not less than or equal to the price of the House on the right
    */
    bool operator <= (const House&) const;
    
    /*
    Overloaded >= operator returning boolean depending on compared house prices.
    Pre: this - left side house object of operator; the object calling the operator overload function
         right - right side house object of operator; the object taken in
    Post: None
    Return: true - price of the House on the left is greater than or equal to the price of the House on the right
            false - price of the House on the left is not greater than or equal to the price of the House on the right
    */
    bool operator >= (const House&) const;
    
    friend std::ostream& operator << (std::ostream&, const House&);
};

#endif /* HOUSE_H */
