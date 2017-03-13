
/***************************************************************************
 * NAME       :  RAIKA SANII
 * STUDENT ID :  101239
 * ASSIGNMENT :  PROGRAM2 / Name-Weight List
 * CLASS      :  CS-41
 **************************************************************************/


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/****************************************************************
 * Class DataNode
 * _____________________________________________________________
 *
 * This class creates nodes that contains names as well
 * as weights for a list of gym members, each node is assigned 
 * to a numeric data and to a string. If one data
 *
 ***************************************************************/
 class Node
 {
        public:
            
            string stringInfo;      // The string value of class Node
            int intInfo;            // The integer value of class Node
            
            Node *nextString;      // Is to point at the next string in a list
            Node *nextInt;         // Is to point at the next integer in a list
          
            
            
        /****************************************************************
         * Overloaded Constructor of Node class
         * _____________________________________________________________
         *
         * Four variables are passed to it:
         *          
         *       string name     : to input names in the node
         *       int weight      : to input weights in the node
         *       Node *newName   : to point to the next name in a future list
         *       Node *newWeight : to point to the next weight in a future list
         ***************************************************************/
         Node (string name, int weight, Node *nextWeight = NULL
                 , Node *nextName = NULL)
         {
            stringInfo = name;  // sets the public value of stringInfo to name
            intInfo =  weight;  // sets the public value of intInfo to weight

            nextString = nextName;  // sets the public value of nextString 
                                    //      to nextName
            nextInt = nextWeight;   // sets the public value of nextInt
                                    //      to nextWeight 

         }
 };
 
 /*****************************************************************************
 * Class Stack
 * ___________________________________________________________________________
 *
 * Creates two singly linked lists with one list of nodes
 * This class has 3 public methods:
 *                   
 *      Insert() method           : To input names, and weights in separate 
 *                                     nodes, in the list
 *      OutputByName() method     : To output member list`s information, 
 *                                    in alphabetic order
 *      OutputByWeight() method   : To output member list`s information,
 *                                    weights in order 
 *****************************************************************************/
 class List
 {
     
    private:
        
        Node *head1,          // The head of the weight list
             *head2,          // The head of the names list
             *nextString,     // Points to the next string (next name)
             *nextInt;        // Points to the next integer(next weight)
   
    public:
        
        //The constructor of the list
        List()
        {
            head1 = head2 = NULL;  //Sets the two heads to NULL
        }

        /****************************************************************
         * Insert Function
         * _____________________________________________________________
         *
         * This function makes nodes of members as it is entered, and makes 
         * a list of nodes.
         *      
         *      Inputs:
         *              string name;
         *              int weight;
         * 
         *      Processing:
         *              Node *newNode;
         *              Node *tmp;
         * 
         *      Output:
         *              This function has no output.
         * 
         ***************************************************************/        
        void Insert()
        {
            string name;        // IN - To input name from the user
            int weight;         // IN - To input weight from the user
            Node *tmp;          // Processing - temporarily points to the a node

            cout << "Enter List: " << endl;
            
            // Processing - while the user in inputting data, a new node is 
            //              created that contains both name, and weight of a 
            //              member, then the node is inserted to its right place
            //              whether alphabetically, or numerically sorted to the 
            //              right place. In the end of the while loop, the 
            //              output function are called to print the list as data 
            //              is entered.
            while(cin)
            {
                // INPUT - to input name and weight to the node
                cin >> name;
                cin >> weight;

                // Processing - creates a new node for the list
                Node *newNode = new Node(name, weight, nextString, nextInt);
                
                // Processing - sets a new head, if there is no head
                if (!head1)
                {
                    head1 = head2 = newNode;
                } 
                
                // Processing - sets the head to the new node if the new node 
                //              has an integer value less than the head 
                if (newNode->intInfo < head1->intInfo)
                {
                    tmp = head1;          // tmp points where head is pointing
                    head1 = newNode;      // head is equal to newNode
                    newNode->nextInt = tmp;   // the node after newNode is equal 
                                              // to the previous head
                }
                
                // Processing - checks if the new node is bigger than the head
                else if(newNode->intInfo >= head1->intInfo)
                    // Processing - from the beginning to the end of the list
                    //              compares integer value of the nodes 
                    for (tmp = head1 ; tmp != 0 ; tmp = tmp->nextInt)
                    
                        // Processing - checks is if the new node`s value is 
                        //              higher than the last node in the list
                        if (tmp->nextInt == NULL && 
                            tmp->intInfo <= newNode->intInfo)
                        {
                            // sets the last node to the new node
                            tmp->nextInt = newNode; 
                            // the last node points no NULL
                            newNode->nextInt = NULL ;   
                        }
                        
                        // Processing - checks to find a pair of nodes, 
                        //              first one less than, second one more
                        //              than the new node
                        else if(tmp->intInfo < newNode->intInfo && 
                                tmp->nextInt->intInfo >= newNode->intInfo)
                        {
                            // a temporary node is pointing to the next node
                            Node *tmp1 = tmp->nextInt; 
                            // the next node is equal to the new node
                            tmp->nextInt = newNode;
                            // new node is pointing to the previous next node, 
                            // which is already in the list
                            newNode->nextInt= tmp1;          
                        }
               
               // Processing - checks if a node`s string value is alphabetically 
               //              less than the new node            
                if (strcmp(name.c_str(),head2->stringInfo.c_str()) < 0 )
                {
                    // sets temporary node where the head is pointing to
                    tmp = head2;
                    // sets the new node as the head
                    head2 = newNode;
                    // connects the new head to the previous head, setting the 
                    // previous head as the node after the new head
                    newNode->nextString = tmp;
                }
                
                // processing - Checks if the new node is bigger than the head
                else if (strcmp(name.c_str(),head2->stringInfo.c_str()) >= 0 )
                
                     // Processing - from the beginning to the end of the list
                     //              compares string value of the nodes 
                    for (tmp = head2 ; tmp != 0 ; tmp = tmp->nextString)
                    
                        // Processing - checks is if the new node`s value is 
                        //              higher than the last node in the list
                        if(tmp->nextString == NULL && (strcmp(name.c_str(), 
                           tmp->stringInfo.c_str()) >= 0) )
                        {
                            // sets the last node to the new node
                            tmp->nextString = newNode;
                            // sets the last node(just added) no point to Null
                            newNode->nextString = NULL ; 
                        }
                        
                        else 
                        
                        // Processing - checks to find a pair of nodes, 
                        //              first one less than, second one more
                        //              than the new node    
                        if(strcmp(name.c_str(), tmp->stringInfo.c_str()) > 0  
                           && strcmp(name.c_str(), 
                              tmp->nextString->stringInfo.c_str()) <= 0)
                        {
                            // a temporary node is pointing to the next node
                            Node *tmp1 = tmp->nextString;
                            // the next node is equal to the new node
                            tmp->nextString = newNode;
                            // new node is pointing to the previous next node, 
                            // which is already in the list
                            newNode->nextString= tmp1;
                        }
  
                // Calls on the function to output list, weights ascending
                OutputByWeight();
                // Calls on the function to output list, names ascending
                OutputByName();
 
            }
 
        }

        /****************************************************************
        * OutputByName Function
        * _____________________________________________________________
        *
        * This is an Output function. This function outputs the members` 
        * information, arranging their names in alphabetic order.
        *      
        *      Inputs:
        *              No inputs.
        * 
        *      Processing:
        *              Node *tmp;
        *              
        *      Output:
        *              The List() in alphabetic order of names.
        * 
        ***************************************************************/ 
        void OutputByName() 
        {
            
            cout << "Names & weights sorted(ascending) by name: " << endl;
            
            // Output - from the beginning to the end of the list
            //              prints the values of nodes, 
            for (Node *tmp = head2; tmp != 0; tmp = tmp->nextString)
                
                if (tmp->nextString != NULL)
                {
                   cout << tmp->stringInfo << "-";
                   cout << tmp->intInfo << ", ";
                }

                // Output - the last node
                else
                {
                    cout << tmp->stringInfo << "-";
                    cout << tmp->intInfo;
                } 

            cout << endl<< endl;
        }

        /****************************************************************
         * OutputByWeight Function
         * _____________________________________________________________
         *
         * This is an Output function. This function outputs the members` 
         * information, arranging their weights in order from lower to 
         * higher weights
         *      
         *      Inputs:
         *              No inputs.
         * 
         *      Processing:
         *              Node *tmp;
         *              
         *      Output:
         *              The List() in order of weights, from lower to higher
         * 
         ***************************************************************/ 
         void OutputByWeight() 
         {
           cout << endl;
           cout << "Names & weights sorted(ascending) by weight: " << endl;

           // Output - from the beginning to the end of the list
            //         prints the values of nodes
           for (Node *tmp = head1; tmp != 0; tmp = tmp->nextInt)
                if (tmp->nextInt != NULL)
                 {
                    cout << tmp->stringInfo << "-";
                    cout << tmp->intInfo << ", ";
                 }
           
                 // Output - the last node
                 else
                 {
                     cout << tmp->stringInfo << "-";
                     cout << tmp->intInfo;
                 }   

           cout << endl << endl;
         }

 };
 
/*****************************************************************************
 * Name-Weight List 
 * __________________________________________________________________________
 * 
 * This program receives a series of names and weight from the user, then 
 * arranges the list in alphabetic order, an in the order of the members` 
 * weights from low to higher weights
 *  
 *****************************************************************************/    
int main()
{
    Node *mainNode;   // Nodes containing names and weights, passed to the main
    List *memberList = new List();  // The members List

    memberList->Insert();   // Calling on Insert method of class List

    
    return 0;
}



//___________________________________________________________________________
//                              OUTPUT
/*
 * Enter List: 
Jim
150
Tom
212
Michael
174
Abe
199
Richard
200
April
117
Claire
124
Bobby
109
Bob
156
Kevin
145
Jason
182
Brian
150
Chris
175
Steven
164
Annabelle
99
Blake 
180
Rob
167
Sam
140

Names & weights sorted(ascending) by weight: 
Jim-150

Names & weights sorted(ascending) by name: 
Jim-150


Names & weights sorted(ascending) by weight: 
Jim-150, Tom-212

Names & weights sorted(ascending) by name: 
Jim-150, Tom-212


Names & weights sorted(ascending) by weight: 
Jim-150, Michael-174, Tom-212

Names & weights sorted(ascending) by name: 
Jim-150, Michael-174, Tom-212


Names & weights sorted(ascending) by weight: 
Jim-150, Michael-174, Abe-199, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, Jim-150, Michael-174, Tom-212


Names & weights sorted(ascending) by weight: 
Jim-150, Michael-174, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, Jim-150, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
April-117, Jim-150, Michael-174, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Jim-150, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
April-117, Claire-124, Jim-150, Michael-174, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Claire-124, Jim-150, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Jim-150, Michael-174, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bobby-109, Claire-124, Jim-150, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Jim-150, Bob-156, Michael-174, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bob-156, Bobby-109, Claire-124, Jim-150, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Kevin-145, Jim-150, Bob-156, Michael-174, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bob-156, Bobby-109, Claire-124, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Kevin-145, Jim-150, Bob-156, Michael-174, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bob-156, Bobby-109, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Michael-174, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bob-156, Bobby-109, Brian-150, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Michael-174, Chris-175, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212


Names & weights sorted(ascending) by weight: 
Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Michael-174, Chris-175, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, April-117, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Steven-164, Tom-212


Names & weights sorted(ascending) by weight: 
Annabelle-99, Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Michael-174, Chris-175, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, Annabelle-99, April-117, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Steven-164, Tom-212


Names & weights sorted(ascending) by weight: 
Annabelle-99, Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Michael-174, Chris-175, Blake-180, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, Annabelle-99, April-117, Blake-180, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Steven-164, Tom-212


Names & weights sorted(ascending) by weight: 
Annabelle-99, Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Rob-167, Michael-174, Chris-175, Blake-180, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, Annabelle-99, April-117, Blake-180, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Rob-167, Steven-164, Tom-212


Names & weights sorted(ascending) by weight: 
Annabelle-99, Bobby-109, April-117, Claire-124, Sam-140, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Rob-167, Michael-174, Chris-175, Blake-180, Jason-182, Abe-199, Richard-200, Tom-212

Names & weights sorted(ascending) by name: 
Abe-199, Annabelle-99, April-117, Blake-180, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Rob-167, Sam-140, Steven-164, Tom-212

 */       
