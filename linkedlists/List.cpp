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

template<class T>
void List<T>::sort(bool(*compare)(T, T))
{
}

template <typename T>
void List<T>::sort(bool ascending)
{
    for (Node* cursor1 = first; cursor1->next!=first; cursor1=cursor1->next)
    {
        Node* mixptr = cursor1;
        for (Node* cursor2 = cursor1->next; cursor2!=first; cursor2=cursor2->next)
            if (ascending? mixptr->value > cursor2->value : mixptr->value < cursor2->value)
                mixptr = cursor2;
        if (cursor1 != mixptr)
        {
            int tmp = mixptr->value;
            mixptr->value = cursor1 -> value;
            cursor1 -> value = tmp;
        }
    }
}

template <typename T>
List<T>* List<T>::sorted(bool ascending)
{
    int n=length();
    List<T>* newlist = new List<T>(first->value);
    for (int i = 1; i<n; i++)
        newlist->add(operator[](i));
    newlist->sort(ascending);
    return newlist;
}

