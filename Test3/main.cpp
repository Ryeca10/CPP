#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class stock
{
        private:
		char name[20];
		float sh, bp, cp, cost, value, prof;

	public:
		stock(char * = " ", float = 0.0 , float = 0.0 , float = 0.0 );
		~stock();
		void print();
		void calc(float);  //parameter is change in price
	
};

stock::stock(char *n, float s , float b , float c )
{
	strcpy(name, n);
	sh = s;
	bp = b;
	cost = sh * bp;
	value = sh * cp;
	prof = value - cost;
}

stock::~stock()		//deconstructor
{
	cout<< name << "is destroyed" << endl;
}

void stock::print()
{
	cout << setprecision(2)<<showpoint<<fixed;
	cout<<"name: "<< name <<endl;
	cout<<"shares: "<< sh <<endl;
	cout<<"buy price: "<< bp <<endl;
	cout<<"current price: "<< cp <<endl;
	cout<<"cost: "<< cost <<endl;
	cout<<"value: "<< value << endl;
	cout <<"profit: "<< prof << endl << endl;
}
void stock:: calc(float change)
{
	cp += change;
	value = sh * cp;
	prof = value - cost;
}
int main()
{
	stock s("Joe's tech", 150, 69.34, 77.55);
	s.print();
	cout<<"enter change in the current price";
	float ch;
	cin>>ch;
	s.calc(ch);
	s.print();

	return 0;
}