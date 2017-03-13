#include<iostream>
#include<iomanip>
using namespace std;


class Fraction
{
	private:
		int numerator;
		int denominator;
                double decimal;
    public:

		Fraction();
		~Fraction();
		void SetData(int nume, int den);
		void SetNume(int nume);
		void SetDen(int den);
		int GetNume();
		int Getden();
		void GetData(int nume , int den);
		void Addition(Fraction frac1, Fraction frac2, Fraction &sum);
		void Subtraction(Fraction frac1, Fraction frac2, Fraction &Diff);
		void Multiplication(Fraction frac1, Fraction frac2, Fraction &Prod);
		void Division(Fraction frac1, Fraction frac2, Fraction &Quo);
                void Print();
};

Fraction::Fraction()
{
}
Fraction::~Fraction()
{
}


void Fraction ::SetData(int nume, int den)
{
        SetNume(nume);
        SetDen(den);
}

void Fraction::SetNume(int nume)
{
        numerator = nume;
}

void Fraction::SetDen(int den)
{
        denominator = den;
}

int Fraction::GetNume()
{
        return numerator;
}

int Fraction::Getden()
{
        return denominator;
}

void Fraction::GetData(int nume , int den)
{
        numerator = nume; 
        denominator = den;
}


void Fraction::Addition(Fraction frac1, Fraction frac2, Fraction &sum)
{
        sum.denominator = frac1.denominator * frac2.denominator;
        sum.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
}

void Fraction::Subtraction(Fraction frac1, Fraction frac2, Fraction &Diff)
{
        Diff.denominator = frac1.denominator * frac2.denominator;
        Diff.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
}

void Fraction:: Multiplication(Fraction frac1, Fraction frac2, Fraction &Prod)
{
        Prod.denominator = frac1.denominator * frac2.denominator;
        Prod.numerator = frac1.numerator * frac2.numerator;
}

void Fraction::Division(Fraction frac1, Fraction frac2, Fraction &Quo)
{
        int tmp = frac2.numerator;
        frac2.numerator = frac2.denominator;
        frac2.denominator = tmp;

        Quo.denominator = frac1.denominator * frac2.denominator;
        Quo.numerator = frac1.numerator * frac2.numerator;


}


void Fraction::Print()
{
    int small = min(numerator, denominator);

    for (int GCD = abs(small) ; GCD > 1 ; GCD--)

    {

        if (numerator % GCD == 0 && denominator % GCD == 0)
        {
            numerator /= GCD;
            denominator /= GCD;
        }


    }

    decimal =  float(numerator) / float(denominator);

    cout << fixed << setprecision(2);
    cout << numerator <<"/"<< denominator<< " = " << decimal << endl;

}
                

int main()
{
	Fraction Frac1, Frac2;
	Fraction Sum, Diff, Prod, Quo;
        int nume1, nume2, den1, den2;
        
        cout << "Enter Numerator of Fraction One: " << endl;
        cin >> nume1;
        
        cout << "Enter Denominator of Fraction One: " << endl;
        cin >> den1;
        
        Frac1.SetData(nume1, den1);
 
        cout << "Enter Numerator of Fraction Two: " << endl;
        cin >> nume2;
        
        cout << "Enter Denominator of Fraction Two: " << endl;
        cin >> den2;
        
        Frac2.SetData(nume2, den2);
        
	Sum.Addition(Frac1, Frac2, Sum);
	Diff.Subtraction(Frac1, Frac2, Diff);
	Prod.Multiplication(Frac1, Frac2, Prod);
	Quo.Division(Frac1, Frac2, Quo);
        
        cout << "The sum of fractions: "; 
                Sum.Print();
        cout << "The difference of fractions: ";
        Diff.Print();
        cout << "The product of fractions: " ;
        Prod.Print();
        cout << "The division of fractions: ";
        Quo.Print();

	return 0;
}

/*
Enter Numerator of Fraction One: 
2
Enter Denominator of Fraction One: 
4
Enter Numerator of Fraction Two: 
6
Enter Denominator of Fraction Two: 
9
The sum of fractions: 7/6
The difference of fractions: -1/6
The product of fractions: 1/3
The division of fractions: 3/4

RUN SUCCESSFUL (total time: 6s)

 */