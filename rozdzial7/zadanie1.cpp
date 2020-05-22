//ZADANIE 1
#include <iostream>

class Dwa{
public:
    Dwa(){
        std::cout << "Kolejność ";
    }

    ~Dwa(){
        std::cout << "logiczna";
    }
};

class Trzy{
public:
    Trzy(){
        std::cout << "i ";
    }

    ~Trzy(){
        std::cout << "obiektów ";
    }
};

class Cztery{
public:
    Cztery(){
        std::cout << "konstrukcji ";
    }

    ~Cztery(){
        std::cout << "jest ";
    }
};

class Raz: public Dwa{
public:
    Raz(){
        Trzy trzy;
        std::cout << "destrukcji ";
    }

private:
    Cztery _cztery;
};

int main() {
    Raz raz;
}