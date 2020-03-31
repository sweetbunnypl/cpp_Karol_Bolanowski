#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>

//LICZBA WYRAZÓW CIĄGU FIBONACCIEGO:
const int liczba_wyrazow_ciagu = 48;

//FIBONACCI REKURENCYJNIE:
unsigned long fibo1(int n){

    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibo1(n-1) + fibo1(n-2);
}

//FIBONACCI ZE WZORU:
unsigned long fibo2(int n){

    double sqrt5 = sqrt(5.0);
    double power1 = pow(2/(sqrt5-1), n);
    double power2 = pow(-2/(sqrt5+1), n);
    return round((1/sqrt5)*(power1-power2));
}

//FIBONACCI Z WEKTORA STATYCZNEGO:
unsigned long fibo3(int n){
    static std::vector<unsigned long> fibonacci = {0,1,1};
    if(n < fibonacci.size()){
        return fibonacci[n];
    }
    for(int i = fibonacci.size(); i-1 < n; i++){
        fibonacci.push_back(fibonacci[i-2] + fibonacci[i-1]);
    }
    return fibonacci[n];
}

void wypisywanie_wyrazow_ciagu(std::string str){
    
    for(int i = 1; i <= liczba_wyrazow_ciagu; i++){
        if(str == "fibo1")
            std::cout << "F_" << i << " = " << fibo1(i) << std::endl;
        else if(str == "fibo2")
            std::cout << "F_" << i << " = " << fibo2(i) << std::endl;
        else if(str == "fibo3")
            std::cout << "F_" << i << " = " << fibo3(i) << std::endl;
    }
}

int main()
{
    //FIBO1:
    std::cout << "FUNKCJA REKURENCYJNA (fibo1):" << std::endl;
    clock_t start = clock();
    wypisywanie_wyrazow_ciagu("fibo1");
    clock_t end = clock() - start;
    double time = double(end)/1000000;

    //FIBO2:
    std::cout << "FUNKCJA ZE WZORU (fibo2):" << std::endl;
    clock_t start2 = clock();
    wypisywanie_wyrazow_ciagu("fibo2");
    clock_t end2 = clock() - start2;
    double time2 = double(end2)/1000000;

    //FIBO3:
    std::cout << "FUNKCJA Z WEKTORA STATYCZNEGO (fibo3):" << std::endl;
    clock_t start3 = clock();
    wypisywanie_wyrazow_ciagu("fibo3");
    clock_t end3 = clock() - start3;
    double time3 = double(end3)/1000000;

    //CZAS DZIAŁANIA FUNKCJI:
    std::cout << "Czas działania fibo1: " << time << "s" << std::endl;
    std::cout << "Czas działania fibo2: " << time2 << "s" << std::endl;
    std::cout << "Czas działania fibo3: " << time3 << "s" << std::endl;
}
