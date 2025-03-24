#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

struct Item {
    int profit;
    int weight;
};

double Knapsack(int Capacity, vector<Item>& arr, int n) {
    vector<pair<double, int>> v; // Holds (profit/weight ratio, index)
    
    // Calculate profit/weight ratio and store index
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i].profit / double(arr[i].weight), i});
    }

    // Sort in descending order of profit/weight ratio
    sort(v.rbegin(), v.rend());

    double ans = 0; // Maximum profit

    for (int i = 0; i < n && Capacity > 0; i++) {
        int idx = v[i].second; // Original item index
        if (arr[idx].weight >= Capacity) {
            ans += Capacity * v[i].first;
            break;
        } else {
            ans += arr[idx].profit;
            Capacity -= arr[idx].weight;
        }
    }
    return ans;
}

int main() {
    int numberItems, Capacity;
    cout << "Enter the number of items & total capacity: ";
    cin >> numberItems >> Capacity;

    vector<Item> arritems(numberItems);
    
    cout << "Enter profits: ";
    for (int i = 0; i < numberItems; i++) cin >> arritems[i].profit;

    cout << "Enter weights: ";
    for (int i = 0; i < numberItems; i++) cin >> arritems[i].weight;

    cout << "Maximum Profit: " << Knapsack(Capacity, arritems, numberItems) << endl;
    return 0;
}

