/* 
 * 
Create a hash table class/struct.
Define an array that holds 19 elements.
Define a function called Hash(int)
-This function returns the module of that int by the size of the table (array).
Define an add function that takes an integer.
-This function takes the integer, determines the hash of that number by calling the above hash function, then adds it to the table using linear probing for collision resolution.
Define a function that looks up a value, it takes an integer, return -1 if the value is not in the table.
*/


#include <iostream>

using namespace std;

const int SIZE = 19;    // a good strong prime number    
const int EMPTY = -1;    // -1 indicates that the cell is empty
#define DISPLAY true    // remove to disable debugging output

class HashTable
{
    int table[SIZE];    // where our data will be held

    bool Probe(int data) // linear probing function
    {
        int index = data % SIZE;
        int probeFcn = (index + 1) % SIZE; // start of the linear probing

        while (index != probeFcn)
        {
            #ifdef DISPLAY
                cout << "Probing at " << probeFcn << ". ";
            #endif
            if (table[probeFcn] == EMPTY)
            {
                #ifdef DISPLAY
                    cout << "Inserted.\n";
                #endif
                table[probeFcn] = data;
                return true;
            }
            
            probeFcn = ++probeFcn % SIZE; // continuation of linear probing
        }
        #ifdef DISPLAY
            cout << "Table is full. " << endl;
        #endif
        return false; // to get here index == probeFcn, which means we looped all the way around,
        // therefore the table is full
    }

    int Hash(int data)
    {
        int hash = data % SIZE;
        return hash;
    }

public:
    HashTable()
    {
        #ifdef DISPLAY
            cout << "Building hash table.\n";
        #endif
        for (int i = 0; i < SIZE; i++)
            table[i] = EMPTY;
    }

    bool Insert(int data)
    {
        #ifdef DISPLAY
            cout << "Inserting " << data << " at ";
        #endif
        if (table[Hash(data)] == EMPTY) // apply the hash function first
        {
            #ifdef DISPLAY
                cout << Hash(data) << endl;
            #endif
            table[Hash(data)] = data;
            return true;
        }
        else //otherwise we need to probe
            return Probe(data);
    }

    bool Search(int integer)
    {
        bool check;
        for (int i=0; i <= SIZE; i++)
        {
            if (table[i] == integer)
               check = true; //1 if found, -1 if not
            else
               check = false;
        }
        return check;
    }
};

int main ()
{
    HashTable *integer = new HashTable();
    int size;
    int num;
    int searchNum;
    
    cout << "How many integers: " << endl;
    cin >> size;
    
    for (int i = 0 ; i < size ; i++)
    {
        cout << "Enter integer: ";
        cin >> num;
        integer->Insert(num);
    }
    
    cout << "Enter a number to search for: ";
    cin >> searchNum;
    
    if (integer->Search(searchNum) == true)
        cout << "The number is in the table. ";
    else
        cout << "The number is in NOT the table";
    return 0;
}