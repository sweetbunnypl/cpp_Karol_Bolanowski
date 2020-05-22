//ZADANIE 2
#include <iostream>
#include <cmath>

class Complex
{
    friend std::ostream &operator<<(std::ostream &result, Complex const &c)
    {
        if (c.im < 0)
            result << c.re << c.im << "i" << std::endl;
        else
            result << c.re << "+" << c.im << "i" << std::endl;
        return result;
    }

    friend std::istream &operator>>(std::istream &result, Complex &c)
    {
        std::cout << "Podaj część rzeczywistą: ";
        result >> c.re;
        std::cout << "Podaj część urojoną: ";
        result >> c.im;
        return result;
    }

public:
    double re, im;

    Complex(double r = 0, double i = 0)
    {
        re = r;
        im = i;
    }

    Complex operator+(Complex const &c) const
    {
        Complex result;
        result.re = re + c.re;
        result.im = im + c.im;
        return result;
    }

    Complex operator-(Complex const &c) const
    {
        Complex result;
        result.re = re - c.re;
        result.im = im - c.im;
        return result;
    }

    Complex operator*(Complex const &c) const
    {
        Complex result;
        result.re = re * c.re - im * c.im;
        result.im = re * c.im + im * c.re;
        return result;
    }

    Complex operator/(Complex const &c) const
    {
        Complex result;
        double num = pow(c.re, 2) + pow(c.im, 2);
        result.re = (re * c.re + im * c.im) / num;
        result.im = (re * (-c.im) + im * c.re) / num;
        return result;
    }

    ~Complex() = default;
};

int main()
{
    Complex complex_1;
    Complex complex_2;

    std::cout << "PIERWSZA LICZBA ZESPOLONA" << std::endl;
    std::cin >> complex_1;
    std::cout << "Pierwsza liczba zespolona: " << complex_1 << std::endl;

    std::cout << "DRUGA LICZBA ZESPOLONA" << std::endl;
    std::cin >> complex_2;
    std::cout << "Druga liczba zespolona: " << complex_2 << std::endl;

    std::cout << "DODAWANIE:" << complex_1 + complex_2 << std::endl;
    std::cout << "ODEJMOWANIE:" << complex_1 - complex_2 << std::endl;
    std::cout << "MNOŻENIE:" << complex_1 * complex_2 << std::endl;
    std::cout << "DZIELENIE:" << complex_1 / complex_2 << std::endl;

    return 0;
}