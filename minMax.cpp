#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
void maxmin(int low, int high, const vector<int>& arr, int& max_val, int& min_val) {
if (low == high) {
max_val = arr[low];
min_val = arr[low];
} else if (high == low + 1) {
max_val = max(arr[low], arr[high]);
min_val = min(arr[low], arr[high]);
} else {
int mid = (low + high) / 2;
int max_val1, min_val1;
maxmin(low, mid, arr, max_val, min_val);
maxmin(mid + 1, high, arr, max_val1, min_val1);
if (max_val < max_val1)
max_val = max_val1;
if (min_val > min_val1)
min_val = min_val1;
}
}
int main() {
srand(time(0));
vector<int> arr;
int size = 10;
int min_range = 1;
int max_range = 10;
for (int i = 0; i < size; ++i) {
arr.push_back(rand() % (max_range - min_range + 1) + min_range);
}
auto start = high_resolution_clock::now();
int low = 0;
int high = arr.size() - 1;
int max_val, min_val;
maxmin(low, high, arr, max_val, min_val);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<nanoseconds>(stop - start);
cout << "Time taken: " << duration.count() << " nanoseconds" << endl;
return 0;
}
