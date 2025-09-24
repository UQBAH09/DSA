#include <iostream>
using namespace std;

int search(int arr[], int size, int val){
    // Insertion sort
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    //Binary search
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        
        if(arr[middle] == val) return middle;
        else if(arr[middle] > val) end = middle - 1;
        else if(arr[middle] < val) start = middle + 1;
    }
    return -1;
}

void print(int arr[], int size){
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5,4,2,0,9,8,3,1,6,7};

    cout << "Target found at index: " << search(arr, 10, 6);
}