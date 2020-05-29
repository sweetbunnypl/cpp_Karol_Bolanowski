//STOS ZADANIE 3 LISTA 6
#include <cassert>
#include "stos.h"
#include <iostream>

Stos::~Stos()
{
    while (!this->empty())
        this->pop();
}

std::ostream &operator<<(std::ostream &result, Stos const &c)
{
    result << "(";
    if (!c.empty())
        result << c.top();
    Ogniwo *last = c._pSzczyt->_p_nastepny;
    while (last != NULL)
    {
        result << ", ";
        result << last->_dane;
        last = last->_p_nastepny;
    }
    result << ")";
    return result;
}