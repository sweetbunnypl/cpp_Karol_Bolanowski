//STOS.H ZADANIE 1 LISTA 6
#ifndef ROZDZIAL6_STOS_H
#define ROZDZIAL6_STOS_H

#include <cstddef>
#include <cassert>

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
    enum
    {
        initial_capacity = 1
    };
    void _grow();
    void _shrink();

    size_t _capacity;
    size_t _size;
    int *_tab;
};

inline Stos::Stos()
    : _capacity(initial_capacity),
      _size(0),
      _tab(new int[initial_capacity])
{
    assert(initial_capacity > 0);
}

inline Stos::~Stos() { delete[] _tab; }

inline void Stos::push(int n)
{
    if (_size == _capacity)
        _grow();

    _tab[_size] = n;
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    _size--;

    if (_size * 4 <= _capacity)
        _shrink();
}

inline int Stos::top() const
{
    assert(!empty());
    return _tab[_size - 1];
}

inline int &Stos::top()
{
    assert(!empty());
    return _tab[_size - 1];
}

inline bool Stos::empty() const { return _size == 0; }

inline size_t Stos::size() const { return _size; }

#endif