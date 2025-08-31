#include <iostream>
using namespace std;

class Marks{
    int department;
    int *student;
    int subject = 5;
    int ***marks;
public:
    Marks(int depart, int *std): department(depart), student(new int[depart]) {
        // Number of students in each department
        for (int i = 0; i < depart; i++)
        {
            student[i] = std[i];
        }
        // Allocate memory
        marks = new int**[department];
        for (int i = 0; i < department; i++)
        {
            marks[i] = new int*[student[i]];
        }
        for (int i = 0; i < department; i++)
        {
            for (int j = 0; j < student[i]; j++)
            {
                marks[i][j] = new int[subject];
            }
        }
        // Populate the array
        for (int i = 0; i < department; i++)
        {
            for (int j = 0; j < student[i]; j++)
            {
                for (int k = 0; k < subject; k++)
                {
                    cin >> marks[i][j][k];
                }
            }
        }
    }

    ~Marks(){
        for (int i = 0; i < department; i++)
        {
            for (int j = 0; j < student[i]; j++)
            {
                delete[] marks[i][j];
            }
        }
        for (int i = 0; i < department; i++)
        {
            delete[] marks[i];
        }
        delete[] marks;
        delete[] student;
    }

    int** totalMarks(){
        // Creating array to store total of each student in each department
        int **total;
        total = new int*[department];
        for (int i = 0; i < department; i++)
        {
            total[i] = new int[student[i]];
        }
        // Populate the total array
        for (int i = 0; i < department; i++)
        {
            for (int j = 0; j < student[i]; j++)
            {
                total[i][j] = 0;
            }
        }
        // Calculating the total 
        for (int i = 0; i < department; i++)
        {
            for (int j = 0; j < student[i]; j++)
            {
                for (int k = 0; k < subject; k++)
                {
                    total[i][j] += marks[i][j][k];            
                }
            }
        }
        // // Printing the total
        // for (int i = 0; i < department; i++)
        // {
        //     cout << "Department " << i + 1 <<": " << endl;
        //     for (int j = 0; j < student[i]; j++)
        //     {
        //         cout << "Student " << j + 1 << ": " << total[i][j] << endl;
        //     }
        //     cout << endl;
        // }
        return total;
    }

    void highest(){
        int **total = totalMarks();
        int max, std;
        cout << "\nHigest Marks:" << endl;
        for (int i = 0; i < department; i++)
        {
            max = total[i][0];
            std = 0;
            for (int j = 0; j < student[i]; j++)
            {
                if(max < total[i][j]){
                    max = total[i][j];
                    std = j;
                }
            }
            cout << "Department " << i + 1 << ": Student " << std + 1 << " - " << max << endl;
            delete[] total[i];
        }
        delete[] total;
    }

    void lowest(){
        int **total = totalMarks();
        int min, std;
        cout << "\nLowest Marks:" << endl;
        for (int i = 0; i < department; i++)
        {
            min = total[i][0];
            std = 0;
            for (int j = 0; j < student[i]; j++)
            {
                if(min > total[i][j]){
                    min = total[i][j];
                    std = j;
                }
            }
            cout << "Department " << i + 1 << ": Student " << std + 1 << " - " << min << endl;
            delete[] total[i];
        }
        delete[] total;
    }

    void average(){
        int **total = totalMarks();
        int avg;
        cout << "\nAverage Marks:" << endl;
        for (int i = 0; i < department; i++)
        {
            avg = 0;
            for (int j = 0; j < student[i]; j++)
            {
                avg += total[i][j];
            }
            cout << "Department " << i + 1 << ": " << avg / student[i] << endl;
            delete[] total[i];
        }
        delete[] total;
    }
};

int main(){
    int students[] = {2, 1};
    Marks m(2, students);
    
    m.highest();
    m.lowest();
    m.average();
}