/***************************************************************************
 * NAME       :  RAIKA SANII
 * STUDENT ID :  101239
 * ASSIGNMENT :  PROGRAM1 - Reverse Polish Calculator
 * CLASS      :  CS-41
 **************************************************************************/
#include <string>
#include <stack>
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;


/****************************************************************
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
        //		    one points to the next node, the other points to the 
        //              previous node
        DataNode( float info , DataNode *nextPtr)
        {
            data = info;        // Assigns the float number entered to the node
            next = nextPtr;     // makes a pointer for the new node
        }

};

/*****************************************************************************
 * Class Stack
 * ___________________________________________________________________________
 *
 * Creates a stack of float numbers.
 * This class has 4 public methods:
 *                   
 *      The push() method      : To input/push numbers to the stack
 *      The pop() method       : To read/pop the most recently entered number
 *      The getHead() method   : To set pointer for the current node that 
 *                                   is made before
 *      The setHead() method   : To set pointer for a node that is just made
 *****************************************************************************/
class Stack
{
	DataNode* head;

public:
	void push(float info, DataNode *head)
	{
                //Creates a new data node for the stack
		DataNode *Node = new DataNode(info, head);
                // connects the new node to the current head
		this->head = Node;
	}

	float pop()
	{
            // stores the value in the node to the variable info
		float info = head->data;

                // Sets the next node to become the head of the list
		head= head->next; 
                
                // Returns the value poped from the stack to the main
		return info;
	}

	DataNode* getHead()
	{
            // Returns the data in the current node to be the head of the stack
		return head;
	}

	void setHead(DataNode* setHead)
	{
                // Creates a pointer for the first node in the stack
		head = setHead;
	}

};

/*****************************************************************************
 * Reverse Polish Calculator
 * __________________________________________________________________________
 * 
 * This program receives a line of ordered numbers and operators, calculates
 * and outputs the result by using reverse polish method.
 * This program can detect errors: division by zero, too many operators, 
 * and too many numbers.
 *  
 *****************************************************************************/
int main()
{
     string dataS;            // INPUT - takes value from the user as a 
                              //         string data
     char oprt;		      // Processing - the operator data
     float floatNum;	      // Processing - the number data
     float result;	      // CALC - the result of the arithmetic
                              //        is either pushed back to the 
                              //        stack, or outputted
     int floatCount = 0;      // CALC - determines how many operands entered
     int oprtCount = 0;       // CALC - determines how many operators entered
     bool divZero = false;    // Boolean - true if division by zero has occurred

     DataNode *head = NULL;   // head of the stack, points to a number

     // Creates a stack, a linked list of numbers 
     Stack *stack = new Stack();

	// OUTPUT - asks the user to input to the list 
	cout << "Enter Data List: " << endl;

       // Processing - while receives string data, performs reverse Polish 
       //              by converting strings to numbers an operators
       //	       calculations all the calculations stops once number 0 
       //              is inputed followed by an enter key
	while (cin >> dataS)
	{
		//Processing - checks if the data is a number
		if(dataS[0] >= 48 && dataS[0] <= 57)
		{
                    // increments the number of operands by one
                    floatCount++;

                    // if a number, converts the literal to a decimal 
                    //      number, saves the number
                    floatNum = strtod(dataS.c_str(), NULL);

                    //insert stack - adds numeric data to the head of the list
                    //      creates the head of the list if it doesn't exist
                    if(!head)
                    {       //Creates a head node for the stack, sets head to the
                            //   current node
                            DataNode *Node = new DataNode(floatNum, head);
                            head = Node;
                            stack->setHead(head);
                    }
                    else            // pushes the number to the stack, sets the 
                                    // head to current head
                                    {
                                            stack->push(floatNum, head);
                                            head = stack->getHead();
                                    }

		}

		//Processing - check if the data entered is a NEGATIVE number
	       else if (dataS.length() != 1 && dataS[1] >= 48 && dataS[1] <= 57)
	       {
                    floatCount++;
                    // converts literal to a floating point number, 
                    floatNum = strtod(dataS.c_str(), NULL);

                    //insert stack - adds numeric data to the head of the list
                    //      creates the head of the list if it doesn't exist
                    if(!head)
                    {       //Creates a head node for the stack, sets head to the
                            //   current node
                            DataNode *Node = new DataNode(floatNum, head);
                            head = Node;
                            stack->setHead(head);
                    }
                    else            // pushes the number to the stack, sets the 
                                    // head to current head
                                    {
                                            stack->push(floatNum, head);
                                            head = stack->getHead();
                                    }

		}

		//Processing - check if the data entered is an operator
		else if (dataS[0] == 42 || dataS[0] == 43 || dataS[0] == 45 
                        || dataS[0] == 47)
		{  
                        //increments the number of operators
			oprtCount++;
			// saves the operator as a character value
			oprt = dataS[0];
			
                        // the last number entered, first on the to of the stack
			float tempFirst;
                        
                        // the first number in the calculations
			float tempSecond;
                        
                        // Processing - receives operator, performs arithmetics
			switch(oprt)
			{
                            case'+':
                                    // error of no data in the list
                                    if(!head)
                                    {
                                         cout << "Error: Too Many Operators. " 
                                              << endl;
                                    }
                                    
                                    else
                                    {       // pops the last variable, sets head
                                            tempFirst = stack->pop();
                                            head = stack->getHead();
                                            
                                            //error if there is no second number
                                            if(!head)
                                            {
                                                  cout << "Error: Too Many "
                                                          "Operators. " << endl;
                                            }
                                            else
                                            {
                                                // popes the second number
                                                tempSecond = stack->pop();
                                                //sets head to the current head
                                                head = stack->getHead();
                                                // calculates and puts the 
                                                // result back to the stack
                                                stack->push(tempSecond + 
                                                            tempFirst,head);
                                                //sets head to current head
                                                head = stack->getHead();
                                            }
                                    }
                                    break;// end of operator +

                            case'-':
                                    // error of no data in the list
                                    if(!head)
                                    {
                                         cout << "Error: Too Many Operators. " 
                                              << endl;
                                    }
                                    
                                    else
                                    {       // pops the last variable, sets head
                                            tempFirst = stack->pop();
                                            head = stack->getHead();
                                            
                                            //error if there is no second number
                                            if(!head)
                                            {
                                                  cout << "Error: Too Many "
                                                          "Operators. " << endl;
                                            }
                                            else
                                            {
                                                // popes the second number
                                                tempSecond = stack->pop();
                                                //sets head to the current head
                                                head = stack->getHead();
                                                // calculates and puts the 
                                                // result back to the stack
                                                stack->push(tempSecond - 
                                                            tempFirst,head);
                                                //sets head to current head
                                                head = stack->getHead();
                                            }
                                    }
                                    break;// end of operator -

                            case'*':
                                    // error of no data in the list
                                    if(!head)
                                    {
                                         cout << "Error: Too Many Operators. " 
                                              << endl;
                                    }
                                    
                                    else
                                    {       // pops the last variable, sets head
                                            tempFirst = stack->pop();
                                            head = stack->getHead();
                                            
                                            //error if there is no second number
                                            if(!head)
                                            {
                                                  cout << "Error: Too Many "
                                                          "Operators. " << endl;
                                            }
                                            else
                                            {
                                                // popes the second number
                                                tempSecond = stack->pop();
                                                //sets head to the current head
                                                head = stack->getHead();
                                                // calculates and puts the 
                                                // result back to the stack
                                                stack->push(tempSecond * 
                                                            tempFirst,head);
                                                //sets head to current head
                                                head = stack->getHead();
                                            }
                                    }
                                    break;// end of operator *

                            case'/':

                                    // error of no data in the list
                                    if(!head)
                                    {
                                         cout << "Error: Too Many Operators. " 
                                              << endl;
                                    }

                                    else
                                    {
                                        tempFirst = stack->pop();
                            
                                        head = stack->getHead();
                                        
                                      //Processing, checks for division by zero
                                        if(tempFirst ==0)
                                        {
                                            cout << "Error:Division by Zero. " 
                                                 << endl << endl;
                                            divZero = true;
                                            break;
                                        }
                         
                                        else
                                        {
                                            // popes the second number
                                            tempSecond = stack->pop();
                                            //sets head to the current head
                                            head = stack->getHead();
                                            // calculates and puts the 
                                            // result back to the stack
                                            stack->push(tempSecond / 
                                                        tempFirst,head);
                                            //sets head to current head
                                            head = stack->getHead();
                                        }
                                    }
                                    break; // end of operator /
				
			}
                        

			
		}
        
        
         //Checks if the user is pressing ENTER key
        char check = cin.get();

        // if user has pressed 0 followed by ENTER key, it ends the program
         if (check == '\n' && dataS[0] == 48)
           {
                   cout << "End of program. " << endl;
                   break;
           }
        
        //Processing - checks if the user has pressed ENTER to get result,
	else if (check == '\n')
           {   
               // Checks if there are too many numbers in the list
               if (floatCount > oprtCount + 1)
               {
                   // OUTPUT- Error: Too Many Operands.
                   cout << "Error: Too Many Operands. " << endl << endl;
                     
                   // cleans the stack of number left overs
                    for(DataNode *tmp = head ; tmp !=0 ; tmp = tmp->next)
                    {
                        stack->pop();
                        head = stack->getHead();
                    }

               }           //checks if there are too many operators in the list
			   else if(floatCount <= oprtCount)
			   {
                                  // OUTPUT- Error: Too Many Operands.
				  cout << "Error: Too Many Operators. " 
                                       << endl << endl;
			   }
                           //Checks if there exist the right number of
                           // operands and operators, and no division by zero
			   else if (floatCount == (oprtCount +1)  && !divZero)
				{
                                   // pops the last node which is the result
				   result = stack->pop();
				   head = stack->getHead();
                                   //OUTPUT - outputs the answer
				   cout << "Result: " << result << endl <<endl;

				}
                                
                                // Assigns the value of the variables to 
                                // initial values, for the next calculation
                                divZero = false;
                                floatCount = 0;
                                oprtCount = 0;
           }

       
	}

return 0;

}


/************************
        OUTPUT
*************************
Enter Data List: 
10 15 +
Result: 25

10 15 -
Result: -5

2.5 3.5 +
Result: 6

10 0 /
Error:Division by Zero. 

10 20 * /
Error: Too Many Operators. 

12 20 30 /
Error: Too Many Operands. 

-10 -30 -
Result: 20

100 10 50 25 / * - -2 /
Result: -40

0
End of program. 

RUN SUCCESSFUL (total time: 1m 36s)

 */