#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

int main() {
    std::string fileName;
    std::cout << "Please enter the file name or type QUIT to exit:" << "\n";
    std::cin >> fileName;

    while (true) {
        if (fileName == "QUIT") {
            return 0;
        }

        std::ifstream inputFile(fileName);
        if (inputFile.is_open()) {
            int count = 0;
            double sum = 0.0;
            double lowest = std::numeric_limits<double>::max();
            double highest = std::numeric_limits<double>::min();
            double number;
            while (inputFile >> number) {
                count++;
                sum += number;
                if (number < lowest) {
                    lowest = number;
                }
                if (number > highest) {
                    highest = number;
                }
            }
            inputFile.close();
            double average = sum / count;
            std::cout << std::fixed << std::setprecision(3);
            std::cout << "Count: " << count << "\n";
            std::cout << "Lowest: " << lowest << "\n";
            std::cout << "Highest: " << highest << "\n";
            std::cout << "Total: " << sum << "\n";
            std::cout << "Average: " << average << "\n";
            break;

        } else {
            std::cerr << "File: " << fileName << " does not exist." << "\n";
            std::cout << "Please enter the file name again or type QUIT to exit:" << "\n";
            std::cin >> fileName;
        }
    }

    return 0;
}
