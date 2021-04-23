#pragma once

#include <iostream>
#include <cassert>

// Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator=
		(const linkedListType<Type>&);
	// Overload the assignment operator.

	void initializeList();
	// Initialize the list to an empty state.
	// Postcondition: first = NULL, last = NULL, count = 0

	bool isEmptyList() const;
	// Postcondition: returns true if list is empty, otherwise 
	// it returns false

	void print() const;
	// Function to output the data contained in each node.
	// Postcondition: none

	int length() const;
	// Function to return the number of nodes in the list.
	// Postcondition: The value of count is returned

	void destroyList();
	// Function to delete all the nodes from the list
	// Postcondition: first = NULL, last = NULL, count = 0

	Type front() const;
	// Function to return the first element of the list.
	// Precondition: The list must exist and must not be empty.
	// Postcondition: If the list is empty, the program terminates;
	// otherwise, the first element will be returned

	Type back() const;
	// Function to return the last element of the list.
	// Precondition: The list must exist and not be empty.
	// Postcondition: If the list is empty, the program terminates; 
	// otherwise, the last element of the list is returned

	virtual bool search(const Type& searchItem) const = 0;
	// Function to determine whether a searchItem is in the list.
	// Postcondition: Returns true if searchItem is in the list,
	// otherwise the value false is returned

	virtual void insertFirst(const Type& newItem) = 0;
	// Function to insert newItem at the beginning of the list.
	// Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list, last points to
	// the last node in the list, and count is incremented by 1.

	virtual void insertLast(const Type& newItem) = 0;
	// Function to insert newItem at the end of the list
	// Postcondition: first points to the new list, newItem is
	// inserted at the end of the list, last points to the
	// last node in the list, and count is incremented by 1.

	virtual void deleteNode(const Type& deleteItem) = 0;
	// Function to delete deleteItem from the list.
	// Postcondition: If found, the node contaning deleteItem is
	// deleted from the list, first points to the first node,
	// last points to the last node of the updated list, and
	// count is decremented by 1.

	linkedListType();
	// Default constructor
	// Initializes the list to an empty state.

	~linkedListType();
	// destructor
	// Deletes all the nodes from the list.
	// Postcondition: The list object is destroyed.
protected:
	nodeType<Type>* first;
	nodeType<Type>* last;
	int count;
};

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator= (const linkedListType<Type>& otherList)
{
	nodeType<Type>* current;
	nodeType<Type>* newNode;

	if (!isEmptyList())
	{
		destroyList();
	}

	if (otherList.isEmptyList())
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first;
		count = otherList.count;
		first = new nodeType<Type>;
		first->info = otherList.first->info;
		first->link = NULL;
		last = first;
		current = current->link;

		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}

	return *this;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList();
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (count == 0 && first == NULL);
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type>* temp;
	temp = linkedListType<Type>::first;
	while (temp != NULL)
	{
		std::cout << temp->info << std::endl;
		temp = temp->link;
	}
}

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type>* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	count = 0;
	last = NULL;
}

template <class Type>
Type linkedListType<Type>::front() const
{
	//assert(first != NULL);
	return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
	//assert(last != NULL);
	return last->info;
}

template <class Type>
linkedListType<Type>::linkedListType()
{
	linkedListType<Type>::first = NULL;
	linkedListType<Type>::last = NULL;
	count = 0;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}