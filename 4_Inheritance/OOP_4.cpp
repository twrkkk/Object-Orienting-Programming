
#include <iostream>
#include "Time.h"

#include "Triad.h"

using std::cin;
using std::cout;

int main()
{
    /*
    cout << t1.compare(t2) << '\n';
    cout << t1.calculateDifference(t2);*/

    Time t1(18, 41, 32), t2(18, 0, 0);
    cout << t1 << t2;
    cout << "t1 > t2: " << (t1 > t2) << " t1 < t2: " << (t1 < t2) << " t1 == t2: " << (t1 == t2) << '\n';
    cout << "Difference: " << t1.calculateDifference(t2);
}

