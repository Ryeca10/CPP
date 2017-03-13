
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Fraction frac, frac1 , frac2, sum, diff, mult, div;
    double decimal;
    
    cout << "Enter fraction one : " ;
    cin >> frac1;
    
    cout << "Enter fraction two : " ;
    cin >> frac2;
    
    cout << "Fraction one is: " << frac1 << endl;
    cout << "Fraction two is: " << frac2 << endl;
    
    sum = frac1 + frac2;
    diff = frac1 - frac2;
    mult = frac1 * frac2;
    div = frac1 / frac2;
    
    cout << "The sum is: " << sum << endl;
    cout << "The difference is: " << diff << endl;
    cout << "The multiple is: " << mult << endl;
    cout << "The division is: "  << div << endl;
    
    cout << "Enter new fraction: ";
    cin >> frac;
    cout << "The pre-increment is : " << --frac << endl;
    
    
    cout << "Enter new fraction: ";
    cin >> frac;
    cout << "The post-increment of fraction two is: " << frac-- << endl;
    
    cout << "Enter two fractions to compare: " << endl;
    cout << "Enter fraction one: ";
    cin >> frac1;
    cout << "Enter fraction two: ";
    cin >> frac2;
    
    if (frac1 == frac2)
        cout << "The two fractions are equal. " << endl;
    else if (frac1 != frac2)
        cout << "The two fractions are un-equal. " << endl;
    
    cout << "Enter a fraction: ";
    cin >> frac;
    
    cout << "The reciprocal of the fraction is: " << frac.Recipricol() <<endl;
    
    return 0;
}
