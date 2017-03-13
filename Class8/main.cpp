
#include <iostream>

using namespace std;

class student
{
        public:
            
            student(int = 0 , int = 0 , int = 0 );
            ~student();
            void SetData(int, int ,int);
            
            void SetTest1(int);
            void SetTest2(int);
            void SetTest3(int);
            
            int GetTest1();
            int GetTest2();
            int GetTest3();
            
            void Change(student &);
            
            void PrintData();
           
        private:
            
            int t1, t2, t3;
};


student :: student(int a, int b, int c )
{       SetData(a,b,c);         }


student :: ~student()
{       cout <<t1<<t2<<t3 << "Snoozed" << endl; }


void student :: SetData(int a, int b, int c)
{       SetTest1(a); SetTest2(b) ; SetTest3(c);   }


void student :: SetTest1(int aa)
{
    t1 = aa;
}


void student :: SetTest2(int bb)
{
    t2 = bb;
}

void student :: SetTest3(int cc)
{
    t3 = cc;
}

int student :: GetTest1()
{       return t1;   }


int student :: GetTest2()
{       return t2;   }


int student :: GetTest3()
{       return t3;   }

void student :: PrintData()
{
  cout << t1 << " " << t2 << " " << t3 << endl;  
}

void student :: Change (student &student)
{
    t2 += 10;
    t3 += 20;
}

int main() 
{
    student stud(10, 20, 30);
    
    stud.PrintData();
    
    int aaa, bbb, ccc;
    
    cout << "Enter 3 scores: " << endl;
    cin >> aaa >> bbb >> ccc;
    
    stud.SetTest1(aaa);
    stud.SetTest2(bbb);
    stud.SetTest3(ccc);
    stud.PrintData();
    
    aaa = stud.GetTest1();
    bbb = stud.GetTest2();
    ccc = stud.GetTest3();
    
    
    cout << aaa << " " << bbb << " "<< ccc << endl;
    
    
    cout << "Test 1 is: " << stud.GetTest1() << endl;
    cout << "Test 2 is: " << stud.GetTest2() << endl;
    cout << "Test 3 is: " << stud.GetTest3() << endl;
   
    stud.PrintData();
    stud.Change( stud);
    stud.PrintData();
    
    
    
    return 0;
}

