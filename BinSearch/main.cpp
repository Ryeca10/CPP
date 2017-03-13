


/*
 * DARA STRUCTURES LAB:
 * FAll 2013
 * 
 *   Binary Search:
 * 
    Write a function that accepts a sorted array and searches the array in a 
    binary fashion, returning the index of the found element, or -1 if not found.
 */



#include <iostream>
using namespace std;



int BinSearch (int *array, int search, int arSize)
{
    int begin=0;
    int end=arSize;
    int middle=0;

    if ((arSize/2 + arSize/2) != arSize)
        
    {
     while( end >= begin) 
     {
       
         middle = (begin + end) / 2; 
       
       
        if (search > array[middle])
        {
           begin = middle + 1;  
        }
        
        else if (search < array[middle]) 
        {
           end = middle -1; 
        }
       
        else
           return middle;     
     }
    }
    
    else 
    {
        
    
     while( end >= begin) 
     {
       
         middle = (begin + end) / 2; 
       
       
        if (search > array[middle])
        {
           begin = middle + 1;  
        }
        
        else if (search < array[middle]) 
        {
           end = middle ; 
        }
       
        else
           return middle;     
     }
    }
    
     return -1;
    
    

}

int main ()
{
    int arSize;
    int *array = new int[arSize];
    int search;
    int index;

    cout<<"Enter array size: "<<endl;
    cin>>arSize;
    
    cout<<"Enter array components: "<<endl;

    for (int i = 0; i <arSize ; i++)
    {
        cin>>array[i];
    }
   
    cout << "Enter number to search for: ";
    cin >> search;
            
    index = BinSearch(array, search, arSize);
    cout<<"The number was found at index: "<<index<<endl;

    cout<<"The elements are: "<<endl;

    for (int i = 0; i < arSize; i++)
    {
        cout<<array[i]<<" ";
    }

    return 0;
}