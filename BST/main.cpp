/*
   DATA STRUCTURES 
 * FALL2013
 * 
 * CUEVAS NOTES
 * BINARY SEARCH TREE
 
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class treeNode
{
public:
	int data;
	treeNode *left, *right;

	treeNode()
	{
		left = right = 0;
	}

	treeNode(int data, treeNode *l = 0, treeNode *r = 0)
	{
		this->data = data;
		left = l;
		right = r;
	}
};
	

class binarySearchTree
{
	
public:	
	treeNode *root;

	binarySearchTree()
	{
		root = 0;
	}

	
	bool addNode(int data)
	{
		treeNode *newNode = new treeNode(data);			// our  new node
		if (root == 0)									// check for an empty root
		{
			root = newNode;
			return true;
		}
		treeNode *temp = root;							// create a temp node to traverse the list
		while(true)
		{
			if (data < temp->data)						// check to see if we will traverse to the left
				if (temp->left == 0)					// check to see if we have found newNode's position
				{
					temp->left = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->left;
			else if (data > temp->data)					// check to see if we will traverse to the right
				if (temp->right == 0)					// check to see if we have found newNode's position
				{
					temp->right = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->right;
			else if (data == temp->data)				// For this implementation, we will not allow duplicates
				return false; // no dupes
		}
		return true;
	}

	//
	// Alternatively
	bool insert(int data)
	{
		treeNode *temp = root, *prev = 0;
		while (temp != 0)
		{
			prev = temp;								// keep track of parent
			if (data < temp->data)						// traverse the left
				temp = temp->left;
			else										// traverse the right
				temp = temp->right;
		}

		if (root == 0)									// check for an empty tree
			root = new treeNode(data);
		else if (data < prev->data)						// see if our position is on the left
			prev->left = new treeNode(data);
		else if (data > prev->data)						// see if our position is on the right
			prev->right = new treeNode(data);
		else											// disallow duplicate data
			return false; // no dupes allowed
		return true;
	}

	bool recurseInsert(treeNode *temp, int data)
	{
		if (data < temp->data)
		{
			if (temp->left != 0)
				recurseInsert(temp->left, data);
			else
			{
				treeNode *newNode = new treeNode(data);
				temp->left = newNode;
				return true;
			}
		}
		else if (data > temp->data)
		{
			if (temp->right != 0)
				recurseInsert(temp->right, data);
			else
			{
				treeNode *newNode = new treeNode(data);
				temp->right = newNode;
				return true;
			}
		}
		else
			return false;
	}

	void recIns(treeNode *temp, int data)
	{
		if (temp == 0)
		{
			treeNode *newNode = new treeNode(data);
			temp = newNode;
		}
		else
		{
			if (data < temp->data)
				recIns(temp->left, data);
			else if (data > temp->data)
				recIns(temp->right, data);
		}
	}


	void inorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			cout << temp->data << " ";				// evaluate (print) current node
			inorderTraversal(temp->right);			// traverse right subtree
		}
	}

	
	void preorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			cout << temp->data << " ";				// evaluate (print) current node
			inorderTraversal(temp->left);			// traverse left subtree
			inorderTraversal(temp->right);			// traverse right subtree
		}
	}

	
	void postorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			inorderTraversal(temp->right);			// traverse right subtree
			cout << temp->data << " ";				// evaluate (print) current node
		}
	}
	

	void rightToLeftInorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			rightToLeftInorderTraversal(temp->right);
			cout << temp->data << " ";
			rightToLeftInorderTraversal(temp->left);
		}
	}



	void findAndDeleteByCopying(int data)
	{    
		treeNode *p = root, *prev = 0;
		
		while (p != 0 && !(p->data == data)) 
		{
			prev = p;
			if (p->data < data)
				p = p->right;
			else p = p->left;
		}
		//
		// If we found it, remove the node.
		if (p != 0 && p->data == data)
			if (p == root)
				deleteByCopying(root);
			else if (prev->left == p)
				deleteByCopying(prev->left);	// pass the parent's link to the node being deleted
			else 
				deleteByCopying(prev->right);	// pass the parent's link to the node being deleted
		else if (root != 0)
			cout << "key " << data << " is not in the tree\n";
		else 
			cout << "the tree is empty\n";
	}
	
	
	void deleteByCopying(treeNode*& node) 
	{   
		
		treeNode *previous, *tmp = node;
		
		if (node->right == 0)                  
			node = node->left;   
		
		else if (node->left == 0)              
			node = node->right;
		
		else // case 3:
		{
			//
			// First step into the left subtree
			tmp = node->left;
			//
			// Start keeping track of the parent
			previous = node;                  
			
			while (tmp->right != 0) 
			{         
				previous = tmp;
				tmp = tmp->right;
			}
			
			node->data = tmp->data;             
			
			if (previous == node)
				previous->left  = tmp->left;		// bridge the gap
			else 
				previous->right = tmp->left;		// bridge the gap
		}
		delete tmp;                            

		
	}

	void rebuildBalance(int array[], int first, int last)
	{
		if (first <= last)
		{
			int middle = (first + last) / 2;
			insert(array[middle]);
			rebuildBalance(array, first, middle-1);
			rebuildBalance(array, middle+1, last);
		}
	}
};

int main (void)
{
	
	binarySearchTree bst;
	bst.recIns(bst.root, 10);
	bst.recIns(bst.root, 5);
	bst.recIns(bst.root, 15);
	bst.recIns(bst.root, 12);
	bst.recIns(bst.root, 17);
	bst.recIns(bst.root, 19);

	bst.addNode(50);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(75);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(25);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(100);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(62);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(37);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(12);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(70);
	bst.inorderTraversal(bst.root);
	cout << endl;

	bst.findAndDeleteByCopying(75);

	binarySearchTree myTree;
	myTree.insert(50);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(75);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(25);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(100);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(62);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(37);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(12);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	cout << endl;
	cout << endl;
	myTree.rightToLeftInorderTraversal(myTree.root);
	cout << endl;

	
	return 0;
}
