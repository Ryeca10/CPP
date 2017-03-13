
/*
 
 * DATA STRUCTUTES LAB:
 * 
 * FALL 2013
 * 
 * Binary Tree Lab:
 * 
    Create a binary node struct class.
    -Data field
    Create a binary tree class.
    -Node array field (private)
    -Count field
    Add method(data)
    -The add method takes a data point, creates a node var/object and adds it to the count position in the array then increases the count.
    Print method(void)
    -Prints all the fields in the tree.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Node
{
    public:
        int weight;
};
    
class Tree
{
    public:
        
        Node array[20];
        int count;

        Tree()
        {
            count = 0;
        }

        bool Add(int num)
        {
            if(count == 0)
            {
                array[0].weight = num;
                count ++;
            } 
            
            else
            {
                array[count].weight = num;
                count ++;
            }
            return true;
        }

        void Print()
        {
            for (int i =0; i<count; i++)
            {
                cout<<array[i].weight<<endl;
            }
        }
};

int main ()
{
    Tree *tree = new Tree();
    
    int weight;
    
    
    cout<<"Enter the weight, enter -1 to exit: "<<endl;
    cin >> weight;
    
    while (weight != -1)
    {
    
            tree->Add(weight);
            cout<<"Enter the weight, enter -1 to exit: "<<endl;
            cin >> weight;
  
    }
    
    tree->Print();
    
    return 0;
}