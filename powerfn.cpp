#include <iostream>
using namespace std;

int power(int x, int n) {
if (n == 0) {
return 1;
} else {
int halfPower = power(x, n / 2);
if (n % 2 == 0) {
return halfPower * halfPower;
} else {
return x * halfPower * halfPower;
}
}
}
int main() {
int base, exponent;
cout << "Enter base: ";
cin >> base;
cout << "Enter exponent: ";
cin >> exponent;
int result = power(base, exponent);
cout << "Result: " << result << endl;
return 0;
}
