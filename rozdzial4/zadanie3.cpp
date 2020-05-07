//ZADANIE 3
#include <iostream>
#include <chrono>

int main()
{
    //POWTÓRZENIA PĘTLI:
    double liczba_powtorzen = 8570000;

    //PĘTLA DLA INSTRUKCJI NEW/DELETE:
    auto start = std::chrono::high_resolution_clock::now();
    for(auto n = 1; n <= liczba_powtorzen; ++n)
    {
        int *p = new int[n];
        delete []p;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> czas_petli = finish - start;
    std::cout << "Czas wykonania pętli: " << czas_petli.count() << " s" << std::endl;
    std::cout << "Czas pojedyńczej instrukcji new/delete: " << (czas_petli/liczba_powtorzen).count() << " s" << std::endl;

    //PĘTLA DLA OPERACJI DODAWANIA:
    int num = 1;
    start = std::chrono::high_resolution_clock::now();
    for(auto n = 1; n <= liczba_powtorzen; ++n)
    {
        num++;
    }
    finish = std::chrono::high_resolution_clock::now();
    czas_petli = finish - start;
    std::cout << "Czas wykonania pętli z taką samą ilością powtórzeń co poprzednia pętla: " << czas_petli.count() << " s" << std::endl;
    std::cout << "Czas pojedynczej operacji dodawania: " << (czas_petli / liczba_powtorzen).count() << " s" << std::endl;

    return 0;
}
