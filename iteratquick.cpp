#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative QuickSort
void iterative_quickSort(vector<int>& arr, int l, int h) {
    vector<int> stack(h - l + 1);
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

// Recursive QuickSort with call count tracking
void recursive_quickSort(vector<int>& arr, int l, int h, int& count) {
    if (l < h) {
        count++; // Count each recursive call

        int p = partition(arr, l, h);
        recursive_quickSort(arr, l, p - 1, count);
        recursive_quickSort(arr, p + 1, h, count);
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    srand(time(nullptr));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;  // Generate random numbers in range [0,99]
    }

    int count = 0;
    recursive_quickSort(arr, 0, size - 1, count);

    cout << "Elements after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNumber of recursive calls: " << count << endl;
    return 0;
}
