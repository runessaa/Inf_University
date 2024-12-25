#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <stdexcept>

double calculateR(float x, float y) {
    if (y == 0) {
        throw std::invalid_argument("Division by zero in calculateR");
    }
    return sin(x / y);
}

double calculateS(float x, float y) {
    return exp(-3 * x) + cbrt(y);
}

double calculateC(double R, double S) {
    return std::max(R, S);
}

int main() {
    float x, y;

    std::cout << "Enter x and y values: ";
    while (!(std::cin >> x >> y) || y == 0) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter valid x and y values (y cannot be zero): ";
    }

    try {
        double R = calculateR(x, y);
        double S = calculateS(x, y);
        double C = calculateC(R, S);

        std::cout << "R = " << R << std::endl;
        std::cout << "S = " << S << std::endl;
        std::cout << "C = " << C << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    system("pause");

    return 0;
}
