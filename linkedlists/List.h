#pragma once
#include <iostream>

class List
{
public:
	List()
	{
		first = nullptr;
	}
	List(int v)
	{
		first = new Node;
		first->next = first;
		first->prev = first;
		first->value = v;
	}

	~List()
	{
		int n = length();
		for (int i = n - 1; i >= 0; i--) {
			remove(0);
		}
		std::cout << "List was deleted." << std::endl;
	}

	void add(int value)
	{
		Node* newnode = new Node;
		newnode->next = newnode;
		newnode->prev = newnode;
		newnode->value = value;
		if (first == nullptr)
		{
			first = newnode;
		}
		else
		{
			Node* last = first->prev;
			newnode->next = first;
			newnode->prev = last;
			last->next = newnode;
			first->prev = newnode;

		}
	}

	int value(int index)
	{
		Node *cursor = first;
		for (int i = 0; i < index; cursor = cursor->next, i++);
		return cursor->value;
	}

	void remove(int index = 0)
	{
		if (first->next == first && first->prev == first)
		{
			delete[] first;
			first = nullptr;
		}
		else
		{
			Node *cursor = first;
			for (int i = 0; i < index; cursor = cursor->next, i++);
			(cursor->prev)->next = cursor->next;
			(cursor->next)->prev = cursor->prev;
			if (cursor == first)
			{
				Node* tmp = first->next;
				delete[] first;
				first = tmp;
			}
			else
			{
				delete[] cursor;
			}
		}
	}

	int length()
	{
		if (first == nullptr)
			return 0;
		Node *cursor = first;
		int i = 1;
		while (cursor->next != first)
		{
			cursor = cursor->next;
			i++;
		}
		return i;
	}

	void Print()
	{
		int n = length();
		for (int i = 0; i < n; i++)
		{
			std::cout << i << " : " << value(i) << std::endl;
		}
	}

private: 
	struct Node
	{
		int value;
		Node* next;
		Node* prev;
	};
	Node* first;
};

