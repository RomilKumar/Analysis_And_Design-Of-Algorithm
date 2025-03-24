#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

void permute(string str, int k, int n) {
if (k == n) {
cout << str << endl;
return;
}
for (int i = k; i <= n; i++) {
swap(str[k], str[i]);
permute(str, k + 1, n);
swap(str[k], str[i]);
}
}
int main() {
string input_string = "abc";
auto start = high_resolution_clock::now();
permute(input_string, 0, input_string.length() - 1);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
return 0;
}