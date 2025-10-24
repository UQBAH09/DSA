#include <iostream>
using namespace std;

struct Review {
    int rating;
    string text;
};

bool compare(const Review &a, const Review &b) {
    if (a.rating == b.rating)
        return a.text < b.text;
    return a.rating > b.rating;
}

void merge(Review arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Review L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Review arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    Review reviews[5] = {
        {5, "Excellent product"},
        {3, "Average quality"},
        {5, "Amazing value"},
        {4, "Good but could be better"},
        {3, "Affordable and decent"}
    };

    int n = 5;

    mergeSort(reviews, 0, n - 1);

    cout << "Sorted Reviews (by rating descending):\n";
    for (int i = 0; i < n; i++) {
        cout << "Rating: " << reviews[i].rating  << " | Review: " << reviews[i].text << endl;
    }

    return 0;
}
