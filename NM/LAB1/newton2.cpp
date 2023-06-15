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

double newtonMethod(double x, double err) 
{
    double xn;
    double nerr = 1.0;
    int iteration = 0;
    
    while (nerr > err)
    {
        xn= x - (fun(x) / dev(x));
        nerr = abs((xn- x) / xn);
        x = xn;
        iteration++;
    }
    cout << "Number of Iterations: " << iteration << endl;
    return xn;
}

int main() 
{
    double initialGuess;
    double epsilon;
    
    cout << "Enter the initial guess: ";
    cin >> initialGuess;
    
    cout << "Enter the desired accuracy (epsilon): ";
    cin >> epsilon;
  
    double root = newtonMethod(initialGuess, epsilon);
    
    if (abs(fun(root)) <= epsilon) 
    {
        cout << "Root found: " << root << endl;
    } 
    else 
    {
        cout << "Root not found within the given number of iterations." << endl;
    }
    
    return 0;
}
