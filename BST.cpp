#include<iostream>
using namespace std;

struct node                         //node structure
{
    node *left;
    int data;
    node *right;

};
class BST
{
public:

    node *root;

    BST()
    {
        root=NULL;
    }

    void non_rec_insert();              //non- recursive function declaration to insert element int node
    int Search(int );                   //function declaration to search an element int the BST
    void rec_inorder(node *);           //function declaration for recursive function to display tree in the inorder form

};

void BST::non_rec_insert()              //function definition to insert element in the tree
{
    node *temp;
    node *curr;

    curr=new node;

    cout<<"ENTER DATA(int): ";
    cin>>curr->data;

    curr->left=curr->right=NULL;                //initialising left & right to NULL

    if(root==NULL)
    {
        root=curr;
    }
    else
    {
        temp=root;

        while(1)
        {
            if(curr->data < temp->data)             //if data is less than the root, it will be attached to the left of the root node
            {
                if(temp->left==NULL)                //checking whether the left node is NULL
                {
                    temp->left=curr;
                    break;
                }
                else
                {
                    temp=temp->left;               //traversing to the leftmost node
                }
            }
            else
            {
                if(temp->right==NULL)              //if data is greater than the root, it will be attached to the right of the root node
                {                                  //checking whether the right node is NULL
                    temp->right=curr;
                    break;
                }
                else
                {
                    temp=temp->right;               //traversing to the rightmost node
                }
            }
        }
    }
}

int BST::Search(int key)                        //function definition for searching element int the BST
{
    node *temp;

    temp=root;

    while(temp!=NULL)
    {
        if(key==temp->data)                     //checking if the entered value to be searched is equal to the valve in the node
        {
            return 1;
        }
        else if(key<temp->data)                 //checking in the left sub-tree
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;                  //checking the right subtree
        }
    }
}

void BST::rec_inorder(node *root)               //recursive function definition for displaying the thee in the inorder format
{
	if(root!=NULL)
	{
		rec_inorder(root->left);                //call to the same function to go to the leftmost node(recursive calling)

		cout<<root->data;                       //displaying the data
		cout<<"\t";

		rec_inorder(root->right);               //call to the same function to go to the righmost node(recursive calling)
	}
}


int main()                              //main function
{
    BST b1;                             //object 'b1' created of class 'BST'

    int k,choice;

    do                                  //menu driven (asking user the choice of option)
    {

        cout<<"----------------------------------------------------------------------------------------------"<<endl<<endl;

        cout<<"1] INSERT DATA(non recursive).   2] SEARCH ELEMENT. 3] INORDER(recursive)    4] EXIT.    "<<endl;
        cout<<"ENTER YOUR CHOICE: ";

        cin>>choice;
        if(choice==1||choice==2||choice==3||choice==4)          //validation of choice of input value
        {
            switch(choice)
            {
            case 1:
                    b1.non_rec_insert();                         //non-recursive function call for insert
                    break;

            case 2:
                    cout<<"ENTER ELEMENT TO BE SEARCHED(int):    ";     //accepting value to be searched
                    cin>>k;

                    int res;

                    res=b1.Search(k);

                    if(res==1)                                          //checking whether result of search is 1(element present)
                    {
                        cout<<"\n ELEMENT "<<k<<" IS PRESENT!!! "<<endl;
                    }
                    else                                                       //displaying the element saying 'PRESENT' or 'ABSCENT'
                    {
                        cout<<"\n ELEMENT "<<k<<" IS ABSCENT!!!"<<endl;
                    }

                    break;

            case 3:
                    cout<<"DISPLAYING AS INORDER!!"<<endl;
                    b1.rec_inorder(b1.root);                                 //recursive function call for displaying tree in inorder format
                    cout<<"\n\n";
                    break;
            }
        }
        else
        {
            cout<<"\n\n ENTER VALID INPUT!!"<<endl;

        }
    }while(choice!=4);              //choice=4  --> EXIT.



    return 0;
}
