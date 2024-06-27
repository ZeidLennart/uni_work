# include <iostream>

class A {
    private: 
    virtual void func() const = 0; // pure virtual function
};

class B : public A {
    public: 
    void func() const{
        std::cout << "do something else" << std::endl; 
    } // if we would not implement this function the class would be abstract
    // also we could not call the function func() from the main function
};

int main() {
    B b; // create class of type B
    b.func();
    return 0;
}