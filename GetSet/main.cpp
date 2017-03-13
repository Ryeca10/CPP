#include <iostream>
#include <string>
using namespace std;


class GetSet
{
    char name[15];
    float num1;
    float num2;
    float num3;
    
    public:
        
    GetSet(char *stdName = " ", float test1 = 0.0 ,  float test2 = 0.0 ,  
           float test3 = 0.0);
    ~GetSet();
    void Set(char * student , float tst1, float tst2, float tst3);
    void SetName(char *std);
    void SetTest1(float test1);
    void SetTest2(float test2);
    void SetTest3(float test3);
    float GetTest1();
    float GetTest2();
    float GetTest3();
    float Calc();
    void Print();
    

};

GetSet :: GetSet(char *stdName, float test1,  float test2,  float test3)
          {     Set(stdName, test1, test2, test3);   }

GetSet :: ~GetSet()
          {     cout << name << " is destroyed!! " << endl; }


void GetSet :: Set(char *student, float tst1, float tst2, float tst3)
               {  
                    SetName(student);
                    SetTest1(tst1);
                    SetTest2(tst2);
                    SetTest3(tst3);
               }

void GetSet :: SetName(char *std)
               {    strcpy(name,std); }

void GetSet :: SetTest1(float test1)
               {     num1 = test1;    }

void GetSet :: SetTest2(float test2)
               {     num2 = test2;    }

void GetSet :: SetTest3(float test3)
               {     num3 = test3;   }


float GetSet :: GetTest1()
                {       return num1;    }

float GetSet :: GetTest2()
                {       return num2;    }

float GetSet :: GetTest3()
                {       return num3;    }

float GetSet :: Calc()
                {    return   ( GetTest1() + GetTest2() + GetTest3() ) / 3; }

void GetSet :: Print()
               {   
                   cout << "Student name: " << name << " data is: " << endl;
                   cout << "Test1: " <<GetTest1() << " Test2: " << GetTest2() 
                           << " Test3: " << GetTest3() << endl;
                   cout << "Student`s overall average: " << Calc() << endl;
               }


int main()
{
    GetSet Student;
    char studName[30];
    float test_1;
    float test_2;
    float test_3;
    
    cout << "Student name: ";
    cin.getline(studName, '\n');
    Student.SetName(studName);
    
    cout << "Test1: ";
    cin >> test_1;
    Student.SetTest1(test_1);
    
    cout << "Test2: ";
    cin >> test_2;
    Student.SetTest2(test_2);
    
    cout << "Test3: ";
    cin >> test_3;
    Student.SetTest3(test_3);
    
    Student.Print();
    
    return 0;
    
}