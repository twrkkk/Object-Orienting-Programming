#include <iostream>
#include <fstream>
#include "My_list.h"

using std::cout;
using std::cin;
int main()
{
	std::ifstream file("data.txt");
	std::ifstream file2("data2.txt");
	if (file && file2)
	{
		DLIST<int> list(file);
		DLIST<int> list2(file2);
		DLIST<int> list3 = list.merge(list2);
		DLIST<int> list4 = list.merge_sorted(list2);
		cout << "LIST 1: " << list.to_string();
		cout << "LIST 2: " << list2.to_string();
		cout << "LIST 1 + 2: " << list3.to_string();
		cout << "LIST 1 + 2 SORTED: " << list4.to_string();
	}
}
