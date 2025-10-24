#include <iostream>
using namespace std;

struct Delivery {
    string destination;
    int ETA;
};

void swap(Delivery &a, Delivery &b) {
    Delivery temp = a;
    a = b;
    b = temp;
}

bool compare(Delivery &a, Delivery &b) {
    if (a.ETA == b.ETA)
        return a.destination < b.destination;
    return a.ETA < b.ETA;
}

int partition(Delivery arr[], int low, int high) {
    Delivery pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Delivery arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Delivery deliveries[3] = {
        {"StoreA", 120},
        {"CustomerB", 45},
        {"Depot", 60}
    };
    int n = 3;

    quickSort(deliveries, 0, n - 1);

    cout << "\nDeliveries sorted by ETA (ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << deliveries[i].destination << " - " << deliveries[i].ETA << " minutes\n";
    }

    return 0;
}
