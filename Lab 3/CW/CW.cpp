#include <iostream>
using namespace std;

void selectionsort(int array[] ,  int size){
    for(int i=0 ; i<size-1 ; i++){
        int minindex = i;
        
        for(int j = i + 1 ; j < size ; j++){
            if(array[minindex] > array[j]){
                minindex = j ;
            }
        }
        swap(array[i], array[minindex]);
    }
}

int binarySearch(int arr[], int size, int search){
    int low = 0;
    int high = size - 1;
    int mid = size / 2;
    while(low <= high){
        if(arr[mid] == search) return mid;
        else if(arr[mid] > search) low = mid;
        else if (arr[mid < search]) high = mid;
        mid -= (high - low)/2;
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int s){
    int low = 0;
    int high = size - 1;
    while (low <= high && s >= arr[low] && s <= arr[high])
    {
        if (high == low){
            if (arr[low] == s){
                return low;
            }
            return -1;
        }

        int pos = low + (((s - arr[low]) * (high - low)) / (arr[high] - arr[low]));

        if (arr[pos] == s) return pos;
        else if (arr[pos] < s) low = pos + 1;
        else high = pos - 1;
    }

    return -1;
}

void printArr(int arr[], int size){
    cout << "Array: " ;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << "Element found at index:", interpolationSearch(arr, 10, 70);
}
