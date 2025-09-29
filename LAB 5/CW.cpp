#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void funA(int n);
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funA(n / 2);
    }
}

bool isSafe(int arr[][4], int x, int y, int n, int solArr[][4])
{
    return (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1 && solArr[x][y] == 0);
}

bool ratInMaze(int arr[][4], int x, int y, int n, int solArr[][4])
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, solArr))
    {
        solArr[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solArr))
            return true;
        if (ratInMaze(arr, x, y + 1, n, solArr))
            return true;
        if (ratInMaze(arr, x - 1, y, n, solArr))
            return true;
        if (ratInMaze(arr, x, y - 1, n, solArr))
            return true;

        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main()
{
    int arr[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}};

    int sol[4][4];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            sol[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, 4, sol))
    {
        cout << "Path found." << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}