// These are the function difinitions separated into its own file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "InventoryUtils.hpp"

using namespace std;

// Function definitions

// This function imports items from a text file
vector<Inventory> ImportInventory() {
    ifstream inputFile("store_inventory.txt");
    vector<Inventory> items;  // Vector to hold all imported inventory items
    
    int ID;
    string name;
    string description;
    double price;
    
    // Reads until the end of the file
    while (inputFile >> ID) {
        inputFile.ignore(); // To skip the newline character
        getline(inputFile, name);
        getline(inputFile, description);
        inputFile >> price;
        inputFile.ignore(); // To skip the newline after price
        
        // Creates Inventory object and add to vector
        items.push_back(Inventory(ID, name, description, price));
    }
    
    if (inputFile.fail() && !inputFile.eof()) {
        cout << "Error occurred while reading from store_inventory.txt" << endl;
    }
    
    inputFile.close();
    return items;
}

// This function prints the menu with different listing options; it also makes the menu repeatable
void PrintMenu(const vector<Inventory>& inventoryList, string nameKey, int key) {
    char repeatMenu = 'y';
    char option;
    
    do {
        // Display menu
        cout << "------------------------- Store Inventory -------------------------" << endl << endl;
        cout << "A. Search item by ID" << endl << endl;
        cout << "B. Search item by Name" << endl << endl;
        cout << "C. List all items in the inventory (unsorted)" << endl << endl;
        cout << "D. List all items in the inventory in ascending order by item ID" << endl << endl;
        cout << "E. List all items in the inventory in ascending order by name" << endl << endl;
        cout << "F. List all items in the inventory in ascending order by price" << endl << endl;
        
        cin >> option;
        option = toupper(option); // Turns every input into capital caseA
        
        switch (option) {
            case 'A':
                cout << "Search item by ID" << endl;
                cout << "Type ID to search: ";
                cin >> key;
            {
                int index = SearchByID(inventoryList, key);
                if (index != -1) {
                    cout << "Item found:" << endl;
                    inventoryList[index].Display();
                } else {
                    cout << "Item with ID " << key << " not found." << endl;
                }
            }
                break;
            case 'B':
                cout << "Search item by name" << endl;
                cout << "Type name to search: ";
            {
                cin.ignore();
                getline(cin, nameKey);
                
                vector<int> matches = SearchByName(inventoryList, nameKey);
                if (!matches.empty()) {
                    cout << "Found " << matches.size() << " item(s) with name \"" << nameKey << "\":" << endl;
                    for (int index : matches) {
                        inventoryList[index].Display();
                        cout << "------------------------------------" << endl;
                    }
                } else {
                    cout << "Item with name \"" << nameKey << "\" not found." << endl;
                }
            }
                break;
                break;
            case 'C':
                cout << "List all items in the inventory (unsorted)" << endl;
                ListAllItems(inventoryList);
                break;
            case 'D':
                cout << "List all items in the inventory in ascending order by item ID." << endl;
                ListAscendingID(inventoryList);
                break;
            case 'E':
                cout << "List all items in the inventory in ascending order by name." << endl;
                ListByName(inventoryList);
                break;
            case 'F':
                cout << "List all items in the inventory in ascending order by price." << endl;
                ListByPrice(inventoryList);
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
        
        cout << "Would you like to try again? y/n" << endl;
        cin >> repeatMenu;
        repeatMenu = toupper(repeatMenu); // Turns every input into capital case
        
    } while (repeatMenu == 'Y');
}

// This function loops through the items and displays them in no order
void ListAllItems(const vector<Inventory>& inventoryList) {
    cout << "---------- Inventory List ----------" << endl;
    
    for (const Inventory& item : inventoryList) {
        item.Display();
        cout << "------------------------------------" << endl;
    }
}

// This functions sorts ID in ascending order
void ListAscendingID(const vector<Inventory>& inventoryList) {
    vector<Inventory> sortedList = inventoryList; // make a copy to modify
    
    // ZyBooks Selection Sort modified to use vectors and objects
    int i, j, indexSmallest;
    
    for (i = 0; i < sortedList.size() - 1; i++) {
        indexSmallest = i;
        for (j = i + 1; j < sortedList.size(); ++j) {
            if (sortedList[j].getID() < sortedList[indexSmallest].getID()) {
                indexSmallest = j;
            }
        }
        
        // Swap the whole objects
        Inventory temp = sortedList[i];
        sortedList[i] = sortedList[indexSmallest];
        sortedList[indexSmallest] = temp;
    }
    
    ListAllItems(sortedList); // print the sorted result
}

// This function searches item by ID
int SearchByID(const vector<Inventory>& inventoryList, int key) {
    // Linear search since we are only dealing with max 50 items
    int i;
    for (i = 0; i < inventoryList.size(); ++i) {
        if (inventoryList[i].getID() == key) {
            return i;
        }
    }
    return -1; // Not found
}

// This function searches item by name
vector<int> SearchByName(const vector<Inventory>& inventoryList, const string& nameKey) {
    vector<int> matches; // There could be multiple items with the same name, therefore I made an vecotor of all matching elements; function returns the matching elements
    
    for (int i = 0; i < inventoryList.size(); ++i) {
        if(inventoryList[i].getName() == nameKey) {
            matches.push_back(i);
        }
    }
    return matches;
}

// This functions list item by name in ascending order
void ListByName(const vector<Inventory>& inventoryList) {
    vector<Inventory> sortedList = inventoryList; // make a copy to modify
    
    // ZyBooks Selection Sort modified to use vectors and objects
    int i, j, indexSmallest;
    
    for (i = 0; i < sortedList.size() - 1; i++) {
        indexSmallest = i;
        for (j = i + 1; j < sortedList.size(); ++j) {
            if (sortedList[j].getName() < sortedList[indexSmallest].getName()) {
                indexSmallest = j;
            }
        }
        
        // Swap the whole objects
        Inventory temp = sortedList[i];
        sortedList[i] = sortedList[indexSmallest];
        sortedList[indexSmallest] = temp;
    }
    
    ListAllItems(sortedList); // print the sorted result
}

void ListByPrice(const vector<Inventory>& inventoryList) {
    vector<Inventory> sortedList = inventoryList; // make a copy to modify
    
    // ZyBooks Selection Sort modified to use vectors and objects
    int i, j, indexSmallest;
    
    for (i = 0; i < sortedList.size() - 1; i++) {
        indexSmallest = i;
        for (j = i + 1; j < sortedList.size(); ++j) {
            if (sortedList[j].getPrice() < sortedList[indexSmallest].getPrice()) {
                indexSmallest = j;
            }
        }
        
        // Swap the whole objects
        Inventory temp = sortedList[i];
        sortedList[i] = sortedList[indexSmallest];
        sortedList[indexSmallest] = temp;
    }
    
    ListAllItems(sortedList); // print the sorted result
}
