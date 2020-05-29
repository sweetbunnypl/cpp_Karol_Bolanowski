//STOS ZADANIE 4 LISTA 6
#include <cassert>
#include "stos.h"
#include <iostream>

Stos::~Stos()
{
    while (!this->empty())
        this->pop();
}

void Stos::reverse()
{
    assert(!empty());
    Ogniwo *iter = this->_pSzczyt;
    Ogniwo *last = NULL;
    Ogniwo *previous = NULL;
    Ogniwo *next = NULL;
    while (iter != NULL)
    {
        next = iter->_p_nastepny;
        iter->_p_nastepny = previous;
        last = iter;
        previous = last;
        iter = next;
    }
    this->_pSzczyt = last;
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