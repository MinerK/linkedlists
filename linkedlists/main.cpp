#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* prev;
};

void add(Node*& first, int value);
int value(Node *first, int index);
void remove(Node *&first, int index = 0);
int length(Node* first);
void PrintList(Node * first);

int main()
{
	int x;
	cout << "Enter next value, 0 to stop: "; cin >> x;

	Node *List1 = nullptr;

	while (x!=0)
	{
		add(List1, x);
		cout << "Enter next value, 0 to stop: "; cin >> x;
	}

	cout << "Length of the list: " << length(List1) << endl;

	PrintList(List1);

	int index_to_del;
	cout << "Index of a node to be deleted: "; cin >> index_to_del;
	remove(List1, index_to_del);

	PrintList(List1);

	system("pause");
	return 0;
}

void add(Node *& first, int value)
{
	Node* newnode = new Node;
	newnode->next = nullptr;
	newnode->prev = nullptr;
	newnode->value = value;
	if (first==nullptr)
	{
		first = newnode;
	}
	else
	{
		if (first->next == nullptr)
		{
			newnode->next = first;
			newnode->prev = first;
			first->next = newnode;
			first->prev = newnode;
			
		}
		else
		{
			Node* last = first;
			while (last->next != first)
			{
				last = last->next;
			}
			newnode->next = first;
			newnode->prev = last;
			last->next = newnode;
			first->prev = newnode;
		}
	}
}

int value(Node * first, int index)
{
	Node *cursor = first;
	for (int i = 0; i < index ; cursor=cursor->next, i++);
	return cursor->value;
}

void remove(Node *& first, int index)
{
	if(index == 0)
	{
		if (first->next != nullptr && first->prev != nullptr)
		{
			(first->prev)->next = first->next;
			(first->next)->prev = first->prev;
			Node* tmp = first->next;
			delete[] first;
			first = tmp;
		}
	}
	else
	{
		Node *cursor = first;
		for (int i = 0; i < index; cursor = cursor->next, i++);
		(cursor->prev)->next = cursor->next;
		(cursor->next)->prev = cursor->prev;
		delete[] cursor;
	}
}

int length(Node * first)
{
	Node *cursor = first;
	int i = 0;
	while (cursor != nullptr && cursor->next != first)
	{
		cursor = cursor->next;
		i++;
	}
	return i;
}

void PrintList(Node * first)
{
	int n = length(first);
	for (int i = 0; i <= n; i++)
	{
		cout<< i << " : "<< value(first, i)<< endl;
	}
}
