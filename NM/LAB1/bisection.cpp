//code  for Bisection 
#include<iostream>
#include<cmath>

using namespace std;

double equation(double x)
{
    return 5* pow(x,5)-2* pow(x,2)-6;
}

double Bi(double a, double b, double err)
{
    double c;
    int iteration =0;
    while ((b-a)>=err)
    {
        c=(a+b)/2;
        if (equation(c)==0)
            break;
        if (equation(c)*equation(a)<0)
            b=c;
        else
        {
            a=c;
        }
       iteration++;     
    }
    cout<<"iteration is :"<<iteration<<endl;
    return c;
}

int main()
{
    double a,b,err;
    cout<<"Enter the initial values :";
    cin>>a>>b;
    cout<<"Enter the err tolorance :";
    cin>>err;
    double root= Bi(a,b,err);
    cout<<"Root is :"<<root<<endl;
    return 0;
}