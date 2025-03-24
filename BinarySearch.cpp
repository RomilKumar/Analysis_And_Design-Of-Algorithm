#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Binary Search Function
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int t = 10;  // Number of trials

    for (int i = 1000; i <= 10000; i += 1000) {
        double timeSum = 0.0;
        int successfulCase = 0;
        int indexPos = 0;

        // Allocate array
        int* a = new int[i];

        for (int j = 0; j < t; j++) {
            // Fill array with sorted values
            for (int k = 0; k < i; k++) {
                a[k] = k;
            }

            // Generate random key
            int key = rand() % (2 * i);

            // Measure binary search execution time
            auto start = high_resolution_clock::now();
            int result = binarySearch(a, 0, i - 1, key);
            auto stop = high_resolution_clock::now();

            // Calculate time taken
            auto duration = duration_cast<microseconds>(stop - start);
            timeSum += duration.count();

            // Track successful searches
            if (result != -1) {
                indexPos += result + 1;
                successfulCase++;
            }
        }

        // Free allocated memory
        delete[] a;

        // Print results
        cout << successfulCase << " ";
        
        if (successfulCase > 0)
            cout << indexPos / successfulCase << " ";
        else
            cout << "N/A ";

        cout << timeSum / t << " μs" << endl;
    }

    return 0;
}
