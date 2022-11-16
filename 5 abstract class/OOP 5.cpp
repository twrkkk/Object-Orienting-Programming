#include <iostream>
#include "Ellips.h"
#include "Hyperbola.h"

int main()
{
    Ellipse ellipse(1, 2, 3, 4);
    ellipse.print();

    Hyperbola hyperbola(4, 3, 2, 1);
    hyperbola.print();
}
