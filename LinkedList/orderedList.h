#pragma once
#include "linkedListType.h"

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition:  

	void insert(const Type& newItem);
	// Function to insert newItem anywhere in the list
	// Postcondition:

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
bool orderedLinkedList<Type>::search(const Type& searchItem) const
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
void orderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type>* previous = nullptr;
	nodeType<Type>* current;

	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;

	if (linkedListType<Type>::isEmptyList())
	{
		linkedListType<Type>::first = newNode;
		linkedListType<Type>::last = newNode;
		linkedListType<Type>::count++;
	}
	else
	{
		current = linkedListType<Type>::first;
		previous = NULL;

		bool found = false;
		while (current != NULL && !found)
		{
			if (newItem <= current->info)
			{
				found = true;
			}
			else
			{
				previous = current;
				current = current->link;
			}
		}

		if (current == linkedListType<Type>::first)
		{
			newNode->link = linkedListType<Type>::first;
			linkedListType<Type>::first = newNode;
			linkedListType<Type>::count++;
		}
		else if (current == NULL)
		{
			linkedListType<Type>::last->link = newNode;
			linkedListType<Type>::last = newNode;
			linkedListType<Type>::count++;
		}
		else
		{
			previous->link = newNode;
			newNode->link = current;
			linkedListType<Type>::count++;
		}
	}
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
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