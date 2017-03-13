#include<iostream>
#include<iomanip>
using namespace std;


class Frac
{
	private:
		int Num;
		int Den;
 
    public:

		Frac();
                
		~Frac();

		void SetData(int num, int den);
		
		void SetNum(int num);
		

		void SetDen(int den);


		void Add(Frac f1, Frac f2);

		void Sub(Frac f1, Frac f2);

		void Multip(Frac f1, Frac f2);
	

		void Div(Frac f1, Frac f2);

                
                void Print();
                void GetData(Frac &f1, Frac &f2);
 
};

Frac:: Frac()
{
}
Frac:: ~Frac()
{
}


void Frac::SetData(int num, int den)
{
        SetNum(num);
        SetDen(den);
}

void Frac:: SetNum(int num)
{
        Num = num;
}

void Frac:: SetDen(int den)
{
        Den = den;
}

void Frac:: Add(Frac f1, Frac f2)
{
        Den = f1.Den * f2.Den;
        Num = f1.Num * f2.Den + f2.Num * f1.Den;
}

void Frac:: Sub(Frac f1, Frac f2)
{
        Den = f1.Den * f2.Den;
        Num = f1.Num * f2.Den - f2.Num * f1.Den;
}

void Frac:: Multip(Frac f1, Frac f2)
{
        Den = f1.Den * f2.Den;
        Num = f1.Num * f2.Num;
}

void Frac:: Div(Frac f1, Frac f2)
{
        int tmp = f2.Num;
        f2.Num = f2.Den;
        f2.Den = tmp;

        Den = f1.Den * f2.Den;
        Num = f1.Num * f2.Num;


}


void Frac :: Print()
{
    int min;
    float dec;

    if (Num > Den)
    {
        min = Den;
    }
    else
    {
        min = Num;
    }
    for (int i = abs(min) ; i > 1 ; i--)

    {

        if (Num % i == 0 && Den % i == 0)
        {
            Num /= i;
            Den /= i;
        }


    }

    dec =  float(Num) / Den;

    cout << fixed << setprecision(2);
    cout << Num  <<"/"<< Den;
    cout <<  ", or " << dec << endl;

}

void Frac :: GetData(Frac &f1, Frac &f2)
{
        int num1, num2, den1, den2;
        
        cout << "Enter Fraction 1: " << endl;
        cin >> num1;
        cin >> den1;       
        
        f1.SetData(num1, den1);
 
        
        
        cout << "Enter Fraction 2: " << endl;
        cin >> num2;
        cin >> den2; 
        
        f2.SetData(num2, den2);
}



int main()
{
	Frac Frac1, Frac2;
	Frac add, sub, mul, div;
        
        Frac1.GetData(Frac1, Frac2);
	add.Add(Frac1, Frac2);
	sub.Sub(Frac1, Frac2);
	mul.Multip(Frac1, Frac2);
	div.Div(Frac1, Frac2);
        
        cout << "Fraction Sum: "; 
        add.Print();
        
        cout << "Fraction Subtract: ";
        sub.Print();
        
        cout << "Fraction Product: " ;
        mul.Print();
        
        cout << "Fraction Division: ";
        div.Print();

	return 0;
}

/*
Enter Fraction 1: 
1 2
Enter Fraction 2: 
3 4
Fraction Sum: 5/4, or 1.25
Fraction Subtract: -1/4, or -0.25
Fraction Product: 3/8, or 0.38
Fraction Division: 2/3, or 0.67

RUN SUCCESSFUL (total time: 10s)

 */