/* Bijan Hamidi & Raika Sanii
* Program 2
* CS 37
* This program uses templates 
*/
#include <iostream>
#include <fstream>
#include<iomanip>
#include <stdio.h>
 
using namespace std;




template <class T>

void printArray(T *a, const int n)

{

	 for(int i = 0; i < n; i++)

	 {

		 cout<<a[i]<<" ";

	 }
 
	cout<<endl;

}

template <class T>

void loadArray(T *a, const int n)

{

    

	 for(int i = 0; i < n; i++)

	 {
		 cin>> a[i];

	 }
 
}

template <class T>

void findBigSmall(T *a, const int n)

{

	 T big = a[0];

	 T small = a[0];

	

         for (int i = 0 ; i < n  ; i++)

        {

            if (a[i] > big)

            {

                big = a[i];

            }

            

            if (a[i] < small)

            {

                small = a[i];

            }

        }

		 cout <<" big is: "<<big << endl;
		 cout <<" small is: " <<small << endl;

} 

template <class T>

void sortArray(T *a, const int n)

{

    for (int i = 0 ; i < n-1 ; i++)

    {

        for (int j = 0 ; j < n-1 ; j++)

        {

            if (a[j] < a[j+1])

            {

                T tmp = a[j];

                a[j] = a[j+1];

                a[j+1] = tmp;

            }

        }

    }

}

 template <class T>

void saveText(T *a, const int n, char *b)

{

    ofstream outfile(b, ios::out);

    

    for(int i =0; i < n; i++)

    {

        //input to file and close file
		outfile << a[i] << " ";
    }

	cout << endl << endl;

    outfile.close();

    

}

template <class T>

void getText(T *a, const int n, char *b)

{
    T input;
    //retrieve file and close
    //define ifstream out file
    
    ifstream infile(b, ios::in);

    int i = 0;
    while(infile >> input)

    {

        //input to file and close file
		a[i] = input;
		
		i++;
    }

	cout << endl << endl;

    infile.close();

}

 int main()

{

	 const int n1 = 5, n2 = 7, n3 = 6;

	 int a[n1];

	 float b[n2];

	 char c[n3];

	 char fileName1[] = "ints.txt";

	 char fileName2[] = "floats.txt";

	 char fileName3[] = "chars.txt";

	 cout<<"enter 5 ints"<<endl;
 
	loadArray(a, n1);

	 cout<<"enter 7 floats"<<endl;

	 loadArray(b, n2);

	 cout<<"enter 5 chars"<<endl;

	 cin.ignore(10, '\n');
 
	loadArray(c, n3-1);

	 findBigSmall(a, n1);

	 findBigSmall(b, n2);
 
	findBigSmall(c, n3-1);

	 sortArray(a, n1);

	 sortArray(b, n2);
 
	sortArray(c, n3-1);

	 printArray(a, n1);

	 printArray(b, n2);
 
	printArray(c, n3-1);

	 saveText(a, n1, fileName1);

	 saveText(b, n2, fileName2);

	 saveText(c, n3, fileName3);

	 getText(a, n1, fileName1);

	 getText(b, n2, fileName2);

	 getText(c, n3, fileName3);

	 printArray(a, n1);

	 printArray(b, n2);

	 printArray(c, n3-1);

	 system("pause");

	 return 0;

}