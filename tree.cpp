#include<iostream>
#include"stack.h"
using namespace std;

struct node
{
	node *left;
	char data;
	node *right;
};

class binary_tree
{

public:

	node *root;

	binary_tree()
	{
		root=NULL;
	}

	void create();
	void rec_inorder(node *);
	void preorder(node *);
};

void binary_tree::create()
{
	node *temp;
	node *curr;

		curr=new node;

		cout<<"ENTER DATA(char):	";
		cin>>curr->data;

		curr->left=curr->right=NULL;

		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;

		do
		{
			char ans;
			cout<<"WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF "<<temp->data<< ":	";
			cin>>ans;
			cout<<endl;

			if(ans=='l')
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=curr;
					break;
				}
				else
				{
					temp=temp->right;
				}
			}
		}while(1);

	}
}


void binary_tree::rec_inorder(node *root)
{
	if(root!=NULL)
	{
		rec_inorder(root->left);

		cout<<root->data;
		cout<<"\t";

		rec_inorder(root->right);
	}
}

void binary_tree::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data;
		cout<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}



int main()
{
	char ch;

	binary_tree b1;

	do
	{
		cout<<"-----------------------------------------------------------------------------------------\n"<<endl;
		cout<<"1] CREATE NODE.	2] INORDER(recursive).  3] PREORDER.    	4] EXIT."<<endl;
		cout<<"ENTER YOUR CHOICE:	";
		cin>>ch;

		switch(ch)
		{
			case '1':
				b1.create();
				cout<<"\n\n";
				break;

			case '2':
				cout<<"DISPLAYING AS INORDER!!"<<endl;
				b1.rec_inorder(b1.root);
				cout<<"\n\n";
				break;



			case '3':
				cout<<"DISPLAYING AS PREORDER!!"<<endl;
				b1.preorder(b1.root);
				cout<<"\n\n";
				break;
		}
	}while(ch!='4');

	return 0;
}


/*

---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	A


---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	B
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	l



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	C
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	r



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	D
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	l

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF B:	l



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	E
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	l

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF B:	r



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	F
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	r

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF C:	l



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	G
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	r

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF C:	r



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	H
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	r

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF C:	r

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF G:	l



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	1
ENTER DATA(char):	P
WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF A:	l

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF B:	r

WHERE TO ATTACH? TO THE LEFT OR TO THE RIGHT?(l/r) OF E:	r



---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	2
DISPLAYING AS INORDER!!
D	B	E	P	A	F	C	H	G

---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	3
DISPLAYING AS PREORDER!!
A	B	D	E	P	C	F	G	H

---------------------------------------------------

1] CREATE NODE.	2] INORDER.	 3] PREORDER	4] EXIT.
ENTER YOUR CHOICE:	4


*/
