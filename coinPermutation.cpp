#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip> // For setprecision()

using namespace std;

double Time_calculation();
void Truth_Table(int, int, vector<char>&);

int main() {
    double t = Time_calculation();
    cout << "Time taken: " << fixed << setprecision(10) << t << " seconds" << endl;
    return 0;
}

double Time_calculation() {
    clock_t start, end;
    int i = 4;  // Number of variables for the truth table

    vector<char> x(i + 1);  // Store the truth table values
    start = clock();
    
    Truth_Table(0, i - 1, x);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    
    return time_taken;  // Return the correct time taken
}

void Truth_Table(int k, int n, vector<char>& x) {
    if (k == n + 1) {
        for (int i = 0; i <= n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }
    
    x[k] = 'T';
    Truth_Table(k + 1, n, x);
    
    x[k] = 'F';
    Truth_Table(k + 1, n, x);
}
