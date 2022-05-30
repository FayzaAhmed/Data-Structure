#pragma once
#include <iostream>
using namespace std;
int maxSize = 1000;
template < class T>
class Stack
{
private:
	T* arr;
	int topElement;
	int capacity;
public:
	// Constructors
	Stack();
	Stack(int);
	Stack(T , int );

	// Destructor
	~Stack();

	// Stack Operations
	void push(T);
	T pop();
	T& top();
	int size();
	bool isEmpty();
	bool isFull();

};

// Default Constructor
template<class T>
inline Stack<T>::Stack()
{
	capacity = maxSize;
	arr = new T[maxSize];
	topElement = -1;
}

// Constructor
template<class T>
inline Stack<T>::Stack(int size)
{
	capacity = size;
	arr = new T[size];
	capacity = size;
	topElement = -1;
}

//constructs a stack having "initial_size" elements whose values are "value".
template<class T>
Stack<T>::Stack(T value, int initialSize)
{
	capacity = initialSize;
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = value;
	}
}

// Destructor
template<class T>
Stack<T>::~Stack()
{
	delete[] arr;
}

// Function to add an element to the stack
template<class T>
void Stack<T>::push(T element)
{
	if (isFull())
	{
		cout << "The stack is full.\n";
	}
	else
	{
		topElement++;
		arr[topElement] = element;
	}
}

// Function to delete an element to the stack
template<class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else
	{
		return arr[topElement--];
	}
}

// Function to return the top element of the stack
template <class T>
T& Stack<T>::top()
{
	if (!isEmpty()) {
		return arr[topElement];
	}
	else {
		cout << "The stack is empty.\n";
	}
}

// function to return the size of the stack
template<class T>
int Stack<T>::size()
{
	return top + 1;
}

// function to check if the stack is empty or not
template<class T>
bool Stack<T>::isEmpty()
{
	return topElement == -1;
}

// function to check if the stack is full or not
template<class T>
bool Stack<T>::isFull()
{
	return topElement == capacity - 1;
}
