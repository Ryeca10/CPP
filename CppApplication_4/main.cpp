/***************************************************************************
 * NAME       :  RAIKA SANII
 * STUDENT ID :  101239
 * ASSIGNMENT :  PROGRAM1
 * CLASS      :  CS-41
 **************************************************************************/

#include <string>
#include <stack>
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>

using namespace std;

/***************************************************************
 * Class DataNode
 * _____________________________________________________________
 *
 * This class creates nodes that can contain numeric data as well
 * as operator for the link, each node is either assigned to a
 * numeric data or to an operator, but not both. If one data
 * type exist, the other one is assigned to NULL
 ***************************************************************/
class DataNode
{
public:


    float data;			// Numeric data in calculator
    DataNode *next;		// Forward Link


    //Constructor- Creates node with 2 primary data types, and 2 pointers,
    //		one points to the next node, the other points to the previous node
    DataNode( float info , DataNode *nextPtr)
	{
        data = info;
	next = nextPtr;
    }

};

/***************************************************************
 * Class Stack
 * _____________________________________________________________
 *
 * 
 ***************************************************************/

class Stack
{
	DataNode* head;

public:
	void push(float info, DataNode *head)
	{
		DataNode *Node = new DataNode(info, head);
		this->head = Node;
	}

	float pop()
	{
		float info = head->data;

		head= head->next; 
		return info;
	}

	DataNode* getHead()
	{
		return head;
	}

	void setHead(DataNode* setHead)
	{
		head = setHead;
	}

};

int main()
{
	cout <<"it runs" << endl;
	string dataS;// INPUT - takes value from the user as a string data
	string slashN = "\n";
        char oprt;					// Processing - the operator data
	float floatNum;				// Processing - the number data
	float nextNum;
	float result;				// CALC - the final value returned from the Calc function
	char tempOprt;
        int oprtCount= 0;
        int whileCount = 0;
        int floatCount = 0;
        size_t found;
     


	DataNode *head = NULL;
	DataNode *tmp;

	// Creates a new linked list of numbers and operators
	Stack *stack = new Stack();

	// OUTPUT - asks the user to input the list of data, asks to enter Q to quit
	cout << "Enter list of data. Enter 0 to quit: " << endl;
        
	// Processing - while receives data and the data is not Q, checks if the data
	//is a number or an operator, then adds the data to the linked list

        while (cin>>dataS)
	{
            
            cout << "entered 1st while loop. " << endl;
		
                //Processing - checks if the data is a number
           if(dataS[0] >= 48 && dataS[0] <= 57)
		{
                        floatCount++;
			// if a number, converts the literal to a decimal number, saves the number
			floatNum = strtod(dataS.c_str(), NULL);

			//insert stack - adds numeric data to the head f the list
			
			if(!head)
			{
				DataNode *Node = new DataNode(floatNum, head);
				head = Node;
                                if (floatNum == 0)
                                 {
                                         break;
                                 }
                                 
				stack->setHead(head);
                               
			}
			else
					{
						stack->push(floatNum, head);
						head = stack->getHead();
					}

			cout<< "number entered." << floatNum <<endl;
		}

		//Processing - check if the data entered is a NEGATIVE number
           else if(dataS.length() != 1 && dataS[1] > 48 && dataS[1] <= 57)
		{
                        floatCount++;
			// converts literal to a floating point number, save the number
			floatNum = strtod(dataS.c_str(), NULL);
			
			if(!head)
			{
				DataNode *Node = new DataNode(floatNum, head);
				head = Node;
                                stack->setHead(head);
			}
			else
					{
                                                stack->push(floatNum, head);
						head = stack->getHead();
					}

				cout<< "number entered:" << floatNum <<endl;
		}
                

		//Processing - check if the data entered is an operator
		else if (dataS[0] == 42 || dataS[0] == 43 || dataS[0] == 45 || dataS[0] == 47)
		{       
                    ++oprtCount;
                        
                    if (oprtCount == 1)
                    {
			// saves the operator as a character value
			oprt = dataS[0];
			
			float tempFirst;
			float tempSecond;
			switch(oprt)
			{
				case'+':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
                                                
						if(!head)
						{
                                                    cout<< "Error: Too Many Operators. " << endl;
						}
						else
						{
							tempSecond = stack->pop();
                                                        cout<<"2 numbers poped. " << endl;
							head = stack->getHead();
							result = tempSecond + tempFirst;
                                                        cout<< "Result back to the stack. " << endl;
                                                       
							
                                                        
						}
					}
					break;

				case'-':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
						if(!head)
						{
							cout<< "Error: Too Many Operators. " << endl;
						}
						else
						{
							tempSecond = stack->pop();
                                                        cout<<"2 numbers poped. " << endl;
							head = stack->getHead();
							result = tempSecond - tempFirst;
                                                        cout<< "Result back to the stack. " << endl;
							
                                                       
						}
					}
					
					break;

				case'*':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
						if(!head)
						{
							cout<< "Error: Too Many Operators. " << endl;
						}
						else
						{
							tempSecond = stack->pop();
                                                        cout<<"2 numbers poped. " << endl;
							head = stack->getHead();
							result = tempSecond * tempFirst,head;
                                                        cout<< "Result back to the stack. " << endl;
                                                        
							
                                                      
						}
					}
					break;

				case'/':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
			
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
                                                if(tempFirst ==0)
                                                {
                                                        cout << "Error: Division by Zero. " << endl;

                                                }
                                                else
                                                {
                                                
                                                        if(!head)
                                                        {
                                                                cout<< "Error: Too Many Operators. " << endl;
                                                        }
                                                        else
                                                        {
                                                                tempSecond = stack->pop();
                                                                cout<<"2 numbers poped. " << endl;
                                                                head = stack->getHead();
                                                                result = tempSecond / tempFirst;
                                                                cout<< "Result back to the stack. " << endl;
                                                                
                                                                
                                                                
                                                        }
                                                }
                                        }
					break;
                                        
                                       
			}
                 
                    }
                    
                    else
                    {
			// saves the operator as a character value
			oprt = dataS[0];
			
			float tempFirst;
			float tempSecond;
			switch(oprt)
			{
				case'+':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
                                              
                                                 result = result + tempFirst;
                                                
                                                 cout<< "Result back to the stack. " << endl;
                                               

					
					}
					break;

				case'-':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
						if(!head)
						{
							//cout<< "Error: Too Many Operators. " << endl;
						}
						else
						{
						
							
							result = tempFirst - result;
                                                        cout<< "Result back to the stack. " << endl;
							
                                                      
						}
					}
					
					break;

				case'*':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
						if(!head)
						{
							//cout<< "Error: Too Many Operators. " << endl;
						}
						else
						{
							result = result * tempFirst;
                                                        cout<< "Result back to the stack. " << endl;
						
                                                       
						}
					}
					break;

				case'/':
					if(!head)
					{
						cout<< "Error: Too Many Operators. " << endl;
					}
			
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 nubmer poped. " << endl;
						head = stack->getHead();
                                                if(result ==0)
                                                {
                                                        cout << "Error: Division by Zero. " << endl;

                                                }
                                                else
                                                {
                                                
                                                        if(!head)
                                                        {
                                                               // cout<< "Error: Too Many Operators. " << endl;
                                                        }
                                                        else
                                                        {
                                                       
                   
                                                                result = tempFirst / result;
                                                                cout<< "Result back to the stack. " << endl;
                                                
                                                        }
                                                }
                                        }
					break;
              
			}
                 
                }
                    
                    if (!head)
                    {
                        cout << "The result: " << result << endl;
                    }
                    
                    
                 
		}
       
            
            
           cout<<"Still in while loop!! " << endl;    
           
           char check = cin.get();
           
           if (check == '\n')
           {
               cout << "works.";
               if (floatCount > oprtCount + 1)
               {
                   cout << "Error: Too Many Operands. " << endl;
               }
           }
        }

        
        
return 0;

}
