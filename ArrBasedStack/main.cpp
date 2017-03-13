
/* Data Structures LAB:
 * Fall 2013
 * 
 *          Array Based Stack
            Create a class/struct.

            Members:
            MaxSize const = 10
            Define an array that holds 10 items.
            Count - indicates how many items are on the stack.

            Methods:
            Push
            - Accepts a number and adds to the top of the stack.
            - If the stack is full emit an error indicating full.
            Pop
            - Returns a number from the top of the stack.
            - If the stack is empty, emit an error indicating the stack is empty.
            IsEmpty
            - Returns a boolean indicating if the stack is empty.
 */


#include <iostream>
using namespace std;

const int MAX=10;

struct Stack
{
    int array[MAX];
    int count;
} stack;

bool IsEmpty ()
{
    if (stack.count==0)
        return true;
    else
        return false;
}


void Push(int num)
{
    
    if (stack.count == MAX)
        cout << "Stack is full" << endl;
    else
    {
    stack.array[stack.count] = num;
    stack.count++;
    }
    
        
}

int Pop()
{
    if (IsEmpty())
    {
        cout<<"Array EMPTY!"<<endl;
    }
    else 
    {
        stack.count--;
        return stack.array[stack.count];
    }
}

int main()
{
    int num;
    int count = 0;

    while (num != -1 && count < MAX)
    {
        cout << "Enter number to stack, enter -1 to exit: " <<endl;
        cin >> num;
        ++count;
        Push(num);
    }
    for (int i = 0 ; i < MAX ; i++)
    {
         cout<<Pop()<< " is poped" <<endl;
    }
    


    return 0;
}
