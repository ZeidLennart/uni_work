# include <iostream>

class A {
    public: 
    virtual void func() const {
        std::cout << "do something" << std::endl;
    }   
    virtual void funcForceOverride() const {
        std::cout << "This will be overwritten" << std::endl;
    }   
    void hideFunc() const {
        std::cout << "This will not be overwritten, but hidden" << std::endl;
    }
};

class B: public A {
    public: 
    void func() const {
        std::cout << "do something else" << std::endl; 
        // since the naming is the same we are overriding the function, 
        // additionally it is needed that the original function is virtual
    }
    void funcForceOverride() const override { 
        // keyword override is optional if its's not overriding it will not compile
        std::cout << "overwrite something" << std::endl; 
    }
    void funct() const { 
        // in case we are having a typo in the overriding function this will be a new function
        std::cout << "do something completely different" << std::endl; 
    }
    void hideFunc() const {
        std::cout << "The original function was hidden" << std::endl;
    }
};

int main() {
    A a; //create class of type A
    B b; // crate class of type B
    {
        A* bb = new B(); 
        // create a pointer of type Base and assign it to a new object of type Derived

        bb->hideFunc();
        bb->func();

        //difference between hiding and overriding
        // hiding is when a function in the base class is not virtual and a function with the same name is defined in the derived class
        // overriding is when a function in the base class is virtual and a function with the same name is defined in the derived class

        delete bb;
    }
    std::cout << "----------------" << std::endl;
    std::cout << "output overriding functions before and after overwriting" << std::endl;
    std::cout << "----------------" << std::endl;
    a.func();
    b.func();
    b.funct();
    std::cout << "----------------" << std::endl;
    std::cout << "output forced overriding functions before and after overwriting" << std::endl;
    std::cout << "----------------" << std::endl;
    a.funcForceOverride();
    b.funcForceOverride();
    return 0;
}