//recursive code to find the sum of number in an array

#include <iostream>
using namespace std;

int Recursive(int arr[], int size) 
{
    if (size == 0) 
    {
        return 0;  
    } else 
    {
        return arr[size - 1] + Recursive(arr, size - 1);

    }
}

int main() 
{
    int arr[] = {9,0,0,0,1,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = Recursive(arr, size);

    cout << "Sum of the array elements: " << sum << endl;

    return 0;
}
