//STOS ZADANIE 2 LISTA 6
#include <cassert>
#include "stos.h"

Stos::~Stos()
{
    while (!this->empty())
        this->pop();
}

Stos::Stos(Stos const &rhs)
    : _pSzczyt(0), _size(0)
{
    Ogniwo *last = _pSzczyt;
    Ogniwo *temp = rhs._pSzczyt;
    Ogniwo *current;
    Ogniwo *szczyt = _pSzczyt;

    while (temp != NULL)
    {
        if (szczyt == NULL)
        {
            szczyt = new Ogniwo(temp->_dane, 0);
            _pSzczyt = szczyt;
            last = szczyt;
        }
        else
        {

            current = new Ogniwo(temp->_dane, 0);
            last->_p_nastepny = current;
            last = current;
        }

        _size++;
        temp = temp->_p_nastepny;
    }
}

Stos &Stos::operator=(Stos const &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (this->_pSzczyt != NULL)
    {

        while (this->_pSzczyt)
        {
            Ogniwo *temp = this->_pSzczyt->_p_nastepny;
            delete this->_pSzczyt;
            this->_size--;
            this->_pSzczyt = temp;
        }
    }
    if (rhs._pSzczyt == NULL)
    {
        this->_pSzczyt = NULL;
    }
    else
    {

        Ogniwo *temp = rhs._pSzczyt;
        Ogniwo *last = this->_pSzczyt;

        while (temp != NULL)
        {
            if (this->_pSzczyt == NULL)
            {
                this->_pSzczyt = new Ogniwo(temp->_dane, 0);
                last = _pSzczyt;
            }
            else
            {

                Ogniwo *current = new Ogniwo(temp->_dane, 0);
                last->_p_nastepny = current;
                last = current;
            }
            this->_size++;
            temp = temp->_p_nastepny;
        }

        return *this;
    }
}