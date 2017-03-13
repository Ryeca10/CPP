#include <iostream>
using namespace std;

const int MAX=10;

struct Que
{
    int front;
    int back;
    int queue[MAX];
    int count;
}que;

bool IsEmpty ()
{
    if (que.count==0)
        return true;
    else
        return false;
}

void Init()
{
    que.count = 0;
    que.front = 0;
    que.back = 0;
}

void Enque(int num)
{
    if (que.back == MAX -1)
        {
            que.queue[que.back] = num;
            que.back = 0;
            que.count++;
        } 
    
    else
        {
            que.queue[que.back] = num;
            que.back ++;
            que.count++;
        }
}

int Deque()
{
    if (!IsEmpty())
    {
        int front = que.queue[que.front];
        que.count--;
        que.queue[que.front] = 0;
        if (que.front ==  MAX-1)
        {
            que.front = 0;
        } 
        
        else
        {
            que.front++;
        }
        
        return front;
    }
    else cout<<"Array EMPTY!"<<endl;
}

int main ()
{
    int num;
    
    for (int i = 0 ; i < MAX ; i++)
    {
        cout << "Enter to Enqueue: ";
        cin >> num;
        Enque(num);
    }
  
    for (int i = 0; i < MAX ; i++)
    {
        cout<<Deque()<<endl;
    }

    return 0;
}
