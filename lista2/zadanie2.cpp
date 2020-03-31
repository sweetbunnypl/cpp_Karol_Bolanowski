#include <iostream>
#include <vector>

void zerowanie(std::vector<double> wyzerowany){

    //ZEROWANIE WEKTORA:
    std::cout << "Wyzerowane elementy wektora: " << std::endl;
    std::cout << "wyzerowany = (";
    for(int i = 0; i < wyzerowany.size(); i++){
        wyzerowany[i] = 0;
        std::cout << wyzerowany[i];
        if(i + 1 != wyzerowany.size()) 
            std::cout << ", ";
    }
    std::cout << ")" <<std::endl;
}

int main()
{
    //WEKTOR 1:
    std::cout << "WEKTOR 1:" <<std::endl;
    std::vector<double> wyzerowany_1 = {5, 6, 11, 7};
    zerowanie(wyzerowany_1);

    //WEKTOR 2:
    std::cout << "WEKTOR 2:" <<std::endl;
    std::vector<double> wyzerowany_2 = {1, 14, 8, 11, 19, 10, 9};
    zerowanie(wyzerowany_2);
    return 0;
}