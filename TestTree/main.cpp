 #include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//int myArray [100];


class treeNode
{
public:
    int data;
    treeNode *left, *right;


    treeNode()
    {
        left = right = 0;
    }

    treeNode(int d, treeNode *l = 0, treeNode *r = 0)
    {
        data = d;
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
        
        treeNode *newNode = new treeNode(data);            // our  new node
        if (root == 0)                                    // check for an empty root
        {
            root = newNode;
            return true;
        }
        treeNode *temp = root;                            // create a temp node to traverse the list
        while(true)
        {
            if (temp->data > data)            //if negative, then smaller than s (the parameter)// check to see if we will traverse to the left
                if (temp->left == 0)                    // check to see if we have found newNode's position
                {
                    temp->left = newNode;
                    break;
                }
                else                                    // move to subtree
                {
                    temp = temp->left;
                }
            else if (temp->data < data)        // check to see if we will traverse to the right
                if (temp->right == 0)                    // check to see if we have found newNode's position
                {
                    temp->right = newNode;
                    break;
                }
                else                                    // move to subtree
                {
                    temp = temp->right;
                }
            else if (temp->data == data)        // For this implementation, we will not allow duplicates
                return false; // no dupes
        }
        return true;
    }

    void inorderTraversal(treeNode *temp)
    {
        if (temp != 0)
        {
            inorderTraversal(temp->left);            // traverse left subtree
            cout << temp->data << " || ";                // evaluate (print) current node
            inorderTraversal(temp->right);            // traverse right subtree
        }
    }
};

int main (void)
{
    // Demonstrating addNode method
    binarySearchTree bst;

    string y="random", t = "T";
    int x=-1;
    
    while (x != 0)
    {
        cout<<"State the weight, insert T to terminate "<<endl;
        cin>>x;
        if (x != 0)
        {
        bst.addNode(x);
        }
        /*bst.addNode(5, "b");
        bst.addNode(25, "c");
        bst.addNode(4, "d");
        bst.addNode(467, "a");*/
    } 
    
    bst.inorderTraversal(bst.root);
    cout << endl;

    system("PAUSE");
    return 0;
}