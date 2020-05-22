//ZADANIE 3
#include "Random.h"

Random::Random(int f1)
    : _fn(f1)
{
    assert(f1 > 0 && f1 < (pow(2, 31) - 1));
}

double Random::operator()()
{
    long long tmp = _fn;
    tmp = (16807 * tmp) % (INT_MAX);
    _fn = tmp;
    return double(tmp) / double(INT_MAX - 1);
}