#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class IntDLLNode 
{
    public:

        int info;				
        IntDLLNode *last;		
        IntDLLNode *next;		


    IntDLLNode(int data, IntDLLNode *lastPtr = 0, IntDLLNode *nextPtr = 0) 
    {
            info = data; 
            last = lastPtr;
            next = nextPtr;
    }

};


class IntDLList 
{
    
private:
	
    IntDLLNode *head, *tail;


public:

	
    IntDLList() 
    {
        head = tail = 0;
    }

	
    ~IntDLList()
    {
		
        for (IntDLLNode *p; !isEmpty(); ) 
        {
                p = head->next;	
                delete head;	
                head = p;		
        }
    }

	
    
    
    
    
    bool isEmpty() 
    {
        return head == 0;
    }

    void addToHead(int data)
    {
		
        IntDLLNode *temp = new IntDLLNode(data, 0, head);
        if (head!=0)
                head->last = temp;
        head = temp;


        if (tail == 0)
           tail = head;
    }

    void addToTail(int data) 
    {
        if (tail != 0) 
        {   
                IntDLLNode *temp = new IntDLLNode(data, tail);

                tail->next = temp;

                tail = tail->next;
        }
        else 
                head = tail = new IntDLLNode(data);
    }

	
    int  deleteFromHead() 
    {
        int data = head->info;	
        IntDLLNode *tmp = head;	

        if (head == tail)		
                 head = tail = 0;	
        else 
        {
                head = head->next;	
                head->last = 0;		
        }

        delete tmp;				
        return data;			
    } 

	
    int  deleteFromTail() 
    {
            int data = tail->info;	
            if (head == tail)		
            {   
                    delete head;		
                    head = tail = 0;	
            }
            else					
            {         
                    IntDLLNode *temp = tail;
                    tail = tail->last;	
                    tail->next = 0;		
                    delete temp;		
            }
            return data;
    } 

    void deleteNode(int data) 
    {

            if (head != 0)                
            {
                    
                    if (head == tail && data == head->info)  
                    {
                           
                            delete head;                       
                            head = tail = 0;
                    }
                    else if (data == head->info)   
                    {
                            
                            IntDLLNode *temp = head;
                            head = head->next;		
                            head->last = 0;
                            delete temp;             
                    }
                    else                        
                    {
                            
                            IntDLLNode *temp;

                            
                            for (temp = head->next;						
                                    temp != 0 && !(temp->info == data);		
                                    temp = temp->next);						


                            if (temp != 0)					
                            {
                                    
                                    temp->last->next = temp->next;
                                   
                                    temp->next->last = temp->last;

                                    if (temp == tail)		
                                            tail = temp->last;

                                    delete temp;					
                            }
                    }
            }
    }

    bool isInList(int data) const 
    {
		
		IntDLLNode *tmp;
		
		for (tmp = head; tmp != 0 && !(tmp->info == data); tmp = tmp->next);
		
		return tmp != 0;
    }

    void printAll() const 
    {
		
		for (IntDLLNode *tmp = head; tmp != 0; tmp = tmp->next)
			cout << tmp->info << " ";
		cout << endl;
    }
}; 




class IntSortedDLList
{	
    private:
        IntDLLNode *head, *tail;
        
    public:
            IntSortedDLList()
            {
                    head = tail = 0;
            }

            void Insert(int data)
            {
                    IntDLLNode *newNode = new IntDLLNode(data);		
                    IntDLLNode *temp = head;						

                    if (head == 0)									
                    {						
                            head = tail = newNode;						
                            return;
                    }

                    while (temp->next != 0 && temp->info <= data)
                            temp = temp->next;							


                    if (head == tail)								
                    {
                            if (data < temp->info)						
                            {
                                    newNode->next = head;
                                    head->last = newNode;					
                                    head = newNode;
                            }
                            else										
                            {
                                    head->next = newNode;
                                    newNode->last = head;
                                    tail = newNode;
                            }
                    }
                    else if (temp == head)							
                    {

                            newNode->next = head;
                            head->last = newNode;
                            head = newNode;
                    }
                    else if (temp == tail)
                    {

                            if (data > tail->info)
                            {
                                    tail->next = newNode;
                                    newNode->last = tail;
                                    tail = newNode;
                            }
                            else
                            {
                                    newNode->next = tail;
                                    newNode->last = tail->last;
                                    tail->last->next = newNode;
                                    tail->last = newNode;
                            }
                    }
                    else											
                    {

                            newNode->next = temp;
                            newNode->last = temp->last;
                            temp->last->next = newNode;
                            temp->last = newNode;
                    }
            } // end insert

        void printAll() const 
        {
                
                cout << "DLL: ";
                for (IntDLLNode *temp = head; temp != 0; temp = temp->next)
                        cout << temp->info << " ";
                cout << endl;
        }

        void printBackwards() const 
        {
                
                cout << "From the tail DLL: ";
                for (IntDLLNode *temp = tail; temp != 0; temp = temp->last)
                        cout << temp->info << " ";
                cout << endl;
        }
}; 


int main (void)
{
	IntDLList *theList = new IntDLList();

	cout << "Adding 10" << endl;
	theList->addToHead(10);
	cout << "Adding 25" << endl;
	theList->addToHead(25);
	cout << "Adding 15" << endl;
	theList->addToHead(15);
	cout << "Adding 20" << endl;
	theList->addToHead(20);
	cout << "Adding 100" << endl;
	theList->addToHead(100);

	cout << "The list: ";
	theList->printAll();

	cout << "Adding 99" << endl;
	theList->addToTail(99);
	cout << "Adding 54" << endl;
	theList->addToTail(54);
	cout << "Adding 33" << endl;
	theList->addToTail(33);

	cout << "The list: ";
	theList->printAll();

	if (theList->isInList(33))
		cout << "Found 33" << endl;

	cout << "Deleting from head: " << theList->deleteFromHead() << endl;
	cout << "Deleting from the tail: " << theList->deleteFromTail() << endl;

	cout << "Deleting 100" << endl;
	theList->deleteNode(100);
	cout << "Deleting 100 again" << endl;
	theList->deleteNode(100);

	cout << "Is the list empty?? " << theList->isEmpty() << endl;
	cout << "Is 100 in the list?? " << theList->isInList(100) << endl;	
	
	cout << "The list: ";
	theList->printAll();

	IntSortedDLList sortedDLL;
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
	{
		int data = rand() % 100;
		cout << "Adding " << data << endl;
		sortedDLL.Insert(data);
		sortedDLL.printAll();
		sortedDLL.printBackwards();
	}

	return 0;
}
