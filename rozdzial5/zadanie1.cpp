//ZADANIE 1
#include <iostream>
#include <string.h>

class Wektor
{
private:
    size_t _rozmiar;
    int *_ptab;
public:
    Wektor(size_t n)
        : _rozmiar(n), _ptab(new int[n])
    {
        for (int i = 0; i < _rozmiar; i++)
            _ptab[i] = 0;
    }

    ~Wektor() { delete[] _ptab; }

    size_t size() const { return _rozmiar; }

    int &operator[](unsigned n) { return _ptab[n]; }

    int operator[](unsigned n) const { return _ptab[n]; }

    void operator=(Wektor const &wek)
    {
        if (this == &wek)
            return;

        if (this->_rozmiar != wek._rozmiar)
        {
            delete[] _ptab;
            this->_rozmiar = wek._rozmiar;
            this->_ptab = new int[this->_rozmiar];
        }
        for (size_t i = 0; i < this->_rozmiar; i++)
            this->_ptab[i] = wek._ptab[i];
    }
};

int main()
{
    Wektor wektorek(10);

    for (int i = 0; i < wektorek.size(); i++) {
        std::cout << "Wartosc wektorek[" << i << "] = " << wektorek[i] << std::endl; }

    return 0;
}