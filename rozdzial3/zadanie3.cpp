#include <iostream>
#include <vector>

//ZMIANA OPERATORA *:
double operator* (std::vector<double> v, std::vector<double> w){

    double wynik;
    for(int i = 0; i < v.size() and i < w.size(); i++)
        wynik += v[i] * w[i];
    return wynik;
}

//ZMIANA SPOSOBU POKAZANIA WEKTORA:
std::ostream & operator<< (std::ostream & ost, std::vector<double> vector){

    ost << "(";
    for(int i = 0; i < vector.size(); i++){
        ost << vector[i];
        if(i+1 != vector.size()) 
            ost << ",";
    }
    ost << ")";
    return ost;
}

int main()
{
    //WEKTOR 1:
    std::vector<double> v = {0, 6, 9, 1};
    std::cout << "v = " << v << std::endl;

    //WEKTOR 2:
    std::vector<double> w = {10, 4, 12, 3};
    std::cout << "w = " << w << std::endl;

    //ILOCZYN SKALARNY:
    std::cout << "ILOCZYN SKALARNY:" << std::endl;
    std::cout << "v * w = " << v * w << std::endl;

    return 0;
}