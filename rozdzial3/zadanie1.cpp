#include <iostream>
#include <vector>
#include <climits>

int najmniejszy_element_wektora(std::vector<int> najmniejszy){

    //JEŚLI WEKTOR PUSTY:
    if(najmniejszy.empty()){
        std::cout << "Wektor pusty, minimalna wartość inta to: ";
        return INT_MIN;
    }

    //JEŚLI WEKTOR ZAWIERA WARTOŚCI:
    int minimalna_wartosc = najmniejszy[0];
    for(int i = 1; i < 5; i++){
        if(minimalna_wartosc > najmniejszy[i]) 
            minimalna_wartosc = najmniejszy[i];
    }
    std::cout << "Długość wektora: " << najmniejszy.size() << std::endl;
    std::cout << "Najmniejszy element wektora: ";
    return minimalna_wartosc;
}


int main()
{
    //WEKTOR 1
    std::cout << "WEKTOR 1:" <<std::endl;
    std::vector<int> wektor_1 = {9, 8, 6, 7, 4};
    std::cout << najmniejszy_element_wektora(wektor_1) << std::endl;
    
    //WEKTOR 2
    std::cout << "WEKTOR 2 (pusty):" <<std::endl;
    std::vector<int> wektor_2;
    std::cout << najmniejszy_element_wektora(wektor_2) << std::endl;
    return 0;
}
