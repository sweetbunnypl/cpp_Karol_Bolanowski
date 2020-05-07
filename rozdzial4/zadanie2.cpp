//ZADANIE 2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //PRZYKŁAD A:
    double tablica_a[100];
    double *wskaznik_a = tablica_a;

    //PRZYKŁAD B:
    char *tablica_b[5][5];

    //PRZYKŁAD C:
    void funkcja_c(char *tablica_c[], size_t size_c);

    //PRZYKŁAD D:
    std::vector<void*> wektor_d;

    //PRZYKLAD E:
    std::vector<double> wektor_e[4];

    //PRZYKŁAD F:
    double *funkcja_f(double tablica_f[], int calkowita_f);

    //PRZYKŁAD G:
    void funkcja_g(int *&calkowita_g);
    return 0;
}
