#include <iostream>
#include "fraction.h"
using namespace std;


int main()
{
	fraction val1, val2, sum, difference, product, quotient;

	cin>>val1>>val2;
	cout<<"For your first entered fraction, we have: "<<val1<<endl;
	cout<<"For your second entered fraction, we have: "<<val2<<endl;

	sum=val1+val2;
	difference=val1-val2;
	product=val1*val2;
	quotient=val1/val2;

	cout<<"The sum of both fractions equals: "<<sum<<endl;
	cout<<"The first fraction subtracted by the second equals to: "<<difference<<endl;
	cout<<"Both fractions multiplied equal: "<<product<<endl;
	cout<<"The first fraction divided by the second equals to: "<<quotient<<endl;

	cout<<endl;
	cout<<--val1; //Ask about cascading this and the below couts
	cout<<val1--;
	cout<<val1;
				      //Ask about cascading the above couts
	if(val1==val2)
		cout<<"Both fractions you entered, in the beginning of the program, are equal."<<endl;
	else if(val1!=val2)
		cout<<"Both fractions you entered, in the beginning of the program, are not equal."<<endl;
	else
		cout<<"You'll never get here to this message!"<<endl;

	system("PAUSE");
	return 0;
}
/*OUTPUT:
Please enter a fraction. Enter with the following format: Y/X
15/2
Please enter a fraction. Enter with the following format: Y/X
20/6
For your first entered fraction, we have: 15/2 aka 7.5

For your second entered fraction, we have: 10/3 aka 3.33333

The sum of both fractions equals: 65/6 aka 10.8333

The first fraction subtracted by the second equals to: 25/6 aka 4.16667

Both fractions multiplied equal: 25

The first fraction divided by the second equals to: 9/4 aka 2.25


2/15 aka 0.133333
2/15 aka 0.133333
15/2 aka 7.5
Both fractions you entered, in the beginning of the program, are not equal.
Press any key to continue . . .
*/

/*
double gcd_euclid(double a_numerator,double b_denominator) //WORKS! Put in class and run. You will get the GCD!!!
    if(a_numerator==0)
       return b_denominator;
    while(b_denominator!=0)
	{
        if(a_numerator>b_denominator)
           a_numerator-=b_denominator;
        else
           b_denominator-=a_numerator;
	}
    return a_numerator; //This will be the greatest common divisor that you can use to divide both the numerator and the denominator by for the sake of simplifying the fraction.
	//if there is a negative, you will have to accomidate for the negative and take it out. When you get the GCD you can then put the negative back in and divide by the GCD.
*/

