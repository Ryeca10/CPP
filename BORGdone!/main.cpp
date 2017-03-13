#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;


const int SIZE = 19;

const int EMPTY = -1;
#define DISPLAY true


// Class Node - creates the nodes that are used in class List

class Node
{
    public:
        
        string varName;
        int integer;
        int start;

        Node *next;

        // Node Constructor - has an integer value and a start scope, as well as
        // a pointer to the next Node
        Node(string name, int value, int s, Node *nInt=NULL)
        {
            varName = name; 
            integer = value;
            start = s;
            next = nInt;

        }   
};


// The Table of Linked Lists, with size 19
Node *Table[SIZE];


// The class HashTable has a constructor, a void Insert function, a void 
// Print Function and a  void Operators ( or Interpretor )
class HashTable 
{
	
	Node *nx;

     public:
         
        // the constructor of HashTable, assigns all the pointers of array pointer o NULL
        HashTable()
        {
                for (int i = 0; i < SIZE; i++)
                    Table[i] = NULL;
        }

        
        //  Insert takes a newly declared and initialized variable as well as the 
        // variables scope (start ) and the value of the variable
        void Insert(const char *var, int value , int start)
        {
            if (start == 0)
            {
                cout << var << " is Undefined. " << endl;
            }
            
            else
            {
                // creates new Node
                    Node *newNode = new Node(var, value, start,nx=NULL);
                    int hashVal = 0, intVal;
                    string varS = var;


                          // helps finding out the value to be hashed
                            for(int i = 0 ; i< varS.length(); i++)
                            {
                                    intVal = var[i] * (i+1);
                                    hashVal += intVal;
                            }

                            // if the table element is still NULL, it will be pointed to
                            // this new node
                            if (Table[hashVal % SIZE] == NULL) 
                            {
                                    Table[hashVal % SIZE] = newNode;
                            }
                    
                            // if a link has already started, head will be the new node and 
                            // link list will be expanded based on the hash value
                            else
                            {

                                    Node *tmp = Table[hashVal%SIZE];
                                    Table[hashVal%SIZE] = newNode;
                                    newNode->next = tmp;
                            } 
                }
              
        }  

        // If the word Print is found in the program, the variable and 
        // the scope of the variable will be sent to Print func. for printing
       void Print( string varS, int start)
        {
   
           int intVal, hashVal = 0;
           bool check = false;
           Node *tmp;

           // Helps finding out the value to be hashed
           for(int i = 0 ; i< varS.length()-1 ; i++)
            { 
                    intVal = varS[i] * (i+1);
                    hashVal += intVal;
            }


           // for each hash value, goes through the linked list of that particular 
           // hash value element
            for ( tmp = Table[hashVal%SIZE] ; tmp != NULL ; tmp = tmp->next)
            {
                // compares the variable passed to the function with the variables in the linked list
                if (strncmp(varS.c_str(), tmp->varName.c_str(), varS.length()-1) == 0)
                {
                    // if the current scope in the main is less than the scope of the variable
                    if (start < tmp->start)
                    {
                        // the variable is undefined
                        cout << varS << " is Undefined. " << endl;
                        return;
                    }
                    else
                    {
                        cout << varS << " is " << tmp->integer << endl;
                        check = true;
                        return;
                    }
                }
            }

           // if the variable is not found in the linked list of its hash value
            if (!check )
            {
                // its not defined
                cout << varS << " is Undefined. " << endl;
            }
           
              
        }
       
     ///The Interpretor of the program
    // Takes the variable and the operator in front of it from the file 
    //
    void Operators( const char *var, const char *var2)
    {
            string varS = var;
            int hashVal = 0;
            const char *var1;
            int intVal;
            int val;

            //helps finding the hash value
            for(int i = 0 ; i< varS.length(); i++)
            { 
                    intVal = var[i] * (i+1);
                    hashVal += intVal;
            }

            // searches the hash value linked list for the variable
            for ( Node *tmp = Table[hashVal%SIZE] ; tmp != NULL ; tmp = tmp->next)
            {
                
                // if it finds the variable in the linked list
                if (strcmp(var , tmp->varName.c_str()) == 0)
                {
                        // if it is increment sign, increases the value of the node variable
                        if (strncmp(var2, "++",2) == 0)
                        {
                                tmp->integer += 1;
                        }
                        // if its the decrement sign, decrements the value of the node variable
                        else if (strncmp(var2, "--",2) == 0)
                        {
                                tmp->integer -= 1;
                        }
                        
                        // adds the next number after the operator in the file to the node value
                        else if (strncmp(var2, "+",1) == 0)
                        {
                                cout <<  tmp->varName << " + ";
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer += val;
                                cout << val << " is " << tmp->integer;
                                cout << endl;
                        } 

                        // subtracts the next number after the operator in the file to the node value
                        else if (strncmp(var2, "-",1) == 0)
                        {
                                cout <<  tmp->varName << " - ";
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer -= val;
                                cout << val << " is " << tmp->integer;  
                                cout << endl;
                        }

                        // multiplies the next number after the operator in the file to the node value
                        else if (strncmp(var2, "*",1) == 0)
                        {
                                cout <<  tmp->varName << " * ";
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer *= val;
                                cout << val << " is " << tmp->integer; 
                                cout << endl;
                        }

                        // divides the next number after the operator in the file to the node value
                        else if (strncmp(var2, "/",1) == 0)
                        {       
                                
                                cout <<  tmp->varName << " / ";
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer /= val;
                                cout << val << " is " << tmp->integer;
                                cout << endl;
                        }

                        // muduluses the next number after the operator in the file to the node value
                        else if (strncmp(var2, "%",1) == 0)
                        {
                                cout <<  tmp->varName << " % ";
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer %= val;
                                cout << val << " is " << tmp->integer; 
                                cout << endl;
                        }

                        // raises the node value to the power of the next number after the operator ^
                        else if (strncmp(var2, "^",1) == 0)
                        {
                                cout <<  tmp->varName << " ^ ";
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer = pow(float(tmp->integer),float(val));
                                cout << val << " is " << tmp->integer;  
                                cout << endl;
                        }
                        
                        // the node value will be assigned to the value of the next number after the operator =
                         else if (strncmp(var2, "=",1) == 0)
                        {
                                cout <<  tmp->varName;
                                var1 =  strtok (NULL, " ");
                                val = atoi(var1);
                                tmp->integer = val;
                                cout << " is " << tmp->integer; 
                                cout << endl;
                        }
                }
        }
    }
        
        
};


int main()
{
	int val; // node value
	const char *var1, // first word
                *var2, //second word
                *var3; // third word
        string vars1;  // change word to string
	char word[80];  // each sentence in the file
        int start=0;  // scope variable

    // instantiates object of hashTable
    HashTable *object = new HashTable(); 
        
    // define file name
	ifstream read;
        // opens file
	read.open("BORG.txt",ios::in);
        // reads a whole line to the array of char word
	read.getline(word,80,'\n');
        //takes the first word from the sentence that is just read
	var1 = strtok(word," ");
        // assigns the array of char to a string
        vars1 = var1;
        
    /// while the text file is not ended
    while(!read.eof())
    {
		// start if the char array of first word is not empty and of it is not a comment
		if (var1 != NULL && strcmp(var1, "COM") != 0)
		{
                    
                    // if the first word is START
                    if (strncmp(var1, "START", 5) == 0)
                    {
                        // increment scope variable by one
                            ++start;
                            
                    }

                    // if the first word is FINISH
                    else if (strncmp(var1, "FINISH", 6)==0 )
                    {
                        // decrement the scope variable by one
                            --start;
                    }

                    // if the first word is VAR
                    else if (strcmp(var1, "VAR") == 0)
                    {
                        // take the Variable name in the sentence
                            var1 = strtok(NULL, " ");
                           // take the = sign 
                            var2 = strtok(NULL, " ");
                            // take the integer the variable is assigned to
                            var3 = strtok(NULL, " ");
                            // turn array of char to integer 
                            val = atoi(var3);
                            
                            // insert variable name value and scope to insert function
                            object->Insert(var1, val, start);

                    }

                    
                  // if the first word is PRINT
                    else if(strncmp(var1, "PRINT", 5)==0 )
                    {
                            var1 = strtok(NULL, " ");
                            vars1 = var1;
                            var2 = strtok(NULL," ");
                           
                            
                            // if after the variable comes an operator,
                            if (var2 != NULL &&(strncmp(var2, "++", 2)==0 || strncmp(var2, "--", 2)==0 || 
                                strncmp(var2, "+", 1)==0 || strncmp(var2, "-", 1)==0 || 
                                strncmp(var2, "*", 1)==0 || strncmp(var2, "/", 1)==0 ||
                                strncmp(var2, "%", 1)==0 || strncmp(var2, "^", 1)==0 ))
                                {// send variable, and value to Interpretor
                                       object->Operators(var1, var2);
                                }
                            else 
                                // if there is no operator after the variable, 
                                //sent variable and the scope to print function
                                object->Print(vars1, start);
                    }
                    
                    /// if no other key words were t the beggining of the sentence
                    //search for variables
                    else 
                    {
                        string varS = var1;
                        int intVal , hashVal=0;
                        // helps calculating the hash value
                        for(int i = 0 ; i< varS.length(); i++)
                        {
                                intVal = var1[i] * (i+1);
                                hashVal += intVal;
                        }

                        // search the linked list for the variable at the hash value element
                        for ( Node *tmp = Table[hashVal%SIZE] ; tmp != NULL ; tmp = tmp->next)
                        {
                            // f the variable was found in the table
                                if (strcmp(var1, tmp->varName.c_str()) == 0)
                                        var2 = strtok(NULL, " ");

                                // if any operators were found after the variable name
                                if (strncmp(var2, "++", 2)==0 || strncmp(var2, "--", 2)==0 || 
                                    strncmp(var2, "+", 1)==0 || strncmp(var2, "-", 1)==0 || 
                                    strncmp(var2, "*", 1)==0 || strncmp(var2, "/", 1)==0 ||
                                    strncmp(var2, "%", 1)==0 || strncmp(var2, "^", 1)==0 || 
                                    strncmp(var2, "=" ,1) == 0)
                                         {
                                                // send variable and the operator to the interpretor
                                                object->Operators(var1, var2);
                                         }
                        }
                    }
                    
		}

                 // take the next sentence from the file 
		read.getline(word,80,'\n');
                //take the first word
		var1 = strtok(word," ");
    }
    read.close();

	system("pause");
    return 0;
}



/*
 * =================  OUTPUT  1  =================
 * 
 * 
    BORAMIR  is 25
    LEGOLAS  is 101
    GANDALF  is Undefined. 
    BORAMIR * 2 is 52
    GANDALF  is 49
    BORAMIR  is 26
    GANDALF  is Undefined. 
    LEGOLAS is 1000
    LEGOLAS  is 1000
    LEGOLAS  is 1000
    LEGOLAS  is 999

    RUN SUCCESSFUL (total time: 62ms)

 */



