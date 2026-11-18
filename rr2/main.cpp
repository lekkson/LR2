
#include <cmath>
#include <format>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

const double a = -0.2;
const double b = 0.2;

// Calculates the series using recurrence.
double s(const double x, const double eps) {
    double term = x * x / 2.0;
    double sum = 0.0;
    double n = 0.0;

    while (term >= eps || term <= -eps) {
        sum += term;
        term *= 2.0 * (2.0 * n + 1.0) * x / (n + 3.0);
        ++n;
    }

    return sum + term;
}

// Reads exactly one real number.
double readNumber(const char* name, const char* hint) {
    cout << "Enter " << name << " (" << hint << "): ";

    string line;
    if (!getline(cin, line)) {
        throw invalid_argument(format("Cannot read {}.", name));
    }

    istringstream input(line);
    double value;

    if (!(input >> value)) {
        throw invalid_argument(
            format("Invalid {}: expected a real number.", name));
    }

    input >> ws;
    if (!input.eof()) {
        throw invalid_argument(
            format("Invalid {}: extra characters.", name));
    }

    return value;
}


int main() {
    cout << "Author: Kostiantyn Liashenko\n";
    cout << "Variant: 171\n";
    cout << "This program calculates the value a power series.\n";

    try {
        const double x = readNumber("x", "from -0.2 to 0.2");

        if (!isfinite(x) || x < a || x > b) {
            throw domain_error("x must be in [-0.2, 0.2].");
        }

        const double eps = readNumber("eps", "positive real number");

        if (!isfinite(eps) || eps <= 0.0) {
            throw domain_error(
                "eps must be a finite positive number.");
        }

        cout << "\n***** do calculations ... " << flush;

        const double result = s(x, eps);

        cout << "done\n";
        cout << format("for x = {:.7E}\n", x);
        cout << format("for eps = {:.9E}\n", eps);
        cout << format("result = {:.8f}\n", result);
    }
    catch (const exception& error) {
        cout << "\n***** error\n";
        cout << error.what() << '\n';
    }
}
