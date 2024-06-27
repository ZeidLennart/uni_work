#include <fstream>

int main() {
    std::ofstream outFile;
    outFile.open("example.txt");

    if (!outFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    // Write data to the file

    outFile.close();  // Close the file
    return 0;
}
