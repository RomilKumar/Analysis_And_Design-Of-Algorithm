#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    vector<int> temp(end - start + 1);

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

void mergesort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void generateRandomInputs(vector<int>& arr) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 100000);

    for (int& num : arr) {
        num = dist(gen);
    }
}

int main() {
    srand(time(0));

    const int numInputs = 10;
    vector<int> arraySizes(numInputs);
    vector<long long> result(numInputs);

    for (int i = 0; i < numInputs; ++i) {
        arraySizes[i] = (i + 1) * 500;
    }

    for (int i = 0; i < numInputs; ++i) {
        int arraySize = arraySizes[i];
        vector<int> arr(arraySize);

        generateRandomInputs(arr);

        auto start = high_resolution_clock::now();
        mergesort(arr, 0, arraySize - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        result[i] = duration.count();
    }

    cout << "Input Size\tTime Taken (microseconds)\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < numInputs; ++i) {
        cout << arraySizes[i] << "\t\t" << result[i] << " µs" << endl;
    }

    return 0;
}
