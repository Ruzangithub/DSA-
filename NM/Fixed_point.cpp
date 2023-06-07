#include<iostream>
#include<cmath>
using namespace std;

double fun(double a)
{
    return exp(-a);
}

double FixedPoint(double x, double err, double maxiteration)
{
    for(int i=0;i<maxiteration;i++)
    {
        double xn=fun(x);

        if (abs(xn-x)<err)
        {
            cout<<"Converged after "<< i+1 <<" iteration "<<endl;
            return xn;
        }
        x=xn;
    }
    cout<<"Did not converged after max iteration"<<endl;
    return x;
}

int main()
{
    double initial_guess;
    double error;
    double max_iterration;

    cout<<"Enter your guess : ";
    cin>>initial_guess;
    cout<<"Enter your tolerance :";
    cin>>error;
    cout<<"Enter your max iterration :";
    cin>>max_iterration;

    double root = FixedPoint(initial_guess,error,max_iterration);

    cout<<"Root is :"<<root<<endl;
    return 0;

}