#include <iostream>
using namespace std;


int ComponentIndex(int *arr)
{
    int searchNum;
    
    cout << "Enter number to search for: " << endl;
    cin >> searchNum;
    
    for (int i = 0 ;  i < sizeof(arr) ; i++)
    {
        if (arr[i] == searchNum)
            return i;
    }
    return -1;
}


int main()
{
    int *array;
    int index;
    
    cout << "Enter the array components: " << endl;
    for (int i = 0 ; i < sizeof(array) ; i++)
    {
        cin >> array[i];
    }
    
    index = ComponentIndex(array);
    
    if(index == -1)
        cout << "The number you entered is not in the array. " << endl;
    else
        cout << "The number was found at index: " << index << endl;
    
    return 0;
}
