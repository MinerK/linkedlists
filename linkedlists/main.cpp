#include "List.h"
#include "List.cpp"
#include <iostream>
#include <string>
using namespace std;

typedef int value_type;
typedef string value_type2;

bool compare1(value_type, value_type);
bool is_even(value_type);

int main()
{
    value_type x;
    cout << "Enter next value, 0 to stop: "; cin >> x;
    
    List<value_type> list1;
    
    while (x!=0)
    {
        list1.add(x);
        cout << "Enter next value, 0 to stop: "; cin >> x;
    }
    
    cout << "Length of the list: " << list1.length() << endl;
    
    list1.Print();
    
    
    int index_to_del;
    cout << "Index of a node to be deleted: "; cin >> index_to_del;
    list1.remove(index_to_del);
    
    int n = list1.length();
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << list1[i] << endl;
    }

    List<value_type>* list2 = list1.sorted(compare1);
	cout << "New list after sorting 1: " << endl;
    list2->Print();

	list2->~List();
	list2 = list1.sorted([](value_type a, value_type b) {return a < b; });

	cout << "New list after sorting 2: " << endl;
	list2->Print();

	list2->~List();
	list2 = list1.filter(is_even);
	cout << "New list after filtering: " << endl;
	list2->Print();

	List<string>* strlist = list1.map(to_string);
	cout << "As a string: " << endl;
	strlist->Print();

    
    
    system("pause");
    return 0;
}

bool compare1(value_type a, value_type b)
{
	return a > b;
}

bool is_even(value_type x)
{
	return x % 2 == 0;
}



