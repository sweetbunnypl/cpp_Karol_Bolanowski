//ZADANIE 5 PIERWSZA METODA
#include <iostream>

class Samochod
{
public:
    Samochod (int n)
    : _kola (n) , _sruby (4*n)    //<---- KOMENTARZ ODNOSNIE TEJ LINII
    {
        std::cout << "Samochod z " << _kola <<  " kolami i "
            << _sruby << " srubami\n";
    }
private:
    int _sruby;
    int _kola;

};

int main()
{
    Samochod s4 (4);
    Samochod s12 (12);
}

/*
KOMENTARZ:
Przez to, że _kola nie zostały jeszcze zainicjowane, możemy jako argument _sruby użyć n.
*/