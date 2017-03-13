/* 
 * File:   main.cpp
 * Author: raikanarimani
 *
 * Created on October 14, 2012, 5:44 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() 
{
int valueToSquare;
int* valueToSquarePtr;
int* squaredResultPtr; 
valueToSquarePtr = &valueToSquare; 
squaredResultPtr = NULL;
cout << "Enter an integer: "; 
cin >> *valueToSquarePtr;
squaredResultPtr = new int;
if(squaredResultPtr == NULL) 
{
cout<< "out of Memory!"; 
}
else
{
*squaredResultPtr = *valueToSquarePtr * *valueToSquarePtr; 
cout<< "Your value is: "<< *squaredResultPtr;
}
delete squaredResultPtr;

return 0;
}
