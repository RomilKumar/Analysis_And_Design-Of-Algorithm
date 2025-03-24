#include <iostream>
#include <vector>
using namespace std;

void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Magic square can only be generated for odd order" << endl;
        return;
    }

    // Use a vector instead of a VLA
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int num = 1;
    int i = n / 2, j = n - 1;

    while (num <= n * n) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) j = 0;
            if (i < 0) i = n - 1;
        }

        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }
        j++;
        i--;
    }

    // Display the magic square
    cout << "The Magic Square for n = " << n << " is:" << endl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the order of the magic square (odd number): ";
    cin >> n;
    generateMagicSquare(n);
    return 0;
}
