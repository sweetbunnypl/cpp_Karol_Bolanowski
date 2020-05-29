//ZADANIE 3 LISTA 8
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class PPMimage
{
public:
    struct Kolor
    {
        unsigned char red, green, blue;
    };

    PPMimage(const char nazwa_pliku[]);
    ~PPMimage();
    void zapisz(const char nazwa_pliku[]);
    void zmiekcz();

private:
    PPMimage(PPMimage const &) {} 
    void operator=(PPMimage const &) {}

    int _szerokosc;
    int _wysokosc;
    int _glebia;
    Kolor **_tab;
};

PPMimage::PPMimage(const char nazwa_pliku[])
{
    std::ifstream F(nazwa_pliku, std::ios::binary);
    std::string s;
    F >> s >> std::ws;
    while (F.peek() == '#')
        F.ignore(100000, '\n');
    F >> _szerokosc >> _wysokosc >> _glebia;
    F.ignore(100000, '\n');
    _tab = new Kolor *[_wysokosc];
    for (int i = 0; i < _wysokosc; ++i)
    {
        _tab[i] = new Kolor[_szerokosc];
        char *adres = reinterpret_cast<char *>(_tab[i]);
        F.read(adres, sizeof(Kolor) * _szerokosc);
    }
}

void PPMimage::zmiekcz()
{
    for (int y = 1; y < _wysokosc - 1; ++y)
    {
        for (int x = 0; x < _szerokosc; x++)
        {
            _tab[y][x].red = (_tab[y - 1][x].red + _tab[y + 1][x].red + _tab[y][x - 1].red + _tab[y][x + 1].red) / 4;
            _tab[y][x].green = (_tab[y - 1][x].green + _tab[y + 1][x].green + _tab[y][x - 1].green + _tab[y][x + 1].green) / 4;
            _tab[y][x].blue = (_tab[y - 1][x].blue + _tab[y + 1][x].blue + _tab[y][x - 1].blue + _tab[y][x + 1].blue) / 4;
        }
    }
}

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n"
      << _szerokosc << " " << _wysokosc << "\n"
      << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char *>(_tab[i]), 3 * _szerokosc);
}

PPMimage::~PPMimage()
{
    for (int i = 0; i < _wysokosc; ++i)
    {
        delete[] _tab[i];
    }
    delete[] _tab;
}

int main()
{
    PPMimage image("obrazek.ppm");
    image.zmiekcz();
    image.zapisz("nowy.ppm");
}