#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
double evaluatePolynomial(const vector<double>& coefficients, double x) {
double result = 0;
for (int i = coefficients.size() - 1; i >= 0; i--) {
result = result * x + coefficients[i];
}
return result;
}
int main() {
srand(time(nullptr));
int size;
cout << "Enter the size of the polynomial coefficients array: ";
cin >> size;
vector<double> coefficients(size);
cout << "Random coefficients of the polynomial: ";
for (int i = 0; i < size; ++i) {
coefficients[i] = rand() % 10 + 1;
cout << coefficients[i] << " ";
}
cout << endl;
double x;
cout << "Enter the value of x for evaluation: ";
cin >> x;
auto start = high_resolution_clock::now();
double result = evaluatePolynomial(coefficients, x);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<nanoseconds>(stop - start);
cout << "Time taken for evaluation: " << duration.count() << " nanoseconds" << endl;
return 0;
}
