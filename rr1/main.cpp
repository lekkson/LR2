#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>

// check x
bool inDomain(double x)
{
    return x > 8.0 && x != 10.0; // division and log (log have one of division)
}

// mathematics function
double f(double x)
{
    return std::cos(4.0 / 50.0)
    + 23 * std::numbers::pi
    - 52 * std::numbers::e
      * 8 / ((x + 4) * (x - 10))
    - 5 * std::atan(x + 15)
    + std::log(x - 8) / std::log(4);
}


int main()
{
    std::cout << "Author: Kostiantyn Liashenko, ITK-11\n"
              << "Variant: 171\n"
              << "Calculate a mathematical expression for a real x.\n"
              << "Enter x (domain: x > 8, x != 10; decimal separator: dot): ";

    double x = 0.0;
    std::cin >> x;

    if (std::cin.fail()) {
        std::cout << "\nwrong input\n";
    } else {
        std::cout << "\n***** do calculations ... ";

        const bool defined = inDomain(x);
        double result = 0.0;
        if (defined) {
            result = f(x);
        }

        std::cout << "done\n";
        std::cout << std::fixed << std::setprecision(5)
                  << "for x = " << x << '\n';

        if (defined) {
            std::cout << std::setprecision(9)
                      << "result = " << result << '\n';
        } else {
            std::cout << "result = undefined\n";
        }
    }

    return 0;
}
