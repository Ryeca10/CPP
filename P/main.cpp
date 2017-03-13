#include<iostream>
using namespace std;


int Search (int SIZE)
{

	int arr[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	int search;



	cout<<"Enter a search term";
	cin>>search;

	if(search < arr[SIZE/2])
	{
		SIZE = SIZE/2;

	}

	if(search > arr[SIZE/2])
	{
	}

	if(search == arr[SIZE/2])
	{
		return SIZE/2;
	}
	
}


int main()

{
	int SIZE = 20;

	Search(SIZE);


	return 0;
}

