
#include <iostream>

using namespace std;


class student
{
        public:
            student();
            ~student();
            void GetData(int , int , int);
            void PrintData();
            void Add(student , student);
            
        private:
            int t1 , t2, t3;
    
               
};

student :: student()
{

}


student :: ~student()
{
    cout  << t1 << t2 << t3 << "incinerated! " << endl;
}


void student :: GetData(int a , int b, int c)
{
    t1 = a; t2 = b; t3 = c;
}



void student :: PrintData()
{
    cout << t1 << t2 << t3 << endl;
}

void student :: Add(student studenta , student studentb)
{
    t1 = studenta.t1 + studentb.t1;
    t2 = studenta.t2 + studentb.t2;
    t3 = studenta.t3 + studentb.t3;
}



int main() 
{
    student one, two, sum;
    
    one.GetData(10, 20, 30);
    two.GetData(20, 30, 40);
    sum.Add(one, two);
    sum.PrintData();
    
    return 0;
}
