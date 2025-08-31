#include <iostream>
using namespace std;

class Matrix{
    int row;
    int col;
    int **arr;

    // Allocate memory
    void alloc(int r = 0, int c = 0, int v = 0){
        row = r;
        col = c;
        arr = new int*[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = v;
            }
        }
    }

    void deloc(){
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
public:
    Matrix(int row = 0, int col = 0, int val = 0) {alloc(row, col, val);}

    Matrix& operator=(const Matrix& m){
        if(this != &m){
            deloc();
            
            alloc(m.row, m.col);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    arr[i][j] = m.arr[i][j];
                }   
            }
        }
        return *this;
    }

    ~Matrix(){deloc();}
    
    void resize(int newRow, int newCol, int val = 0){
        Matrix m(newRow, newCol, val);

        int r = (row > newRow)? newRow: row;
        int c = (col > newCol)? newCol: col; 

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                m.arr[i][j] = arr[i][j];
            }
        }

        *this = m;
    }

    void transpose(){
        Matrix m(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m.arr[j][i] = arr[i][j];
            }
        }

        *this = m;
    }

    friend ostream& operator<<(ostream& out, const Matrix& m){
        out << "Matrix:" << endl;
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.col; j++)
            {
                out << " " << m.arr[i][j];
            }
            out << endl;
        }
        return out;
    }

    void add2(){
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int index = i * col + j;
                if (index % 2 != 0){
                    arr[i][j] += 2;
                }
            }
        }   
    }
    
};

int main(){
    Matrix m(2, 2, 7);
    cout << m;
    
    // Resizing the matrix
    cout << "Increasing the size:" << endl;
    m.resize(4,4,3);
    cout << m << endl;
    cout << "Decreasing the size:" << endl;
    m.resize(2,2);
    cout << m << endl;

    // Transpose
    cout << "Transpose array:" << endl;
    m.transpose();
    cout << m;

    // Add 2 to each odd index
    cout << "Add 2 to each odd index: " << endl;
    m.add2();
    cout << m;
}