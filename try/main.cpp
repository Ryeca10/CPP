#include <iostream>
using namespace std;

int main()
{
    
    int arr[10] = { 23, 54 , 12, 71 , 10, 31, 81, 3, 41,9 };
    
    int i,j;
    

    for (i = 0 ; i <10; i++)
        for(j=0;j<10;j++)
        {
            while(arr[j]>arr[j+1]) 
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
  
    for(i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
        
    }

    
    return 0;
}