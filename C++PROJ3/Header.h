/*
   C++ 3rd project
 * 
 * Operator Overloading
 * 
 * FALL 2013
 
 */

#ifndef HEADER_H
#define	HEADER_H


#include <iostream>
using namespace std;



class Fraction
{
    friend istream &operator >> (istream &, Fraction &);
    friend ostream &operator << (ostream &, Fraction const &);
    
public:
    

    Fraction operator + (const Fraction &) const;
    Fraction operator - (const Fraction &) const;
    Fraction operator * (const Fraction &) const;
    Fraction operator / (const Fraction &) const;
    Fraction operator -- ();
    Fraction operator -- (int);
    bool operator == (const Fraction &) const;
    bool operator != (const Fraction &) const;
    void Simplify();
    Fraction Recipricol();
    
private:
    
    int numerator, denominator;
    double decimal;
    
};


istream &operator >> (istream &input, Fraction &f)
{
    input >> f.numerator >> f.denominator;
    
    while (f.denominator == 0)
    {
        cout << "denominator has to be non-zero. Re-enter denominator: ";
        input >> f.denominator;
    }
    
    return input;
}

ostream &operator << (ostream &output, const Fraction &f)
{
    output << f.numerator << "/" << f.denominator;
    
    return output;
}

Fraction Fraction :: operator + (const Fraction &rhs) const
{
    Fraction result;
    
    result.denominator = denominator * rhs.denominator;
    result.numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    
    result.Simplify();
    
    return result;
}

Fraction Fraction :: operator - (const Fraction &rhs) const
{
    Fraction result;
    
    result.denominator = denominator * rhs.denominator;
    result.numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    
    result.Simplify();
    
    return result;
}

Fraction Fraction :: operator * (const Fraction &rhs) const
{
    Fraction result;
    
    result.denominator = denominator * rhs.denominator;
    result.numerator = numerator * rhs.numerator;
    
    result.Simplify();
    
    return result;
}

Fraction Fraction :: operator / (const Fraction &rhs) const
{
    Fraction result;
    
    result.denominator = denominator * rhs.numerator;
    result.numerator = numerator * rhs.denominator;

    result.Simplify();
    
    return result;
}

Fraction Fraction :: operator --()
{
    Fraction result;
    
    result.numerator  = numerator - denominator;
    result.denominator = denominator;

    result.Simplify();
    
    return result;
}

Fraction Fraction :: operator -- (int)
{
    Fraction tmp = *this;
 
    Fraction result;
    
    result.numerator = numerator - denominator;
    result.denominator = denominator;

    result.Simplify();
    
    return tmp;
}

bool Fraction :: operator == (const Fraction &rhs) const
{
    if (numerator * rhs.denominator == denominator * rhs.numerator)
        
        return true;
    else
        return false;
}

bool Fraction :: operator != (const Fraction &rhs) const
{
    
    if (numerator * rhs.denominator != denominator * rhs.numerator)
        return true;
    else 
        return false;
}



void Fraction :: Simplify()
{
    int gcf = min(denominator, numerator);
    for (int i = abs(gcf); i > 1  ; i--)
    {
        if ((numerator % i == 0) && (denominator % i == 0))
        {
            numerator /= i;
            denominator /= i;
        }
    }
}

Fraction Fraction :: Recipricol()
{
    Fraction result;
    
    int tmp = numerator;
    
    result.numerator = denominator;
    result.denominator = tmp;
    
    result.Simplify();
    
    return result;
}





#endif	/* HEADER_H */

