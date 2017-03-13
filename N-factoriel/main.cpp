/* 
 * File:   main.cpp
 * Author: raikanarimani
 *
 * Created on September 30, 2012, 8:17 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() 
{
    int n;
    int nFac;
    
    
    cout << "Enter n, press -1 to exit. " << endl;
    
    while(cin >> n)
    {
    
        nFac = n;

        if (n==0)
        {
            nFac = 1;
        }
        
        else if(n == -1)
        {
            break;
        }
        
        else
        {
            for (int i = n-1 ; i >1 ;i--)
            {
                nFac *= i;
            }
        }
        
        cout <<"result: "<< nFac << endl << endl;
       
        
    }
    return 0;
}

