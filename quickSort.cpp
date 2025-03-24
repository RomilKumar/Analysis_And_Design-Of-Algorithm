#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


int partition(vector<int>& arr, int low, int high) {
  
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(low, high);
    int randomPivotIndex = dist(gen);
    
    swap(arr[randomPivotIndex], arr[high]);  

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random inputs
void generateRandomInputs(vector<int>& arr) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 100000);

    for (int& num : arr) {
        num = dist(gen);
    }
}

int main() {
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
        quickSort(arr, 0, arraySize - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        result[i] = duration.count();
    }

    // Display results
    cout << "Input Size\tTime Taken (microseconds)\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < numInputs; ++i) {
        cout << arraySizes[i] << "\t\t" << result[i] << " µs" << endl;
    }

    return 0;
}
