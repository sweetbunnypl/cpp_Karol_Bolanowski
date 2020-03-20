#include <iostream>

using namespace std;

int main()
{
    int n=40;
    long long silnia=1;
    cout << "ZADANIE 1" <<endl;
    for(int i=1; i<=n; i++)
    {
        silnia = silnia*i;
        cout << i<<"! = "<<silnia<< " ";
    }

    return 0;
}
//
