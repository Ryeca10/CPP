#include <iostream>
using namespace std;

int main ()
{
    int arSize;
    int *array = new int[arSize];

    cout<<"Enter size for the array: "<<endl;
    cin>>arSize;

    for (int i = 0 ; i < arSize ; i++)
    {
        cout << "Enter array componant: ";
        cin>>array[i];
        if(array[i]==-1)
            
        return 0;
    }
   
    cout<<"Your array: "<<endl;

    for (int i = 0; i < arSize; i++)
    {
        cout<<array[i]<<" ";
    }

    cout<<endl;
    return 0;
}
