#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node
{
public:

    int info;            
    Node *prev;        
    Node *next;        

    Node(int data, Node *prevPtr = NULL, Node *nextPtr = NULL) 
    {
        info = data; 
        prev = prevPtr;
        next = nextPtr;
 
    }
};


class List 
{
private:

    Node *head, *tail;
    int count;
public:

    List() 
    {
        head = tail = 0;
        count  = 0 ;
    }


    void AddTail(int data) 
    {
        if (tail != 0) 
        {      
            Node *temp = new Node(data, tail);
           
            tail->next = temp;
           
            tail = tail->next;
        }
        else 
            head = tail = new Node(data);
    }


 
    int  DeleteTail() 
    {
        int data = tail->info;   
        if (head == tail)        
        {   
            delete head;        
            head = tail = 0;   
        }
        else                    
        {         
            Node *temp = tail;  
            tail = tail->prev;
            tail->next = 0;     
            delete temp;        
        }
        return data;
    } 

    bool IsEmpty ()
        {
            if (count==0)
                return true;
            else
            return false;
        }

void Push(int val)
{
    AddTail(val);
    count++;
}

int Pop()
{
    if (!IsEmpty())
    {
        int x = tail->info;
        count--;

        DeleteTail();
        return x;
    }

}


};
int main ()
{
    List *list = new List();
    int num;
    int count = 0;
    
    
    cout << "enter to stack: " ;
    cin >> num;
    while(num != -1)
    { 
        count ++;
        list->Push(num);
        
        cout << "enter to stack: " ;
       cin >> num;
        
    }
    

    for (int i = 0 ; i< count ; i++)
        cout <<list->Pop() << "was poped.";
    

 
    return 0;
}
