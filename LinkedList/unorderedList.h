#pragma once

#include "linkedListType.h"

using namespace std;
// NOTE: There was a problem with the derived class accessing the base class member variables. When we used the scope resolution operator it worked.

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition:  

	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition:  

	void insertLast(const Type& newItem);
	//Function to insert newItem at the end of the list.
	//Postcondition:  

	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition:  

};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
	nodeType<Type>* current;
	current = linkedListType<Type>::first;

	while (current != NULL)
	{
		if (current->info == searchItem)
		{
			return true;
		}
		current = current->link;
	}

	return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;

	if (linkedListType<Type>::isEmptyList())
	{
		linkedListType<Type>::first = newNode;
		newNode->link = NULL;
		newNode->info = newItem;
		linkedListType<Type>::last = newNode;
	}
	else
	{
		newNode->link = linkedListType<Type>::first;
		newNode->info = newItem;
		linkedListType<Type>::first = newNode;
	}
	linkedListType<Type>::count++;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;

	newNode->info = newItem;
	newNode->link = NULL;

	if (linkedListType<Type>::isEmptyList())
	{
		linkedListType<Type>::first = newNode;
		linkedListType<Type>::last = newNode;
	}
	else
	{
		linkedListType<Type>::last->link = newNode;
		linkedListType<Type>::last = newNode;
	}
	linkedListType<Type>::count++;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current;
	nodeType<Type>* previous;

	if (linkedListType<Type>::isEmptyList())
	{
		std::cout << "ERROR: List is empty!\n";
	}
	else
	{
		current = linkedListType<Type>::first;
		previous = NULL;

		// If first node holds data
		if (current->info == deleteItem)
		{
			// Only one node
			if (linkedListType<Type>::first->link == NULL)
			{
				linkedListType<Type>::first = NULL;
				linkedListType<Type>::last = NULL;
				linkedListType<Type>::count--;
				delete current;
			}
			else
			{
				linkedListType<Type>::first = linkedListType<Type>::first->link;
				linkedListType<Type>::count--;
				delete current;
			}
		}
		else
		{
			bool found = false;
			while (current != NULL && !found)
			{
				previous = current;
				current = current->link;

				if (current->info == deleteItem)
				{
					found = true;
					previous->link = current->link;
					if (previous->link == NULL)
					{
						linkedListType<Type>::last = previous;
					}
					delete current;
					linkedListType<Type>::count--;
				}
			}
			if (!found)
			{
				std::cout << "ERROR: Item not found!\n";
			}
		}
	}
}