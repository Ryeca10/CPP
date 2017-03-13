#include <iostream>

using namespace std;

int main()
{
    int eax = 1;
    int ebx = 100;
    int store_eax = 0;
    
    while(eax <= 100000)
    {
        
        store_eax++;
        eax++;
        ebx += 4;
        
        
     
    }
    
    return 0;
}


