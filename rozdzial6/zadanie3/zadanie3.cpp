//ZADANIE 3 LISTA 6
#include <iostream>
#include "stos.h"

int main()
{
    Stos stos;
    stos.push(10);
    stos.push(20);
    stos.push(30);
    stos.push(40);

    std::cout << stos;
}