#include<iostream>
using namespace std;

void selectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }   
}

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(int arr[], int size){
    cout << "Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int linearSearch(int arr[], int size, int search){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == search){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int search){
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] == search) return mid;
        else if(arr[mid] < search) left = mid + 1;
        else if(arr[mid] > search) right = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int search){
    int left = 0;
    int right = size - 1;

    while(left <= right && search >= arr[left] && search <= arr[right]){
        if (left == right)
        {
            if (arr[left] == search) return -1;
        }
        
        int pos = left + ((search - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if(arr[pos] == search) return pos;

        if(arr[pos] < search) left = pos + 1;

        else right = pos - 1;
    }
    return -1;
}

int main(){
    int arr[10] = {3,7,3,6,9,5,2,1,5,0};
    selectionSort(arr, 10);
    // insertionSort(arr, 10);
    // print(arr, 10);

    cout << "Linear Search: " << linearSearch(arr,10,6) << endl;
    cout << "Binary Search: " << binarySearch(arr,10,6) << endl;
    cout << "Interpolation Search: " << interpolationSearch(arr,10,6) << endl;
}