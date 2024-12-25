#include <iostream>
#include <cmath>
#include <algorithm>

double calculateR(float x, float y) {
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
    std::cin >> x >> y;

    double R = calculateR(x, y);
    double S = calculateS(x, y);
    double C = calculateC(R, S);

    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;
    std::cout << "C = " << C << std::endl;

    system("pause");

    return 0;
}
