//#include <iostream>
#include <fstream>
using namespace std;
/*
class OBC
{
public:
    OBC() : m_fuel(0.0)
    {
    }

private:
    double m_fuel;
};

class OBCA : public OBC
{
public:
    OBCA() : OBC(), m_miles(0.0)
    {
    }
    void addMiles(double fuel)
    {
        m_miles += fuel;
    }

    double getMiles()
    {
        return m_miles;
    }

private:
    double m_miles;
};

*/
int main() {
    ofstream outFile;
    outFile.open("example.txt");

    if (!outFile.is_open()) {
        cout << "Failed to open the file." << std::endl;
        return 1;
    }

    // Write data to the file

    outFile.close();  // Close the file
    return 0;
}



// reducing risk of Inheritance => variables private => minimize calls to baseclass
// in a struct Inheritance will be public by default in a class one has to define the Inheritance as public otherwise it will be public
// OBCA { }.getMiles() will return a temporary variable using the default values