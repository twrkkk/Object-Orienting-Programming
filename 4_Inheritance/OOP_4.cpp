
#include <iostream>
#include "Time.h"

using std::cin;
using std::cout;

int main()
{
    Time t1(18, 41, 32), t2(18, 0, 0);
    cout << t1.compare(t2) << '\n';
    cout << t1.calculateDifference(t2);
}

