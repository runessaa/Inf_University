#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    float x, y;

    std::cout << "Enter x and y values: ";
    std::cin >> x >> y;

    double R = sin(x / y);
    double S = exp(-3 * x) + cbrt(y);

    double C = std::max(R, S);

    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;
    std::cout << "C = " << C << std::endl;

    system("pause");

    return 0;
}