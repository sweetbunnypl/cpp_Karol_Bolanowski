//STOS.H ZADANIE 2 LISTA 6
#if !defined STOS_H__
#define STOS_H__

#include <cassert>
#include <cstddef>

struct Ogniwo
{
    Ogniwo(int n, Ogniwo *p)
        : _dane(n), _p_nastepny(p)
    {
    }

    int _dane;
    Ogniwo *_p_nastepny;
};

class Stos
{
public:
    Stos();
    Stos(Stos const &);
    ~Stos();

    void push(int i);
    void pop();
    int top() const;
    int &top();
    bool empty() const;
    size_t size() const;
    Stos &operator=(Stos const &);
private:
    Ogniwo *_pSzczyt;
    size_t _size;
};

inline Stos::Stos()
    : _pSzczyt(0), _size(0)
{
}

inline void Stos::push(int n)
{
    _pSzczyt = new Ogniwo(n, _pSzczyt);
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    Ogniwo *temp = _pSzczyt;
    _pSzczyt = _pSzczyt->_p_nastepny;
    delete temp;
    _size--;
}

inline int Stos::top() const
{
    assert(!empty());
    return _pSzczyt->_dane;
}

inline int &Stos::top()
{
    assert(!empty());
    return _pSzczyt->_dane;
}

inline bool Stos::empty() const { return _pSzczyt == 0; }

inline size_t Stos::size() const { return _size; }

#endif