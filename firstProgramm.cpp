#include <iostream>
using namespace std;

int test()
{
    return 2 * 2 * 2 * 2 * 2 * 2;
}

int main()
{
    if (true)
    {
        cout << test();
    }
    else if (false)
    {
    }
    else
    {
    }

    int x = 12;
    while (x >= 0)
    {
        x -= 1;
    }
}