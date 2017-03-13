
#include<iostream>
using namespace std;

class Node
{
    Node(int )
    {
        int nodeWeight;
    }
};


class MinHeap
{
   private:

        Node *heapMem;
        int count;
   
   public:

        MinHeap()
        {
            heapMem = NULL;
            count = 0;
        }

        
        void Add(int weight)
        {
            Node *node ;
            
            if(heapMem == NULL)
            {
                heapMem.nodeWeight = weight;
                count++;
            }
            
           
            
        }
        
        void Delete()
        {
            
        }
};



int main()
{
    
    int weight;
    MinHeap *tree= new MinHeap();
    
    while (weight != -1)
    {
        cout << "Enter data: ";
        cin >> weight;
    }
    
    tree->Add(weight);
    return 0;
}