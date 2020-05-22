//ZADANIE 4
#include <iostream>

int main()
{
    double tab[10];
    double x;
    std::cout << &x << "\t" << &tab[-1] <<"\n";
}
/*
KOMENTARZ:
Zjawisko również występuje na moim komputerze.
Referencja niewłaściwych podanej tablicy lub pustej zmiennej powoduje wyświetlenie tego samego adresu. 
*/