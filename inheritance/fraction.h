#include <iostream>
using namespace std;

class fraction
{
	friend istream &operator>>(istream &, fraction &); //You must bring the stream back in with the &. And since we are returning the istream ITSELF, we need an &.
	friend ostream &operator<<(ostream &, fraction const &);
public:
	fraction operator+(const fraction &) const; //const keeps the current objects variables of numerator, denominator, and decimal (left hand object) unmodifiable
	fraction operator-(const fraction &) const; //experiment with deleting the & all together here
	fraction operator*(const fraction &) const;
	fraction operator/(const fraction &) const;
	fraction &operator--();//predecrement [recipricol for this program]
	fraction operator--(int);//postdecrement (Need dummy int parameter to specify that) [recipricol for this program]
	bool operator==(const fraction &) const;
	bool operator!=(const fraction &) const;
	void recipricol();
	void simplify();
private:
	int numerator, denominator;
	double decimal;
};


bool fraction::operator==(const fraction &rhs) const
{
	int val1_denom=denominator, val1_numerat=numerator, val2_denom=rhs.denominator, val2_numerat=rhs.numerator;
	int val1_tempdenom=val1_denom, val1_tempnumerat=val1_numerat, val2_tempdenom=val2_denom, val2_tempnumerat=val2_numerat;
	val1_numerat = val1_tempnumerat * val2_tempdenom; //Make this less clutered.
	val1_denom = val1_tempdenom * val2_tempdenom;
	val2_numerat = val2_tempnumerat * val1_tempdenom;
	val2_denom = val1_denom;//val2_tempdenom*val1_tempdenom;

	if(val1_numerat==val2_numerat)
		return true;
	else
		return false;
}
bool fraction::operator!=(const fraction &rhs) const
{
	int val1_denom=denominator, val1_numerat=numerator, val2_denom=rhs.denominator, val2_numerat=rhs.numerator;
	int val1_tempdenom=val1_denom, val1_tempnumerat=val1_numerat, val2_tempdenom=val2_denom, val2_tempnumerat=val2_numerat;
	val1_numerat=val1_tempnumerat*val2_tempdenom; //Make this less clutered.
	val1_denom=val1_tempdenom*val2_tempdenom;
	val2_numerat=val2_tempnumerat*val1_tempdenom;
	val2_denom=val1_denom;//val2_tempdenom*val1_tempdenom;

	if(val1_numerat!=val2_numerat)
		return true;
	else
		return false;
}

fraction &fraction::operator--()
{
	int temp_numerator, temp_denominator;
	temp_numerator=denominator;
	temp_denominator=numerator;
	numerator=temp_numerator;
	denominator=temp_denominator;

	decimal=numerator/(double) denominator;
	return *this;
}
fraction fraction::operator--(int) //Notice how the dummy int isn't even used? It is just there to specify the fact that this is a POST decrement
{
	fraction temp=*this;

	int temp_numerator, temp_denominator;
	temp_numerator=denominator;
	temp_denominator=numerator;
	numerator=temp_numerator;
	denominator=temp_denominator;

	decimal=numerator/(double) denominator;
	return temp;
}

istream &operator>>(istream &input, fraction &in_frac)
{
	cout<<"Please enter a fraction. Enter with the following format: Y/X"<<endl;
	input>>in_frac.numerator;
	input.get();
	input>>in_frac.denominator;

	while(in_frac.denominator==0)
	{
		cout<<"Denominator cannot be zero. Please enter a fraction without the denominator of zero."<<endl;
		input>>in_frac.numerator;
		input.get();
		input>>in_frac.denominator;
	}

	in_frac.decimal=in_frac.numerator/(double) in_frac.denominator;
	in_frac.simplify();

	return input;
}
ostream &operator<<(ostream &output, fraction const &out_frac)
{
	if(out_frac.denominator==1)
		output<<out_frac.numerator;
	else
		if(out_frac.numerator==0)
			output<<"0";
		else
			if(out_frac.denominator==0)
				output<<"Undefined, as you cannot divide by a zero.";
			else
				output<<out_frac.numerator<<'/'<<out_frac.denominator<<" aka "<<out_frac.decimal;

	output<<endl;
	return output;
}

fraction fraction::operator+(const fraction &rhs) const
{
	int val1_denom=denominator, val1_numerat=numerator, val2_denom=rhs.denominator, val2_numerat=rhs.numerator;
	int val1_tempdenom=val1_denom, val1_tempnumerat=val1_numerat, val2_tempdenom=val2_denom, val2_tempnumerat=val2_numerat;
	val1_numerat=val1_tempnumerat*val2_tempdenom; //Make this less clutered.
	val1_denom=val1_tempdenom*val2_tempdenom;
	val2_numerat=val2_tempnumerat*val1_tempdenom;
	val2_denom=val1_denom;//val2_tempdenom*val1_tempdenom;
	
	fraction temp;
	temp.numerator=val1_numerat+val2_numerat;
	temp.denominator=val2_denom;

	temp.decimal=temp.numerator/(double) temp.denominator;
	temp.simplify();
	return temp;
}
fraction fraction::operator-(const fraction &rhs) const
{
	int val1_denom=denominator, val1_numerat=numerator, val2_denom=rhs.denominator, val2_numerat=rhs.numerator;
	int val1_tempdenom=val1_denom, val1_tempnumerat=val1_numerat, val2_tempdenom=val2_denom, val2_tempnumerat=val2_numerat;
	val1_numerat=val1_tempnumerat*val2_tempdenom; //Make this less clutered.
	val1_denom=val1_tempdenom*val2_tempdenom;
	val2_numerat=val2_tempnumerat*val1_tempdenom;
	val2_denom=val1_denom;//val2_tempdenom*val1_tempdenom;

	fraction temp;
	temp.numerator=val1_numerat-val2_numerat;
	temp.denominator=val2_denom;

	temp.decimal=temp.numerator/(double) temp.denominator;
	temp.simplify();
	return temp;
}
fraction fraction::operator*(const fraction &rhs) const
{
	fraction temp;
	temp.numerator=numerator*rhs.numerator;
	temp.denominator=denominator*rhs.denominator;

	temp.decimal=temp.numerator/(double) temp.denominator;
	temp.simplify();
	return temp;
}
fraction fraction::operator/(const fraction &rhs) const
{
	fraction temp;
	temp.numerator=numerator*rhs.denominator;
	temp.denominator=rhs.numerator*denominator;

	temp.decimal=temp.numerator/(double) temp.denominator;
	temp.simplify();
	return temp;
}

void fraction::recipricol()
{
	if(numerator==1 && denominator!=0)
		cout<<denominator;
	else
		if(numerator==-1 && denominator!=0)
			cout<<denominator*-1;
		else
			if(denominator==0)
				cout<<"Sorry, the recipricol of an undefined number doesn't exist.";
			else
				if(numerator==0)
					cout<<"Undefined because the recipricol of zero doesn't exist.";
				else
				{
					decimal=denominator/(double) numerator;
					if(numerator>0)
						cout<<denominator<<'/'<<numerator<<" aka "<<decimal;
					if(numerator<0)
						cout<<denominator*-1<<'/'<<numerator*-1<<" aka "<<decimal;
				}
	cout<<endl;
}

void fraction::simplify()
{	//Algorithm below for reducing fractions
	int temp;
	if(numerator>denominator)
		temp=denominator;
	else
		temp=numerator;

	int TF=0;

	if(temp>1)
	{
		while(TF==0)
		{
			if(denominator%temp==0 && numerator%temp==0)
			{
				denominator=denominator/temp;
				numerator=numerator/temp;
				TF=1;
			}
			else
				temp--;
		}
	}

	if(temp<-1)
	{
		while(TF==0)
		{
			if(denominator%temp==0 && numerator%temp==0)
			{
				denominator=denominator/temp;
				numerator=numerator/temp;
				TF=1;
			}
			else
				temp++;
		}
	}
	if(denominator<0) //For proper formatting of a negative fraction (like making: -2/1 look like -2/1 instead of possibly looking like 2/-1 from the made algorithm above)
	{
		numerator=numerator/-1;
		denominator=denominator/-1;
	}
}