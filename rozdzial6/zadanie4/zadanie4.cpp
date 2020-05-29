//ZADANIE 4 LISTA 6
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

    stos.reverse();

    std::cout << stos;
}