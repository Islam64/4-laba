#include <iostream>
#include "twolist.h"

using namespace std;


int main()
{

	setlocale(LC_ALL, "rus");
     twoList<int> a;
	cout << endl << "pushfront " << endl ;
	a.pushFront(5);
	a.pushFront(7);
	a.pushFront(101);
    for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
    cout << endl << "pushback " << endl ;
	a.pushBack(4);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
    cout << endl << "popback " << endl ;
    a.popBack();
    for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
	cout << endl << "popfront " << endl ;
    a.popFront();
    for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
	cout << endl << "������" << endl ;
    cout << a.size() << endl;
    cout << endl << "�������� ������" << endl ;
    if (a.empty()== 0){
    cout << "�� ������" << endl;
    }
    else
    cout << " ������" << endl;




	return 0;
}


