#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<iomanip> // Add this line for setprecision
using namespace std;

vector<int> generateRandomList(int size);
void selectionSort(vector<int>& arr);
double calculateTime(vector<int>& arr);

int main() {
const int listSize = 10;
vector<int> myList = generateRandomList(listSize);

double averageTime = calculateTime(myList);

cout << "Average time taken for selection sort: " << averageTime << " nanoseconds" << endl;
return 0;
}

void selectionSort(vector<int>& arr) {
int n = arr.size();
for(int i = 0; i < n; i++) {
int minIndex = i;
for(int j = i + 1; j < n; j++) {
if(arr[j] < arr[minIndex]) {
minIndex = j;
}
}
swap(arr[i], arr[minIndex]);
}
}

double calculateTime(vector<int>& arr) {
clock_t start, end;
double totalTime = 0.0;
for(int m = 1; m <= 10; m++) {
vector<int> arrCopy = arr;
start = clock();
selectionSort(arrCopy);
end = clock();
double timeTaken = double(end - start) / CLOCKS_PER_SEC * 1e9;
totalTime += timeTaken;
}

return totalTime / 10.0;
}

vector<int> generateRandomList(int size) {
vector<int> randomList;
for(int i = 0; i < size; i++) {
randomList.push_back(rand() % size);
}
return randomList;
}
