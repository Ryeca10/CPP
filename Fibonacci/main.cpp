/* 
 * File:   main.cpp
 * Author: raikanarimani
 *
 * Created on September 30, 2012, 8:45 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() 
{

    int sentence;
    int fst = 1;
    int snd = 1;
    int fibNum;
    
    cout << "Enter the sentence in Fibonacci series( -1 to exit ): " << endl;
    
    while(cin >> sentence)
    {
        if (sentence == 1 || sentence == 2 )
        {
            fibNum = 1;
        }
        
        
        else 
        {
            for (int i = 3 ; i <= sentence ; i++)
            {
               fibNum = fst + snd;
               
               fst = snd;
               snd = fibNum;
            }
        }
        
        cout << "Result: " << fibNum << endl;
    
    }
    return 0;
}

