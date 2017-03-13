#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    string name;
    int weight;
    
    ifstream infile("//Users//raikanarimani//NetBeansProjects//CppApplication_8//names123.txt",ios::in);
    
    while(getline(infile, name))
    {
        
        infile >> weight;
        
        cout << name << " " << weight;
        
        cout << endl;
        infile.ignore(100,'\n');
    }
    infile.close();
    
    return 0;
}