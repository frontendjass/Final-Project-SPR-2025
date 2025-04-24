// This is the Inventory class

#ifndef Inventory_hpp
#define Inventory_hpp

#include <string>
#include <iostream>
using namespace std;

class Inventory {
private:
    int itemID;
    string itemName;
    string itemDescription;
    double itemPrice;

public:
    Inventory(); // Default constructor
    Inventory(int ID, string name, string description, double price); // Parameter constructor
    void Display() const;

    // Getters
    int getID() const;
    string getName() const;
    string getDescription() const;
    double getPrice() const;

    // Setters (optional if needed)
    void setID(int ID);
    void setName(const string& name);
    void setDescription(const string& desc);
    void setPrice(double price);
};

#endif /* Inventory_hpp */
