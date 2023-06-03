#include <iostream>
#include <cmath>

using namespace std;

double fun(double x) 
{
    return cos(x) + 5 * x - 6;
}

double dev(double x) 
{
    return -sin(x) + 5;
}

double newtonMethod(double x0, double epsilon, int maxIterations) 
{
    double x = x0;
    int iteration = 0;
    
    while (abs(fun(x)) > epsilon && iteration < maxIterations) 
    {
        x = x - fun(x) / dev(x);
        iteration++;
    }
    
    return x;
}

int main() 
{
    double initialGuess;
    double epsilon;
    int maxIterations;
    
    cout << "Enter the initial guess: ";
    cin >> initialGuess;
    
    cout << "Enter the desired accuracy (epsilon): ";
    cin >> epsilon;
    
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;
    
    double root = newtonMethod(initialGuess, epsilon, maxIterations);
    
    if (abs(fun(root)) <= epsilon) 
    {
        cout << "Root found: " << root << endl;
    } else 
    {
        cout << "Root not found within the given number of iterations." << endl;
    }
    
    return 0;
}
