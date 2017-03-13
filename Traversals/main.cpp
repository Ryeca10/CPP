#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


class Node
{
    public:
        int num;
        Node *left, *right;

        Node(int integer, Node *lOf = NULL, Node *rOf = NULL)
        {
            left = right = NULL;
            num = integer;
            left = lOf;
            right = rOf;
            
        }
};

class Tree
{
public:    
    Node *root;
    Node *l;
    Node *r;
    int count;
    Tree()
    {
        root = NULL;
        count = 0;
    }


   	bool addNode(int data)
	{
		Node *newNode = new Node(data, l =NULL, r = NULL);			// our  new node
		if (root == 0)									// check for an empty root
		{
			root = newNode;
			return true;
		}
		Node *temp = root;							// create a temp node to traverse the list
		while(true)
		{
			if (data < temp->num)						// check to see if we will traverse to the left
				if (temp->left == 0)					// check to see if we have found newNode's position
				{
					temp->left = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->left;
			else if (data > temp->num)					// check to see if we will traverse to the right
				if (temp->right == 0)					// check to see if we have found newNode's position
				{
					temp->right = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->right;
			else if (data == temp->num)				// For this implementation, we will not allow duplicates
				return false; // no dupes
		}
		return true;
	}

	//
	// Alternatively
	bool insert(int data)
	{
		Node *temp = root, *prev = 0;
		while (temp != 0)
		{
			prev = temp;								// keep track of parent
			if (data < temp->num)						// traverse the left
				temp = temp->left;
			else										// traverse the right
				temp = temp->right;
		}

		if (root == 0)									// check for an empty tree
			root = new Node(data);
		else if (data < prev->num)						// see if our position is on the left
			prev->left = new Node(data);
		else if (data > prev->num)						// see if our position is on the right
			prev->right = new Node(data);
		else											// disallow duplicate data
			return false; // no dupes allowed
		return true;
	}

    void inorderTraversal(Node *tmp)
    {
        if (tmp != 0)
        {
            inorderTraversal(tmp->left);            
            cout << tmp->num << " ";                
            inorderTraversal(tmp->right);           
        }
    }
    
    void preorderTraversal(Node *tmp)
    {
            if (tmp != 0)
            {
                    cout << tmp->num << " ";				
                    inorderTraversal(tmp->left);			
                    inorderTraversal(tmp->right);			
            }
    }


    void postorderTraversal(Node *tmp)
    {
            if (tmp != 0)
            {
                    inorderTraversal(tmp->left);			
                    inorderTraversal(tmp->right);			
                    cout << tmp->num << " ";				
            }
    }
	
    
};



int main ()
{
    Tree *tree = new Tree();
    Node *root;
    
    int weight;
    
    
    cout<<"Enter the weight, enter -1 to exit: "<<endl;
    cin >> weight;
    
    while (weight != -1)
    {
    
            tree->insert(weight);
            cout<<"Enter the weight, enter -1 to exit: "<<endl;
            cin >> weight;
  
    }
    
    cout << "Inorder Traversal: " << endl;
    tree->inorderTraversal(tree->root);
    cout << "Postorder Traversal: " << endl;
    tree->postorderTraversal(tree->root);
    cout << "Preorder Traversal: " << endl;
    tree->preorderTraversal(tree->root);
    return 0;
}