// stackWithLinkedList.cpp : Defines the entry point for the console application.
//by Carol Mcdaid

#include "stdafx.h"
#include <iostream>



using namespace std;
const int Max = 20;

//Struct that will hold the numbers
struct node
{
	int num;

	node *next;

}*front = NULL, *top = NULL;

//Functions
node* newnode(int num);
void push(node *start);
void pop();
bool isFull();
void showStack();
bool isEmpty();







int main()
{

	int i;
	node *point;
	cout << "Testing the Stack...." << endl;

	showStack();

	//for loop that adds the numbers to the stack
	for (i = 0; i <= Max; i++) 
	{
		point = newnode(i);
		push(point);

	}
	//calls the isFull function to check is the stack is full
	isFull();
	cout << "\n";
	//The stack is displayed
	showStack();

	// The numbers are deleted one by one by the pop functions
	for (i = 0; i < Max +1;i++)
	{
		pop();
	}

	cout << "\n";
	//The stack is displayed once more to show it is empty.
	showStack();
	

	cin.ignore();
	cin.get();
	return 0;

}

// this is were the next number is added the node is moved to the next place along.
node* newnode(int data) {

	front = new node;
	front->num = data;
	front->next = NULL;
	return (front);

}


//pushing the value into the stack
void push(node *start) 
{
	if (top == NULL)
	{	

		top = start;
	}
	else 
	{
		//Adds the num to the stack
		cout << top->num << " has been added" << endl;

		start->next = top;

		top = start;
	}
}


void pop() 
{
		//deletes the num from the stack
		cout << top->num << " has been deleted" << endl;

		front = top;

		top = top->next;

		delete (front);
}

// checks if the stack is full
bool isFull() 
{
	
	if (front->num == Max)
	{
		cout << "stack is full";
		return true;
	}
	else
	{

		return false;
	}
}
// checks if the stack is empty
bool isEmpty() 
{
	
	if (front->num == -1)

		return true;

	else

		return false;
}

// will show what is in the stack one by one.
//If the stack is empty then it will display a message
void showStack()
{
	node *newest;
	newest = top;
	if (top == 0) {

		cout << "Stack is Empty" << endl;
	}
	else
	{		
		while (newest != 0)
		{
			cout << newest->num << " ";

			newest = newest->next;
		
		}
		cout << endl;
	}

}







