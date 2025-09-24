#include <iostream>
using namespace std;

int search(int arr[], int size, int val){
    // Selection sort
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        if(minIndex != i) swap(arr[i], arr[minIndex]);
    }

    // Interpolation search
    int start = 0;
    int end = size - 1;

    if (size == 0) return -1;
    if (val < arr[start] || val > arr[end]) return -1;

    while (start <= end){
        if (arr[start] == arr[end]) {
            return (arr[start] == val) ? start : -1;
        }

        int middle = start + (end - start) / (arr[end] - arr[start]) * (val - arr[start]);
        if (middle < start) middle = start;
        if (middle > end) middle = end;

        if(arr[middle] == val) return middle;
        else if(arr[middle] > val) end = middle - 1;
        else if (arr[middle] < val) start = middle + 1;
    }
    return -1;
}

int main(){
    int arr[] = {5,4,2,0,9,8,3,1,6,7};

    cout << "Target found at index: " << search(arr, 10, 6);
}