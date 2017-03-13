#include <iostream>
using namespace std;

class LinkedList
{
public:
    int num;
    LinkedList *next;
    
    LinkedList(int n , LinkedList *nextNum = NULL)
    {
        num = n;
        next = nextNum;
    }     
};

class List
{
    LinkedList *head, *tail;
    LinkedList *nextInt;
public:
    
    List()
    {
        head = tail = NULL;
    }
    void MakeList()
    {
        int num;
        
        cout << "Enter number to add to list: ";
        cin >> num;

        while( num != -1)
        {
            

            LinkedList *node = new LinkedList(num,nextInt = NULL);

            if (!head)
            {
                head = tail = node;
            }
            else if (num < head->num)
                
            {
                LinkedList *tmp = head;
                head = node;
                node->next = tmp;
            }
            else if (num > tail->num)
            {
                LinkedList *tmp = tail;
                tail = node;
                tmp->next = tail;
            }
            
            else
                
                for (LinkedList *tmp = head ; head != tail ; tmp = tmp->next)
                {
                    if (num > tmp->num && num <= tmp->next->num)
                    {
                        LinkedList *tmp1 = tmp->next;
                        tmp->next = node;
                        node->next = tmp1;
                    }
                }
            
            cout << "Enter number to add to list: ";
            cin >> num;
        }
        cout << "End of the list. ";
    } 
    
    void Print()
    {
        cout << "The list: " << endl;
        for (LinkedList *tmp = head ; tmp != NULL ; tmp = tmp->next)
            cout << tmp->num << " ";
    }
};


int main()
{
    List *list;
    
    list->MakeList();
    list->Print();
    
    return 0;
}