//ZADANIE 2 LISTA 6
#include <iostream>
#include "stos.h"

int main()
{
    Stos stos;
    for (int i = 1; i <= 50; i++)
    {
        if (i % 3 == i % 5)
            stos.push(i);
    }
    Stos stos2 = stos;

    while (!stos2.empty())
    {
        std::cout << stos2.top() << " " << std::flush;
        stos2.pop();
    }
}