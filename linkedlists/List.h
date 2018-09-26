
#ifndef List_h
#define List_h

template <class T>
class List
{
public:
    List();
    List(T v);
    ~List();
    void add(T value);
    T& operator[] (int index);
    void remove(int);
    int length();
    void Print();
    void sort (bool ascending);
    List<T>* sorted (bool ascending);
    
private:
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
    };
    Node* first;
};

#endif
