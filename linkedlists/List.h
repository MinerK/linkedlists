
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
    //void sort (bool ascending);
    //List<T>* sorted(bool ascending);

	void sort(bool(*compare)(T, T));
	List<T>* copy();
	List<T>* sorted(bool(*compare)(T, T));

	template <typename U>
	List<U>* map(U(*transform)(T));

	List<T> *filter(bool(*include)(T));

	//template <typename U>
	//U reduce(U initial, U(*next_result)(U, T));
    
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
