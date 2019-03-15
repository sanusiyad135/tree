//Program to demonstrate a binary search tree
// Including library
#include<iostream>

// using namespace std
using namespace std;

//including class node
class Node
{
public:
//data variable
int data;
//pointers to move to left and right child
Node *left;
Node *right;
	//constructor to initialize left and right pointers as NULL
Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};
//including class BST
class BST{
  public:
//pointer that points to root of the tree
Node *root;
//constructor to initialize root as NULL
	BST(){
		root = NULL;
	}
	//function inorder to insert value into tree
void insert(int value){
		insertHelper(root,value);
	}
	//recursive function to insert values to the tree
void insertHelper(Node *curr, int value){
//Base case if curr is NULL, insert there
    if(curr == NULL){
			curr = new Node(value);
			//update head
			if(root == NULL)
				root = curr;
			return;
		}
		//else compare curr data with value
else if(value < curr->data){
			//checks if left child of current is NULL
			//if yes, then inserts there or else moves to current pointer's left child's left child
if(curr->left == NULL)
				curr->left = new Node(value);
else
				insertHelper(curr->left,value);
		}
else{
			//similar approach for the right child as well
if(curr->right == NULL)
				curr->right = new Node(value);

else
				insertHelper(curr->right,value);
		}
	}
	//display function
void display(){
		//recursive call
		display2(root);
	}
	//recursive display function
void display2(Node *curr){
		//base case
		if(curr == NULL)
			return;
		//display left
		display2(curr->left);
		//display current
		cout<<curr->data<<"->";
		//display right
		display2(curr->right);
	}
	//search function
void search(int value){
		cout<<endl;
		Node * var;
		var = search2(root,value);
		if(var == NULL)
			cout<<"Sorry, the element does NOT EXIST\n";
		else
			cout<<"The element EXISTS\n";
	}

	//recursive function for searching
	//returns the address of the node containing the value to be searched
	Node * search2(Node *curr,int value)
	{

		if(curr == NULL || curr->data == value)                    //if else condition
			return curr;

		else if(value < curr->data)
			return search2(curr->left,value);

		else
			return search2(curr->right,value);
	}
};
//driver function
int main(){
	//Variable declaration
	BST b1;
	int x;
	//insertion of values
	for(int i=1;i<6;i++)
		b1.insert(i);
	//displaying the tree
	b1.display();
	//entering a value to be searched
	cout<<endl<<"Enter value to be searched\n";
	cin>>x;
	b1.search(x);
	//return
return 0;
}
