#include <iostream>
using namespace std;

void example1(){
    int arr[5] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "1D Array: ";
    for (int i = 0; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
}

void example2(){
    int arr[2][3] = {{1,2,3},{4,5,6}};

    int row = sizeof(arr)/sizeof(arr[0]);
    int col = sizeof(arr[0])/sizeof(arr[0][0]);

    cout << "2D Array: " << endl;
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

void example3(){
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int *arr = new int(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "1D Array: ";
    for (int i = 0; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

    delete arr;
}

void example4(){
    int row, col;

    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of colums: ";
    cin >> col;

    int **arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int(col);
    }
    

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element (" << i << "," << j << "): ";
            cin >> arr[i][j];
        }
    }
    
    cout << "\n2D Array: " << endl;
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete arr[i];
    }
    delete arr;
}

void example5(){
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    // Get size of colums
    int *col = new int(row);
    for (int i = 0; i < row; i++)
    {
        cout << "Enter number of colums in row " << i+1 << ": ";
        cin >> col[i];
    }

    // Declare array
    int **arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int(col[i]);
    }
    
    // Enter value in the array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << "Enter element (" << i << "," << j << "): ";
            cin >> arr[i][j];
        }
    }
    
    // Print the array
    cout << "\n2D Array: " << endl;
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
    
    for (int i = 0; i < row; i++)
    {
        delete arr[i];
    }
    delete arr;
    delete col;
}

int main(){
    // example1();
    // example2();
    // example3();
    example5();
}