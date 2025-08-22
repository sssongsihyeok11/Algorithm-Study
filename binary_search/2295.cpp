#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    vector<int> sum_of_two;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum_of_two.push_back(arr[i] + arr[j]);
        }
    }

    sort(sum_of_two.begin(), sum_of_two.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int target = arr[i] - arr[j]; 
            if (binary_search(sum_of_two.begin(), sum_of_two.end(), target)) {
                cout << arr[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}