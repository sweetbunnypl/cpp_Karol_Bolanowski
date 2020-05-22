//ZADANIE 3
#include <iostream>
#include "Random.h"

int main()
{
    Random r;
    for (int i = 0; i < 10; i++)
    {
        std::cout << r() << std::endl;
    }
}