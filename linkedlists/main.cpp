#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

void add(Node*& first, int value);
int value(Node *first, int index);
void remove(Node *&first, int index = 0);
int length(Node* first);

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

	int n = length(List1);
	cout << "Length of the list: " << length(List1) << endl;



	return 0;
}

void add(Node *& first, int value)
{
	Node* newnode = new Node;
	newnode->next = nullptr;
	newnode->value = value;
	if (first==nullptr)
	{
		first = newnode;
	}
	else
	{
		Node* last = first;
		while (last->next!=nullptr)
		{
			last = last->next;
		}
		last->next = newnode;
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
	Node *cursor = first;
	for (int i = 0; i < index; cursor = cursor->next, i++);
	delete[] cursor;
}

int length(Node * first)
{
	Node *cursor = first;
	int i = 0;
	while (cursor != nullptr && cursor->next != nullptr)
	{
		cursor = cursor->next;
		i++;
	}
	return i;
}
