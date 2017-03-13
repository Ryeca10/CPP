#include <iostream>
using namespace std;

const int SIZE = 19;    
const int EMPTY = -1;    


class HashTable
{
    int Table[SIZE];    



    int Hash (int num)
    {
        int hash = num % SIZE;
        return hash;
    }

    
        bool Probe(int num) 
    {
        int index = num % SIZE;
        int norm = (index + 1) % SIZE; 
        while (index != norm)
        {
          
            if (Table[norm] == EMPTY)
            {
           
                Table[norm] = num;
                return true;
            }
            
            norm = ++norm % SIZE; 
        }

        return false;  
    }
        



public:
    HashTable()
    {

        for (int i = 0; i < SIZE; i++)
            Table[i] = EMPTY;
    }


    bool Search(int num)
    {
        int search;
        for (int i=0; i <= SIZE; i++)
        {
            if (Table[i] != num)
                search = false; 
            else
                return true;
        }
    }
    
    bool Insert(int num)
    {

        if (Table[Hash(num)] == EMPTY) 
        {

            Table[Hash(num)] = num;
            return true;
        }
        else
            return Probe(num);
    }
    
};



int main ()
{
    int num;
    int search;
    HashTable *Table = new HashTable();

    cout << "Insert number: " ;
    cin >> num;
    
    while(Table->Insert(num) && num != -1)
    {
        cout << "Insert number: " ;
        cin >> num;
    }
    
    cout << "Enter a number to search for: ";
    cin >> search;

            
    if (Table->Search(search))
        cout << "the number is in the table" << endl;
    else 
        cout << "the number is not in the table" << endl;
            
            
     

    return 0;
}  