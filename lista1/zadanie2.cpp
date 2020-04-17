#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 1000000;
    double j = 1;
    double suma = 0;

    //PUNKT A
    double factor = 1;
    for(j; j<=n; j++)
    {
        suma += factor/(2*j-1);
        factor = -factor;
    }
    suma *= 4;
    cout <<"ZADANIE 2"<<endl;
    cout <<"A:"<<endl;
    cout <<"suma a wynosi = "<<suma<<endl;
    cout <<"różnica miedzy wynikami = "<<suma-M_PI<<endl;

    //PUNKT B
    j = 1;
    suma = 1;

    for(j; j<=n; j++)
    {
        suma *= (4*j*j)/(4*j*j-1);
    }
    suma *= 2;
    cout <<"B:"<<endl;
    cout <<"suma a wynosi = "<<suma<<endl;
    cout <<"różnica miedzy wynikami = "<<suma-M_PI<<endl;

    //PUNKT C
    j = 1;
    suma = 0;

    for(j; j<=n; j++)
    {
        suma += 1/((2*j-1)*(2*j-1));
    }
    suma *= 8;
    suma = sqrt(suma);

    cout <<"C:"<<endl;
    cout <<"suma a wynosi = "<<suma<<endl;
    cout <<"różnica miedzy wynikami = "<<suma-M_PI<<endl;

    return 0;
}
