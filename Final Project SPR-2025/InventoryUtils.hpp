// These are the function prototypes separated into its own file

#ifndef InventoryUtils_hpp
#define InventoryUtils_hpp

#include <vector>
#include <string>
#include "Inventory.hpp"

vector<Inventory> ImportInventory(); // This is a vector(like an array) of Inventory type objects
void PrintMenu(const vector<Inventory>& inventoryList, string nameKey, int key);
void ListAllItems(const vector<Inventory>& inventoryList);
void ListAscendingID(const vector<Inventory>& inventoryList);
vector<int> SearchByName(const vector<Inventory>& inventoryList, const string& nameKey); // Returns the index of the item
int SearchByID(const vector<Inventory>& inventoryList, int key); // Returns the index of the item
void ListByName(const vector<Inventory>& inventoryList);
void ListByPrice(const vector<Inventory>& inventoryList);


#endif /* InventoryUtils_hpp */
