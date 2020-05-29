//ZADANIE 2 LISTA 8
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
    struct NewColor
    {
        unsigned char gray;
    };

    PPMimage(const char nazwa_pliku[]);
    ~PPMimage();
    void zapisz(const char nazwa_pliku[]);
    void convert();

private:
    PPMimage(PPMimage const &) {}       
    void operator=(PPMimage const &) {}

    int _szerokosc;  
    int _wysokosc;
    int _glebia;
    Kolor **_tab;
    NewColor **_new_tab;
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
    _new_tab = new NewColor *[_wysokosc];
    for (int i = 0; i < _wysokosc; ++i)
    {
        _tab[i] = new Kolor[_szerokosc];
        _new_tab[i] = new NewColor[_szerokosc];
        char *adres = reinterpret_cast<char *>(_tab[i]);
        F.read(adres, sizeof(Kolor) * _szerokosc);
    }
}

void PPMimage::convert()
{
    NewColor *p = new NewColor[_szerokosc];
    for (int y = 0; y < _wysokosc; ++y)
    {
        for (int x = 0; x < _szerokosc; x++)
        {
            auto srednia = (_tab[y][x].red + _tab[y][x].green + _tab[y][x].blue) / 3;
            p[x].gray = srednia;
        }
        std::swap(_new_tab[y], p);
    }
    delete[] p;
}

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P5\n"
      << _szerokosc << " " << _wysokosc << "\n"
      << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char *>(_new_tab[i]), _szerokosc);
}

PPMimage::~PPMimage()
{
    for (int i = 0; i < _wysokosc; ++i)
    {
        delete[] _tab[i];
        delete[] _new_tab[i];
    }
    delete[] _tab;
    delete[] _new_tab;
}

int main()
{
    PPMimage image("obrazek.ppm");
    image.convert();
    image.zapisz("nowy.pgm");
}