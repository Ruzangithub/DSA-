#include <iostream>
#include <vector>

using namespace std;

double hornerMethod(const vector<double>& coefficients, double x) {
    double result = coefficients[0];
    int n = coefficients.size();
    for (int i = 1; i < n; i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    vector<double> coefficients = {2, -3, 1}; 
    double x = 3;
    double result = hornerMethod(coefficients, x);
    cout << "Result: " << result << endl;

    return 0;
}
