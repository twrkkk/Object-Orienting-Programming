
/*
 реализовать класс Triangle с полями-координатами вершин
 для представления координат вершин используйте класс Point
*/


#include "Triangle.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Triangle User_Input()
{
	int choice = 0;
	cout << "Выберите способ инициализации треугольника\n" <<		
		"1.По координатам 3 точек\n" <<
		"2.Выход\n";

	Point p1, p2, p3;
	do
	{
		bool error = false;
		do
		{
			cin >> choice;
			if (choice < 1 || choice > 2)
				error = true;
		} while (error);

		if (choice == 2) exit(0);

		cout << "Введите значения\n";
		cin >> p1 >> p2 >> p3;

		return Triangle(p1, p2, p3);

	} while (choice != 2);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Triangle triangle = User_Input();
	double h1, h2, h3;
	triangle.CalcHeights(h1, h2, h3);
	std::cout << triangle.toString() << triangle.TriType() << "Площадь: " << triangle.CalcArea() << "\n" << "Периметр: " << triangle.CalcPerim();
}