#include<iostream>
using namespace std;


int ReturnIndex(int *array, int SIZE)
{
    int search;
    
    cout << "Enter eement to search for: ";
    cin >> search;
    for (int i = 0 ; i < SIZE; i++)
    {
        if (search==array[i])
        {
            return i;
        }
    }
    
    return -1;
}


int main()
{
    int *arr;
    int size;
    
    cout << "Enter array size: ";
    cin >> size;
    for (int i = 0 ; i < size; i++)
    {
        cout << "Enter array element: ";
        cin >> arr[i];
    }
    
    cout << "The element is at index: " << ReturnIndex(arr,size);
    
    return 0;
}