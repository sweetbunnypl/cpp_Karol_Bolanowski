#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int i = 30;
    double t0 = 1.0/sqrt(3.0);
    double t = t0;
    double pi;

    cout << "ZADANIE 3" <<endl;
    cout << "A:" <<endl;
    for(int j=0; j<=i; j++)
    {
        t = (sqrt(pow(t,2)+1)-1)/t;
        if(j==0) t = t0;
        pi = 6*pow(2,j)*t;
        cout <<"dla i = "<<j<<", wartość wynosi: "<<pi<<endl;
    }
    cout << "różnica miedzy wynikami = " << pi - M_PI << endl;
    
    cout << "B:" <<endl;
    for(int j=0; j<=i; j++)
    {
        t = t/(sqrt(pow(t,2)+1)+1);
        if(j==0) t = t0;
        pi = 6*pow(2,j)*t;
        cout <<"dla i = "<<j<<", wartość wynosi: "<<pi<<endl;
    }
    cout <<"różnica miedzy wynikami = "<<pi-M_PI<<endl;

    return 0;
}
