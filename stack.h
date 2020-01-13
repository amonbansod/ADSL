#include<iostream>
using namespace std;

template<class T>			//template (data type may differ)
class stack
{
	int i,top;
	int max_size;
	T s[20];			//declaing array 's'
	
public:

	stack()
	{
		top=-1;				//initialising top and max_size
		max_size=20;
	}
	
	int is_empty()				//checks whether the stack is empty or not
	{
		if(top==-1)
		{	
			return 1;		//if empty it will return 1
		}
	
		else
		{
			return 0;		//if not empty it will return 0
		}
	}
	
	int is_full()				//checks whether the stack is fullor not
	{
		if(top=max_size-1)
		{
			return 1;		//if stack is full it returns 1
		}
	
		else
		{
			return 0;		//if stack is not full it returns 0
		}
	}
	
	void push(T item )			//function definition to push an element onto the stack
	{
		if(!is_full())			//checking whether the stack is full.(if not full add elements)
		{
			top++;
			s[top]=item;		//element added to the location pointed by top
		
		}
		else
		{
			cout<<"STACK OVERFLOW."<<endl;		//if stack is full, it will display the given message
		}
	}
	
	T pop()							//function definition to pop an element from the stack
	{
		if(!is_empty())					//checks whether the stack is empty or not.(if not empty then pop topmost element)
		{
			T item;
			item=s[top];
			top--;					//element poped
			return item;
		}
	
		else
		{
			cout<<"stack UNDERFLOW."<<endl;		//if stack is empty it will display the given message
		}
	}
	
};

	
