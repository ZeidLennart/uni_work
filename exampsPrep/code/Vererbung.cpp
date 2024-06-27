# include <iostream>

// access specifiers and und Vererbungsformen
// Die standart Vererbung ist Privat

class A {
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

class B : public A {
    // a is public
    // b is protected
    // c is not accessible from B
};

class C : protected A {
    // a is protected
    // b is protected
    // c is not accessible from C
};

class D : private A {
    // a is private
    // b is private
    // c is not accessible from D
};