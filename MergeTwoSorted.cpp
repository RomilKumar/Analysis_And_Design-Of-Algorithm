#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

void merge_sorted_arrays(const std::vector<int>& arr1, const std::vector<int>& arr2, std::vector<int>& merged_array) {
    int i = 0, j = 0, k = 0;
    int s1 = arr1.size(), s2 = arr2.size();
    
    while (i < s1 && j < s2) {
        if (arr1[i] < arr2[j]) {
            merged_array[k++] = arr1[i++];
        } else {
            merged_array[k++] = arr2[j++];
        }
    }
    
    while (i < s1) {
        merged_array[k++] = arr1[i++];
    }
    
    while (j < s2) {
        merged_array[k++] = arr2[j++];
    }
}

int main() {
    srand(time(0));
    int n;
    std::cout << "Enter the size of the arrays: ";
    std::cin >> n;

    std::vector<int> array1(n), array2(n);
    
    for (int i = 0; i < n; ++i) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Sorting both arrays before merging
    std::sort(array1.begin(), array1.end());
    std::sort(array2.begin(), array2.end());

    std::vector<int> resultant_array(2 * n);

    auto start = std::chrono::high_resolution_clock::now();
    merge_sorted_arrays(array1, array2, resultant_array);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::nano> elapsed_nanoseconds = end - start;
    std::cout << "Time taken for merging: " << elapsed_nanoseconds.count() << " nanoseconds" << std::endl;

    std::cout << "Merged sorted array: ";
    for (int num : resultant_array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
