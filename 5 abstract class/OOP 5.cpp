#include <iostream>
#include "Ellips.h"
#include "Hyperbola.h"

int main()
{
    Function* e = new Ellipse(2, 4);
    std::cout << e->print(e->calculate(1)) << '\n';

    Function* h = new Hyperbola(5, 6);
    std::cout << h->print(h->calculate(6)) << '\n';
}
