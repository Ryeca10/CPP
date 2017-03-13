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
 *
 ***************************************************************/
class DataNode
{
public:


    float data;			// Numeric data in calculator
    DataNode *next;		// Forward Link


    //Constructor - Creates node with 2 primary data types, and 2 pointers,
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
	void push(float info, DataNode *head1)
	{
		DataNode *Node = new DataNode(info, head);
		head1 = Node;
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
	string data;				// INPUT - takes value from the user as a string data
	char oprt;					// Processing - the operator data
	float floatNum;				// Processing - the number data
	float nextNum;
	float result;				// CALC - the final value returned from the Calc function
	char tempOprt;



	DataNode *head = NULL;
	DataNode *tmp;

	// Creates a new linked list of numbers and operators
	Stack *stack = new Stack();

	// OUTPUT - asks the user to input the list of data, asks to enter Q to quit
	cout << "Enter Data, Enter Q to quit: " << endl;

	// Processing - while receives data and the data is not Q, checks if the data
	//				is a number or an operator, then adds the data to the linked list
	while (cin >> data)
	{
		cout << "entered loop. " << endl;

		//Processing - checks if the data is a number
		if(data[0] >= 48 && data[0] <= 57)
		{
			// if a number, converts the literal to a decimal number, saves the number
			floatNum = strtod(data.c_str(), NULL);

			//insert stack - adds numeric data to the head f the list

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

			cout<< "number entered." << floatNum <<endl;
		}

		//Processing - check if the data entered is a NEGATIVE number
		else if (data.length() != 1 && data[1] >= 48 && data[1] <= 57)
		{
			// converts literal to a floating point number, save the number
			floatNum = strtod(data.c_str(), NULL);

			if(!head)
			{
				DataNode *Node = new DataNode(floatNum, head);
				head = Node;
			}
			else
					{
						head = stack->getHead();
						stack->push(floatNum, head);
					}

				cout<< "number entered:" << floatNum <<endl;
		}

		//Processing - check if the data entered is an operator
		else if (data[0] == 42 || data[0] == 43 || data[0] == 45 || data[0] == 47)
		{
			// saves the operator as a character value
			oprt = data[0];

			float tempFirst;
			float tempSecond;
			switch(oprt)
			{
				case'+':
					stack->push(stack->pop() + stack->pop(),head);
					head = stack->getHead();
					break;

				case'-':
					if(!head)
					{
						cout<<"Error: Too Many Operators. " << endl;
					}
					else
					{
						tempFirst = stack->pop();
                                                cout<<"1 number in stack. " <<endl;
						head = stack->getHead();
						if(!head)
						{
							cout<<"Error: Too Many Operators. " << endl;
						}
						else
						{
							tempSecond = stack->pop();
                                                        cout<< "2 number in stack. "<< endl;
							head = stack->getHead();
							stack->push(tempSecond - tempFirst,head);
							head = stack->getHead();
						}
					}
                                         cout << "The result: " << stack->pop() << endl;
					break;

				case'*':
					stack->push(stack->pop() * stack->pop(),head);
					head = stack->getHead();
					break;

				case'/':
					tempFirst = stack->pop();
					tempSecond = stack->pop();

					if(tempFirst ==0)
					{
						cout << "ERROR" << endl;
						break;
					}
					else
					{
						stack->push(tempSecond / tempFirst,head);
						head = stack->getHead();
						break;						// performs calculation
					}
                                        

                                       
			}
                        

		}

	}

return 0;
}
