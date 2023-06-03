#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return 5 * pow(x, 5) - 2 * pow(x, 2) - 6;
}

double secantMethod(double x0, double x1, double error)
{
    double xo = x0;
    double xn = x1;
    double xne = 0.0;
    double nerror = 1.0;
    int iterations = 0;

    while (nerror > error)
    {
        xne = xn - (func(xn) * (xn - xo)) / (func(xn) - func(xo));
        nerror = abs((xne - xn) / xne);
        xo = xn;
        xn = xne;
        iterations++;
    }

    cout << "Estimated Root: " << xne << endl;
    cout << "Functional Value at Root: " << func(xne) << endl;
    cout << "Number of Iterations: " << iterations << endl;

    return xne;
}

int main()
{
    double x0, x1, error;

    cout << "Enter the initial guess (x0): ";
    cin >> x0;
    cout << "Enter the second guess (x1): ";
    cin >> x1;
    cout << "Enter the expected error: ";
    cin >> error;

    double root = secantMethod(x0, x1, error);

    return 0;
}
