#include <iostream>
#include <fstream>
#include "My_list.h"

using std::cout;
using std::cin;
int main()
{
	std::ifstream file("data.txt");
	if (file)
	{
		DLIST<int> list(file);
		cout << list.to_string() << '\n';
		
		//DLIST<int> list(file);
		//cout<<list;
		//NODE<double> a(5.00001);
		/*ptrNODE<double> b = new NODE<double>(7);
		cout << b->info;*/
	}
}
