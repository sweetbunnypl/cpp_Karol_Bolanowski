//ZADANIE 1 LISTA 8
#include <iostream>
#include <sstream>

void change_to_number(std::istringstream &numbers)
{
    while (true)
    {
        int number;
        numbers >> number;

        if (numbers)
        {
            std::cout << number << "\n";
            continue;
        }
        else if (numbers.eof())
        {
            break;
        }

        numbers.clear();
        numbers.get();
    }
}

int main()
{
    std::istringstream numbers("40 30 20 10");
    change_to_number(numbers);

    return 0;
}