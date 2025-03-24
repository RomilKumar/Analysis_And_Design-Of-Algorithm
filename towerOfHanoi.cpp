#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip> // Added for setprecision()

using namespace std;

double Time_calculation();  // Change return type to double
void Hanoi_Tower(int, char, char, char);

int main() {
    double t = Time_calculation();
    cout << "Average time taken: " << fixed << setprecision(10) << t << " seconds" << endl;
    return 0;  // Added return statement
}

void Hanoi_Tower(int n, char source, char to, char destination) {
    if (n >= 1) {
        Hanoi_Tower(n - 1, source, destination, to);
        cout << "Move 1 disk from " << source << " to " << destination << endl;
        Hanoi_Tower(n - 1, to, source, destination);
    }
}

double Time_calculation() {  // Change return type to double
    clock_t start, end;
    int i = 9;
    
    start = clock();
    char A = 'A';
    char B = 'B';
    char C = 'C';

    for (int m = 1; m <= 10; m++) {
        Hanoi_Tower(i, A, B, C);
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    double result = time_taken / 10.0;  // Average time

    return result;  // Return the computed time
}
