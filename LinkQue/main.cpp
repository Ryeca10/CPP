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


    Node(int data, Node *prevPtr = 0, Node *nextPtr = 0) 
    {
        info = data; 
        prev = prevPtr;
        next = nextPtr;
       
    }
};

class List 
{
private:
    int count;
    Node *front, *back;
public:

    List() 
    {
        front = back = 0;
        count = 0;
    }

    bool IsEmpty ()
    {
        if (count==0)
            return true;
        else
        return false;
    }

    void AddQ(int data) 
    {
        if (back != 0) 
        {      
            Node *temp = new Node(data, back);
           
            back->next = temp;
           
            back = back->next;
        }
        else 
            front = back = new Node(data);
    }

    int  DelHead() 
    {
        int data = front->info;   
        Node *tmp = front;    

        if (front == back)      
             front = back = 0;    
        else 
        {
            front = front->next;    
            front->prev = 0;      
        }

        delete tmp;              
        return data;           
    } 


void Enque(int val)
{
    AddQ(val);
    count++;
}

int Deque()
{
    if (!IsEmpty())
    {
        int x=0;
        count--;
        x=DelHead();
        return x;
    }
    else cout<<"Empty list"<<endl;
}


};


    

int main ()
{
    List *list = new List();
    int num, count = 0;
 
    cout << "Enter to queue: ";
    cin >> num;
    
    while (num != -1)
    {
        count++;
        list->Enque(num);
        cout << "Enter to queue: ";
        cin >> num;
    }

    for(int i = 0 ; i < count ; i++)
    {
        cout << list->Deque() << " left! " << endl;
    }

    return 0;
}