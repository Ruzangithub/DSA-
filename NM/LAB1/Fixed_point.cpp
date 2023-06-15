#include<iostream>
#include<cmath>
using namespace std;

double fun(double a)
{
    return exp(-a);
}

double FixedPoint(double x, double err)
{
    double xo=x;
    double xn;
    double nerr=1.0;
    double iteration =0;

    while(nerr >err)
    {
        //xn = -log(fun(xo));
        xn = (1 - pow(x, 3)) / 2;
        nerr = abs((xn - xo) / xn);
        xo = xn;
        iteration++;
    }
   
    cout << "Functional Value at Root: " << fun(xn) << endl;
    cout << "Number of Iterations: " << iteration << endl;
    return xn;
}

int main()
{
    double initial_guess;
    double error;

    cout<<"Enter your guess : ";
    cin>>initial_guess;
    cout<<"Enter your tolerance :";
    cin>>error;

    double root = FixedPoint(initial_guess,error);

     cout << "Estimated Root: " << root << endl;
    return 0;

}