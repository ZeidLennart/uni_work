#include <iostream>
using namespace std;

int isDivisible(int a)
{
    float aa = a % 5;
    float bb = a % 11;
    cout << aa << '-' << bb;
    if (floorf(aa) == aa)
    {
        if (floorf(bb) == bb)
        {
            return 2;
        }
        return 0;
    }
    else if (floorf(bb) == bb)
    {
        return 1;
    }
    return 3;
}

int main()
{
    isDivisible(20);
}