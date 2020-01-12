#include<iostream>
using namespace std;

template<class T>
class stack
{
	int i,top;
	int max_size;
	T s[20];
	
public:

	stack()
	{
		top=-1;
		max_size=20;
	}
	
	int is_empty()
	{
		if(top==-1)
		{	
			return 1;
		}
	
		else
		{
			return 0;
		}
	}
	
	int is_full()
	{
		if(top=max_size-1)
		{
			return 1;
		}
	
		else
		{
			return 0;
		}
	}
	
	void push(T item )
	{
		if(!is_full())
		{
			top++;
			s[top]=item;
		
		}
		else
		{
			cout<<"STACK OVERFLOW."<<endl;
		}
	}
	
	T pop()
	{
		if(!is_empty())
		{
			T item;
			item=s[top];
			top--;
			return item;
		}
	
		else
		{
			cout<<"stack UNDERFLOW."<<endl;
		}
	}
	
};
/*
int stack::is_empty()


int stack::is_full()


int stack::push(int item)


int stack::pop()

*/

	
