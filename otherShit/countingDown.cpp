#include <iostream>
using namespace std;

string countDown(string input)
{
    char lastChar = input.back();
    input.pop_back();
    if (lastChar == '0')
    {
        return countDown(input) + "1";
    }
    else
    {
        string output = input + '0';
        return output;
    }
}

bool checkIfZ(string input)
{
    bool result = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '1')
        {
            result = false;
            break;
        }
    }
    return result;
}

bool isBinary(string input)
{
    bool result = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (!(input[i] == '1' or input[i] == '0'))
        {
            result = false;
            break;
        }
    }
    return result;
}

int main()
{
    string input = "0";
    cout << "enter a binary number" << endl;
    cin >> input;
    if (!isBinary(input))
    {
        cout << "not binary input" << endl;
    }
    else
    {
        bool isNull = checkIfZ(input);
        while (!isNull)
        {
            input = countDown(input);
            isNull = checkIfZ(input);
            cout << input << endl;
        }
    }
}