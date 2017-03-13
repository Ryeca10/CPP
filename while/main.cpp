/* 
 * File:   main.cpp
 * Author: raikanarimani
 *
 * Created on October 26, 2012, 1:53 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() 
{

    int num ;
    
    printf("Enter num: \n");
    scanf("%d",&num);
    
    do
    {
        printf("Entered loop\n");
        
        printf("Enter num: \n");
        scanf("%d",&num);
    
        
    }   
    
    while (num > 5 || num <1);
    
    printf("Out of loop");
    
    return 0;
}

