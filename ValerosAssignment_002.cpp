#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
using namespace std;

void inputGrades(vector<vector<int>> *pGrid) {
    for (int i = 0; i < (*pGrid).size(); i++) {
        for (int j = 0; j < (*pGrid)[i].size(); j++) {
            cout << "Enter grade for Student #" << i + 1 << ", Subject #" << j + 1 << ": ";
            cin >> (*pGrid)[i][j];
        }
        cout << "---------------------------------------" << endl;
    }
}

void displayGrades(vector<vector<int>> *pGrid, int subjects) {
    double sum = 0;
    cout << "Students|\t";
    for (int i = 1; i <= subjects; i++) {
        cout << "S" << i << "\t";
    }
    cout << "|\tAverage" << endl;

    for (int i = 0; i < (*pGrid).size(); i++) {
        cout << "----------------------";
    }
    cout << endl;

    for (int i = 0; i < (*pGrid).size(); i++) {
        cout << "   " << i + 1 << '\t';
        cout << "|" << '\t';
        sum = 0;
        for (int j = 0; j < (*pGrid)[i].size(); j++) {
            cout << (*pGrid)[i][j] << '\t';
            sum += (*pGrid)[i][j];
        }
        cout << "|" << '\t';
        cout << sum / subjects << endl;
    }
}

int findLargest(vector<vector<int>> *pGrid) {
    int largest = (*pGrid)[0][0];
    for (int i = 0; i < (*pGrid).size(); i++) {
        for (int j = 0; j < (*pGrid)[i].size(); j++) {
            if ((*pGrid)[i][j] > largest) {
                largest = (*pGrid)[i][j];
            }
        }
    }
    return largest;
}

int main() {
    int students;
    int subjects;
    char choice;

    do {
        system("cls");
        cout << "Student Grades: (Represented in columns and rows)" << endl;

        cout << "Enter a number of students: ";
        cin >> students;
        cout << "Enter a number of sunjects: ";
        cin >> subjects;

        cout << endl << endl;

        vector<vector<int>> gridGrade(students, vector<int>(subjects));
        vector<vector<int>> *pGrid = &gridGrade;

        inputGrades(pGrid);
        cout << endl;
        
        displayGrades(pGrid, subjects);
        cout << endl;

        int largest = findLargest(pGrid);
        cout << "This is the highest grade: " << largest << endl;

        cout << "Do you want to do it again [Y/N]: ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}
