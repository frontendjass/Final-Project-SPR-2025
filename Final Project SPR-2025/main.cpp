// Team Members: Daniel Perez, Juan Sosa, Sebastian Lamas, Thomas Rendon
// Programming Fundamentals II
// Spring Semester 2025
// Mrs. Lara
// Description: This application is an inventory management tool that allows users to import, view, search, and sort a list of store items from a text file.
// The text file must be in the following order: ID, name, description, price.

#include <iostream>
#include <fstream>
#include <string>
#include <vector> // To use vectors rather than arrays
#include <cctype> // I'm using this to validate lower/uppercase input

#include "Inventory.hpp" // Class
#include "InventoryUtils.hpp" // Utility functions

using namespace std;

int main() {
    string nameKey; // This is the name we want to find (input)
    int key; // This is the ID we want to find (input)
    
    vector<Inventory> inventoryList = ImportInventory(); // This calls the ImportInventory() function and stores the data into a vector "inventoryList"
    // Now we have the inventory Object extracted from the text file, so we can start using this data.
    
    PrintMenu(inventoryList, nameKey, key); // This function prints the menu, but more importantly, it passes inventoryList as an argument so that we can use the data.
    
    return 0;
}
