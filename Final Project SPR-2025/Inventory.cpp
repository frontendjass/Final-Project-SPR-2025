// These are the Inventory class functions

#include "Inventory.hpp"

Inventory::Inventory() {
    itemID = 0;
    itemName = "";
    itemDescription = "";
    itemPrice = 0.0;
}

Inventory::Inventory(int ID, string name, string description, double price) {
    itemID = ID;
    itemName = name;
    itemDescription = description;
    itemPrice = price;
}

void Inventory::Display() const {
    cout << "ID: " << itemID << endl;
    cout << "Name: " << itemName << endl;
    cout << "Description: " << itemDescription << endl;
    cout << "Price: $" << itemPrice << endl;
}

// Getters
int Inventory::getID() const {
    return itemID;
}

string Inventory::getName() const {
    return itemName;
}

string Inventory::getDescription() const {
    return itemDescription;
}

double Inventory::getPrice() const {
    return itemPrice;
}

// Setters
void Inventory::setID(int ID) {
    itemID = ID;
}

void Inventory::setName(const string& name) {
    itemName = name;
}

void Inventory::setDescription(const string& desc) {
    itemDescription = desc;
}

void Inventory::setPrice(double price) {
    itemPrice = price;
}
