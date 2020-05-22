//ZADANIE 3
#include <ctime>
#include <cassert>
#include <math.h>
#include <climits>

class Random
{
    int _fn;

public:
    Random(int f1 = time(0));
    double operator()();
};
