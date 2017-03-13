/*
 Raika Sanii
 
 ID # 101239
 
 CS-41

 PROGRAM 3
 
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/****************************************************************
 *    Class TreeNode
 *    ___________________________________________________________
 *
 *    Contains nodes that carry both name(string) and weight
 *    (integer). TreeNodes are doubly linked fro, left and right
 *
 ****************************************************************/

class TreeNode
{
public:
        string stringData;  //name
	int intData;        // weight
	TreeNode *left, *right;   // left node and right node

    // Default constructor of a TreeNode
    TreeNode()
    {
        left = right = NULL;  // the left ad right of each node is set to NULL
    }

    // Over-loaded constructor
    TreeNode(string name, int weight, TreeNode *l = NULL, TreeNode *r = NULL)
    {
            stringData = name; 
            intData = weight;
            left = l;
            right = r;
    } 
   
};


/******************************************************************************
 * Class Tree
 * __________________________________________________________________
 * 
 * Is a Binary Search Tree, with string names as the code values. 
 * The Tree holds the nodes in alphabetical order, adding nodes to 
 * the tree as the data is entered. There are the following methods 
 * in this class:
 * 
 *            BuildTree    Builds the name tree as the data is entered
 *     InorderTraversal    Finds and prints names in an in-order traversal
 *   PreOrder Traversal    Finds and prints names in a Pre-order traversal
 *   PostOrderTraversal    Finds and prints names in a Post-order traversal
 *           ReturnLeaf    Calculates and returns the number of leaves
 *           NameExists    Determines if a name exists in the tree, finds the 
 *                              associated weight
 *               Height    Calculates and returns the height of the tree
 *         SmallestName    Finds the first name in alphabetical order
 *           HighWeight    Finds and returns the highest weight
 *            LowWeight    Finds and returns the lowest weight
 *            AvgWeight    Calculates and returns the average weight                      
 *****************************************************************************/
class Tree
{
    
private:
    
    int leaf;         //The number of leaves in a tree
    int count;        //Number of nodes in a tree
    int highWeight;   //Highest weight in a tree
    int lowWeight;    //Lowest Weight in a tree  
    int avgWeight;    //Average weight in a tree
    int leftBranch;   //The edge on the left side of a node
    int rightBranch;  //The edge on the right side of the node
    
    
    
public:
   
    TreeNode *root;   // The root of the tree, that is the first data entered
  
    //Default Constructor of a class tree, the variables have been initialized
    Tree()
    {
        leaf = 0;   
        count = 0;
        highWeight = 0;
        lowWeight = 1000000;
        avgWeight = 0;
        root = 0;
        leftBranch = 0;
        rightBranch = 0;
    }

   /********************************************************************
    * BuildTree
    * ____________________________________________________________
    * 
    * Builds the tree as data is entered, names are the key values
    * 
    *           returns false if a name value is duplicated
    *           returns true if a new name value is added 
    * 
    ********************************************************************/
    bool  BuildTree(string name, // INPUT - name
                    int weight)  // INPUT - weight
    {
           // makes a new node
           TreeNode *newNode = new TreeNode(name, weight);	

           // If no root, the first node is the root
           if (root == 0)									
           {
                   root = newNode;
                   return true;
           }

           // assigns he value of rot to the temporary variable
           TreeNode *tmp = root;	

           // Processing - while non-douplicated nodes are inputed, 
           //              find the nodes place in the tree 
           while(true)
           {
                   // If the new name is less than the node name, go left
                   if (strcmp(name.c_str(), tmp->stringData.c_str()) <0)	

                           // If the left position is empty, place the new node
                           if (tmp->left == 0)					
                           {
                                   tmp->left = newNode;
                                   break;
                           }
                           // if the left position is not available, traverse left
                           else									
                                   tmp = tmp->left;

                   // If the new name is more than the current node, traverse right
                   else if (strcmp(name.c_str(), tmp->stringData.c_str()) >0)

                           // If the right position is available, place the new node
                           if (tmp->right == 0)					
                           {
                                   tmp->right = newNode;
                                   break;
                           }
                   
                           // If the right position is not available, traverse right
                           else									
                                   tmp = tmp->right;

                   // If the new names` value is equal to the current node, return false
                   else if (strcmp(name.c_str(), tmp->stringData.c_str()) == 0)				
                           return false;
           }
           // If node placement is done successfully, return true
           return true;
    }
    
    
    /********************************************************************
    * InOrderTravessal
    * ____________________________________________________________
    * 
    * Finds and prints nodes in an in-order fashion
    * 
    *           returns nothing
    * 
    ********************************************************************/
    void InOrderTraversal(TreeNode *tmp)
    {
           // If the member nodes still exist
           if (tmp != 0)
           {
                   //keep traversing left
                   InOrderTraversal(tmp->left);	
                   // Print each node on the way
                   cout << tmp->stringData << " ";
                   //Keep traversing right
                   InOrderTraversal(tmp->right);		
           }
    }

    /********************************************************************
    * PreOrderTravessal
    * ____________________________________________________________
    * 
    * Finds and prints nodes in an pre-order fashion
    * 
    *           returns nothing
    * 
    ********************************************************************/
    void PreOrderTraversal(TreeNode *tmp)
    {
            // If the member nodes still exist
           if (tmp != 0)
           {	
                   // Print name
                   cout << tmp->stringData << " ";
                   // Keep traversing left and printing
                   PreOrderTraversal(tmp->left);
                   // Keep traversing right and printing
                   PreOrderTraversal(tmp->right);
           }
    }

    /********************************************************************
    * PostOrderTravessal
    * ____________________________________________________________
    * 
    * Finds and prints nodes in an post-order fashion
    * 
    *           returns nothing
    * 
    ********************************************************************/
    void PostOrderTraversal(TreeNode *tmp)
    {
            // If the member nodes still exist
           if (tmp != 0)
           {
                   // Keep traversing left 
                   PostOrderTraversal(tmp->left);
                   // Keep traversing right
                   PostOrderTraversal(tmp->right);
                   // Print name
                   cout << tmp->stringData << " ";	
           }
    }

    /********************************************************************
    * ReturnLeaf
    * ____________________________________________________________
    *   
    *  Calculate the number of leaves
    *           
    *           Returns the number of leaves 
    * 
    ********************************************************************/
    int ReturnLeaf(TreeNode *tmp)
    {
         // If the member nodes still exist
        if(tmp != 0)
        {
            //Keep traversing left
            ReturnLeaf(tmp->left);
            // if no children were found, add leaf by 1
            if (tmp->left == 0 && tmp->right == 0)
                leaf++;
            // Keep traversing right
            ReturnLeaf(tmp->right);
        } 

        return leaf;
    }
      
    
    /********************************************************************
    * NameExists
    * ____________________________________________________________
    *   
    *  Checks whether a name exists in the tree, finds and prints the 
    *  associated weight with that name
    *           
    *           Returns nothing
    * 
    ********************************************************************/
    void NameExists(string searchName)
    {
        // initializes temporary node too root, and the previous node to NULL
       TreeNode *p = root, *prev = 0;

       // While there is still nodes in the tree and the search name is not found
       while (p != 0 && !(strcmp(searchName.c_str(),p->stringData.c_str())==0)) 
       {
               // save the value of current node
               prev = p;
               // if search name is bigger than current name, traverse right
               if (strcmp(searchName.c_str(),p->stringData.c_str())>0)
                       p = p->right;
               // if search name is less than the current name, traverse left
               else p = p->left;
       }

       //If search name is equal to current name, print the associated weight 
       if (p != 0 && strcmp(searchName.c_str(),p->stringData.c_str())==0)
           cout << searchName << " found, the weight is: " << p->intData  
                << endl;
       else 
           cout << "The name was not found. " << endl;

    }
      
    
    /********************************************************************
    * Height
    * ____________________________________________________________
    *   
    *  Calculate the height of the tree
    *           
    *           Returns the height of the tree
    * 
    ********************************************************************/
    int Height(TreeNode *tmp)
    {

        // If there is no node in the tree, return zero
        if(tmp==NULL)
        {
            return 0;
        }

        // if there is no children in the tree, return zero
        else if(tmp->left == NULL && tmp->right == NULL)
        {
            return 0;
        }   

        // if there are edges
        else
        {
            // 
            leftBranch=Height(tmp->left);
            //
            rightBranch=Height(tmp->right);

            //if an edge is found on the left side, add to the branches
            if (leftBranch>rightBranch)
            {
                leftBranch += 1;
                // return the total branches
                return leftBranch;
            }
            //if an edge is found on the right side, add to the branches
            else
            {
                rightBranch += 1;
                //return the total branches
                return rightBranch;
            }


        }

    }

    /********************************************************************
    * SmallestName
    * ____________________________________________________________
    *   
    *  Finds the name that comes first in alphabetic order
    *           
    *           Returns nothing
    * 
    ********************************************************************/
    void SmallestName(TreeNode *tmp)
    {

        // Keep as left as possible
        while(tmp->left != 0 )
        {
            tmp = tmp ->left;
        }
        
        // print the name at thevery left position
         cout << "The first name in alphabetical order is: " 
              << tmp->stringData<< endl;
    }

  /********************************************************************
    * HighWeight
    * ____________________________________________________________
    *   
    *  Finds the highest weight in the tree
    *           
    *           Returns the highest weight in the tree
    * 
    ********************************************************************/
    int HighWeight(TreeNode *tmp )
    { 
         // If the member nodes still exist
        if(tmp != 0)
        {
            // keep traversing left
            HighWeight(tmp->left);
            // if  a higher weight in found, assign highest to that value
            if (highWeight < tmp->intData)	
                highWeight = tmp->intData;
            // Keep traversing right
            HighWeight(tmp->right);
        }

        return highWeight;
    } 

    
    /********************************************************************
    * LowWeight
    * ____________________________________________________________
    *   
    *  Finds the lowest weight in the tree
    *           
    *           Returns the lowest weight in the tree
    * 
    ********************************************************************/
    int LowWeight(TreeNode *tmp )
    { 
         // If the member nodes still exist
        if(tmp != 0)
        {
            // keep traversing left
            LowWeight(tmp->left);
            // if a lower weigh is found, assign the lowest weight to that weight
            if (lowWeight > tmp->intData)	
                lowWeight = tmp->intData;
            // Keep traversing right
            LowWeight(tmp->right);
        }

        return lowWeight;
    } 

    /********************************************************************
    * AvgWeight
    * ____________________________________________________________
    *   
    *  Finds the Average weight in the tree
    *           
    *           Returns the average weight in the tree
    * 
    ********************************************************************/
    float AvgWeight(TreeNode *tmp )
    { 
          // If the member nodes still exist
          if(tmp != 0)
          {
              // Keep traversing lect
              AvgWeight(tmp->left);
              //add every node to the total values, increment the number of nodes by one
              avgWeight += tmp->intData;
              count++;
              // Keep traversing right
              AvgWeight(tmp->right);
          }

          // return the average value
          return float(avgWeight)/count;
    }  
};

int main()
{
    string name;        //INPUT - Name of a new member
    string searchName;  //INPUT - a name to be searched for
    int weight;         //INPUT - weight of a new member     
    int leaf;           //CALC & OUTPUT - number of leaves in the tree
    int height;         //CALC & OUTPUT - height of the tree
    int highest;        //Process & OUTPUT - The highest weight in the tree
    int lowest;         //Process & OUTPUT - The lowest weight in the tree
    float avg;          //CALC & OUTPUT - The average weight in the tree
    Tree *tree = new Tree();      // The name-weight tree
    
    
    cout << "Enter name, enter 0 to exit: ";
    cin >> name;
    
    // Processing - if name is not 0, enter name and weight
    while (name[0] != 48)
    {
        cout << "Enter weight: ";
        cin >> weight;
        
        //Builds the tree by passing name and weight
        tree->BuildTree(name, weight);
        
        cout << "Enter name, enter 0 to exit: ";
        cin >> name;
    }

    cout<< "In-order Traversal: ";
    // Processing and OUTPUT - Prints names, in-order traversal 
    tree->InOrderTraversal(tree->root);
    cout<< endl;
    
    
    cout<< "Pre-order Traversal: ";
    // Processing and OUTPUT - Prints the names, Pre-Order Traversal
    tree->PreOrderTraversal(tree->root);
    cout << endl;
    
    
    cout<< "Post-order Traversal: ";
    // Processing and OUTPUT - Prints the names, PostOrder Traversal
    tree->PostOrderTraversal(tree->root);
    cout << endl;
    
    // CALC - Calculates the number of leaves in a tree
    leaf = tree->ReturnLeaf(tree->root);
    cout << "The number of leaves: " << leaf << endl;
    
    cout << "Who are you searching for: " << endl;
    cin >> searchName;
    // Processing - By passing the name to be searched for, finds out 
    //              whether the searched name exists
    tree->NameExists(searchName);
   
    // Processing - Finds the highest weight
    highest = tree->HighWeight(tree->root);
    //Processing -finds the lowest weight
    lowest = tree->LowWeight(tree->root);
    // CALC - finds the average weight
    avg = tree->AvgWeight(tree->root);

    // OUTPUT - Highest, lowest, and the average weight
    cout << "The highest weight is " << highest << endl;
    cout << "The lowest weight is " << lowest << endl;
    cout << "The average weight is " << avg << endl;

    // CALC - Calculates the height of the tree
    height = tree->Height(tree->root);
    cout << "The height of the tree is: " << height << endl;

    // Processing - Finds the name that alphabetically comes first in the tree
    tree->SmallestName(tree->root);
   
   
   return 0;
}

/*
 
 Enter name, enter 0 to exit: mike
Enter weight: 56
Enter name, enter 0 to exit: dihe
Enter weight: 34
Enter name, enter 0 to exit: patric
Enter weight: 56
Enter name, enter 0 to exit: charley
Enter weight: 25
Enter name, enter 0 to exit: hiro
Enter weight: 79
Enter name, enter 0 to exit: nancy
Enter weight: 74
Enter name, enter 0 to exit: sue
Enter weight: 68
Enter name, enter 0 to exit: blake
Enter weight: 86
Enter name, enter 0 to exit: raika
Enter weight: 28
Enter name, enter 0 to exit: xie
Enter weight: 35
Enter name, enter 0 to exit: 0
In-order Traversal: blake charley dihe hiro mike nancy patric raika sue xie 
Pre-order Traversal: mike dihe charley blake hiro patric nancy sue raika xie 
Post-order Traversal: blake charley hiro dihe nancy raika xie sue patric mike 
The number of leaves: 5
Who are you searching for: 
xie
xie found, the weight is: 35
The highest weight is 86
The lowest weight is 25
The average weight is 54.1
The height of the tree is: 3
The first name in alphabetical order is: blake

RUN SUCCESSFUL (total time: 1m 10s)

 
 
 
 */