//ZADANIE 5 DRUGA METODA
#include <iostream>

class Samochod
{
public:
    Samochod (int n)
    : _kola(n)        //<---- KOMENTARZ ODNOSNIE TEJ LINII
    {
        _sruby = 4 * _kola;
        std::cout << "Samochod z " << _kola << " kolami i "
            << _sruby << " srubami\n";
    }

private:
    int _sruby;
    int _kola;
};

int main()
{
    Samochod s4(4);
    Samochod s12(12);
}

/*
KOMENTARZ:
Przez to, że _kola nie zostały jeszcze zainicjowane, możemy później zainicjować _sruby i przypisać do nich już zainicjowaną wtedy wartość.
*/