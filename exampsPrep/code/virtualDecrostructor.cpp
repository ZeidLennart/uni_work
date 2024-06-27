#include <iostream>
// virtual functions
// Eine virtuelle Funktion ist eine Funktion, die in einer Basisklasse als virtuell deklariert wird und in abgeleiteten Klassen überschrieben werden kann.
// Eine virtuelle Funktion wird in der Basisklasse als virtuell deklariert, indem das Schlüsselwort virtual vor der Funktionsdeklaration steht.

class Base {
    public: 
        virtual ~Base() { std::cout << "Base destructor"; } 
};

class Derived : public Base {
    public:
        ~Derived() { std::cout << "Derived destructor"; }
};

int main() {
    Base *b = new Derived();
    delete b;
    return 0;
}
