/* 
 * File:   main.cpp
 * Author: raikanarimani
 *
 * Created on October 1, 2012, 12:22 PM
 */

#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */
int main() 
{
    int base;
    int power;
    int result;
    
    
    cout << "Enter base: " << endl;
    
    cin>> base;
    
    while(base != 0)
    {
    
            cout << "Enter power: " << endl;

            cin >> power;

            result = pow(base,power);

            cout << "Result: " << result << endl;

            cout << "Enter base: " << endl;

            cin>> base;
    }
    
    return 0;
}

