#include <iostream>
using namespace std;

int main(){
    int student = 2;
    int subject = 2;

    // Allocate size for array
    int **score = new int*[student];
    for (int i = 0; i < student; i++)
    {
        score[i] = new int[subject];
    }
    
    // Populate array
    for (int i = 0; i < student; i++)
    {
        for (int j = 0; j < subject; j++)
        {
            cout << "Enter score of student " << i+1 << ", subject " << j+1 << ": ";
            cin >> score[i][j];
        }
    }
    
    // Display all marks
    cout << "\n All Marks...." << endl;
    for (int i = 0; i < student; i++)
    {
        cout << "Student " << i+1 << ": ";
        for (int j = 0; j < subject; j++)
        {
            cout << score[i][j] << " ";
        }
        cout << endl;
    }

    // Total marks for each student
    cout << "\n Total Marks...." << endl;
    int totalMarks[student] = {0};

    for (int i = 0; i < student; i++)
    {
        for (int j = 0; j < subject; j++)
        {
            totalMarks[i] += score[i][j];
        }
    }
    for (int i = 0; i < student; i++)
    {
        cout << "Student " << i+1 <<": " << totalMarks[i] << endl;
    }
    
    // Average marks for each subject
    cout << "\n Average Marks...." << endl;
    int subjectMarks[subject] = {0};

    for (int i = 0; i < subject; i++)
    {
        for (int j = 0; j < student; j++)
        {
            subjectMarks[i] += score[i][j];
        }
    }
    for (int i = 0; i < subject; i++)
    {
        cout << "Subject " << i+1 <<": " << (float)subjectMarks[i]/student << endl;
    }
    
    // Topper
    cout << "\n Higgest Marks...." << endl;
    int max = totalMarks[0];
    int hStudent = 1;
    for (int i = 0; i < student; i++)
    {
        if (totalMarks[i] > max){
            max = totalMarks[i];
            hStudent = i+1;
        }
    }
    cout << "Highest score is of student " << hStudent <<": " << max << endl;
    
    for (int i = 0; i < student; i++)
    delete[] score[i];
    delete[] score;

}