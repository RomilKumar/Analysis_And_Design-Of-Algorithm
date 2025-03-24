#include <bits/stdc++.h>
using namespace std;

// Splitting matrix into sub-matrices
vector<vector<int>> split(vector<vector<int>> &a, int startRow, int endRow, int startCol, int endCol) {
    vector<vector<int>> c;
    for (int i = startRow; i < endRow; i++) {
        vector<int> temp;
        for (int j = startCol; j < endCol; j++) {
            temp.push_back(a[i][j]);
        }
        c.push_back(temp);
    }
    return c;
}

// Matrix Subtraction
vector<vector<int>> subtraction(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

// Matrix Addition
vector<vector<int>> addition(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

// Vertical Stacking
vector<vector<int>> vstack(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> c = a;
    c.insert(c.end(), b.begin(), b.end());
    return c;
}

// Horizontal Stacking
vector<vector<int>> hstack(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> c(a.size(), vector<int>(a[0].size() + b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        copy(a[i].begin(), a[i].end(), c[i].begin());
        copy(b[i].begin(), b[i].end(), c[i].begin() + a[i].size());
    }
    return c;
}

// Strassen’s Algorithm for Matrix Multiplication
vector<vector<int>> strassen(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();

    // Base case: 1x1 matrix
    if (n == 1)
        return {{a[0][0] * b[0][0]}};

    // Splitting matrices
    int mid = n / 2;
    vector<vector<int>> a1 = split(a, 0, mid, 0, mid);
    vector<vector<int>> a2 = split(a, 0, mid, mid, n);
    vector<vector<int>> a3 = split(a, mid, n, 0, mid);
    vector<vector<int>> a4 = split(a, mid, n, mid, n);
    vector<vector<int>> b1 = split(b, 0, mid, 0, mid);
    vector<vector<int>> b2 = split(b, 0, mid, mid, n);
    vector<vector<int>> b3 = split(b, mid, n, 0, mid);
    vector<vector<int>> b4 = split(b, mid, n, mid, n);

    // 7 Recursive Strassen Multiplications
    vector<vector<int>> p = strassen(a1, subtraction(b2, b4));
    vector<vector<int>> q = strassen(addition(a1, a2), b4);
    vector<vector<int>> r = strassen(addition(a3, a4), b1);
    vector<vector<int>> s = strassen(a4, subtraction(b3, b1));
    vector<vector<int>> t = strassen(addition(a1, a4), addition(b1, b4));
    vector<vector<int>> u = strassen(subtraction(a2, a4), addition(b3, b4));
    vector<vector<int>> v = strassen(subtraction(a1, a3), addition(b1, b2));

    // Constructing result matrix
    vector<vector<int>> c11 = addition(subtraction(addition(t, s), q), u);
    vector<vector<int>> c12 = addition(p, q);
    vector<vector<int>> c21 = addition(r, s);
    vector<vector<int>> c22 = subtraction(subtraction(addition(p, t), r), v);

    return vstack(hstack(c11, c12), hstack(c21, c22));
}

int main() {
    vector<vector<int>> a = {
        {5, 7, 9, 10},
        {2, 3, 3, 8},
        {8, 10, 2, 3},
        {3, 3, 4, 8}
    };

    vector<vector<int>> b = {
        {3, 10, 12, 18},
        {12, 1, 4, 9},
        {9, 10, 12, 2},
        {3, 12, 4, 10}
    };

    vector<vector<int>> c = strassen(a, b);

    // Printing Result Matrix
    cout << "Resultant Matrix: \n";
    for (const auto &row : c) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
