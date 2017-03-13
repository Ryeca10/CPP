
/*
    Data Structures LAB: 
 *  Fall 2013
 *  
 *  Binary Search Tree
    Create a node class/struct
    -Data field
    -2 self referential pointers
    Create a BST class/struct
    -Node field
    Methods:
    Add (data)
    -Adds the data to the tree in sorted order.
    Print()
    -Prints all the nodes using inorder traversal

 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Node
{
public:
	int data;
	Node *left, *right;

	Node(int data, Node *leftOf = NULL, Node *rightOf = NULL)
	{
		this->data = data;
		left = leftOf;
		right = rightOf;
	}
};

class Tree
{
	
public:	
	Node *root;

	Tree()
	{
		root = 0;
	}

	
	bool Add(int data)
	{
		Node *newNode = new Node(data);			
		if (root == 0)									
		{
			root = newNode;
			return true;
		}
		Node *temp = root;							
		while(true)
		{
			if (data < temp->data)						
				if (temp->left == 0)					
				{
					temp->left = newNode;
					break;
				}
				else									
					temp = temp->left;
			else if (data > temp->data)					
				if (temp->right == 0)					
				{
					temp->right = newNode;
					break;
				}
				else									
					temp = temp->right;
			else if (data == temp->data)				
				return false; 
		}
		return true;
	}

	bool insert(int data)
	{
		Node *temp = root, *prev = 0;
		while (temp != 0)
		{
			prev = temp;								
			if (data < temp->data)						
				temp = temp->left;
			else										
				temp = temp->right;
		}

		if (root == 0)									
			root = new Node(data);
		else if (data < prev->data)						
			prev->left = new Node(data);
		else if (data > prev->data)						
			prev->right = new Node(data);
		else											
			return false; 
		return true;
	}

        void inorderTraversal(Node *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			
			cout << temp->data << " ";				
			inorderTraversal(temp->right);			
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
    
    return 0;
}