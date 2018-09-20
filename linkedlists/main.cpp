#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter next value, 0 to stop: "; cin >> x;
    
    List list1;
    
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
    bool asc;
    cout<<"Ascending sort? 0=false: ";
    cin>>asc;
    List list2 = list1.sorted(asc);
    list2.Print();

    
    
    system("pause");
    return 0;
}
