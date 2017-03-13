/* 
 * File:   main.cpp
 * Author: raikanarimani
 *
 * Created on October 1, 2012, 11:59 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() 
{
    int num;
    int result = 1;
    
    cout << "Enter number: " << endl;
    
 

    while(cin>>num)
    {
        result *= num;
    
    

            char check = cin.get();

            if(num == 0 && check == '\n')
            {
                break;
            }

            else if(check == '\n')
            {
                cout << "Result: " << result << endl;
            }
    
    }
    return 0;
}

