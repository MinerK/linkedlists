#include "List.h"
#include <iostream>

template <typename T>
List<T>::List()
{
    first = nullptr;
}

template <typename T>
List<T>::List(T v)
{
    first = new Node;
    first->next = first;
    first->prev = first;
    first->value = v;
}

template <typename T>
List<T>::~List()
{
    int n = length();
    for (int i = n - 1; i >= 0; i--) {
        remove(0);
    }
    std::cout << "List was deleted." << std::endl;
}

template <typename T>
void List<T>::add(T value)
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

template <typename T>
T& List<T>::operator[] (int index)
{
    Node *cursor = first;
    for (int i = 0; i < index; cursor = cursor->next, i++);
    return cursor->value;
}

template <typename T>
void List<T>::remove(int index)
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

template <typename T>
int List<T>::length()
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

template <typename T>
void List<T>::Print()
{
    int n = length();
    for (int i = 0; i < n; i++)
    {
        std::cout << i << " : " << operator[] (i) << std::endl;
    }
}

template <typename T>
void List<T>::sort(bool(*compare)(T, T))
{
    for (Node* cursor1 = first; cursor1->next!=first; cursor1=cursor1->next)
    {
        Node* mixptr = cursor1;
        for (Node* cursor2 = cursor1->next; cursor2!=first; cursor2=cursor2->next)
            if (compare(mixptr->value,cursor2->value))
                mixptr = cursor2;
        if (cursor1 != mixptr)
        {
            T tmp = mixptr->value;
            mixptr->value = cursor1 -> value;
            cursor1 -> value = tmp;
        }
    }
}

template <typename T>
List<T>* List<T>::copy()
{
	List<T>* newlist = new List<T>(first->value);
	for (Node* cursor = first->next; cursor!=first; cursor=cursor->next)
		newlist->add(cursor->value);
	return newlist;
}

template <typename T>
List<T>* List<T>::sorted(bool(*compare)(T, T))
{
    List<T>* newlist = copy();
    newlist->sort(compare);
    return newlist;
}

template<class T>
List<T>* List<T>::filter(bool(*include)(T))
{
	List<T>* newlist = new List<T>;
	Node* cursor = first; 
	do
	{
		if (include(cursor->value))
			newlist->add(cursor->value);
		cursor = cursor->next;
	}
	while (cursor != first);
	return newlist;
}
//
//template <typename T>
//template <typename U>
//List<U> *map(U(*transform)(T))
//{
//	List<U>* newlist = copy();
//	return newlist;
//}
//
//template <typename T>
//template <typename U>
//U reduce(U initial, U(*next_result)(U, T))
//{
//	U result;
//	return result;
//}