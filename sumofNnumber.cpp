#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0;
    else
        return arr[0] + recursiveSum(arr + 1, size - 1);
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000;
    }

    auto start = high_resolution_clock::now();
    int sum = recursiveSum(arr, size);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sum of the array elements: " << sum << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    delete[] arr; // Free allocated memory
    return 0;
}

    