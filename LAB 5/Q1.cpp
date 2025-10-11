#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int target) {
    if (target == 0) return true;
    if (n == 0 && target != 0) return false;

    if (arr[n - 1] > target)
        return subsetSum(arr, n - 1, target);

    return subsetSum(arr, n - 1, target) || subsetSum(arr, n - 1, target - arr[n - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSum(arr, n, target))
        cout << "True (subset with target sum exists)" << endl;
    else
        cout << "False (no subset found)" << endl;

    return 0;
}
