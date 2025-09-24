#include <iostream>
using namespace std;

int search(int arr[], int size, int val){
    // Bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    // Print sorted array
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Linear search
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == val) return i;
    }
    return -1;
}

int main(){
    int arr[] = {5,4,2,0,9,8,3,1,6,7};

    cout << "Target found at index: " << search(arr, 10, 6);
}