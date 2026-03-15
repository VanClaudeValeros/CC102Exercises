#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    char choice;

    do {
        system("cls");

        int numStudents, numQuizzes;

        // User Input for Dimensions
        cout << "\n--- Student Quiz Records ---" << endl;
        cout << "Enter number of students: ";
        cin >> numStudents;
        cout << "Enter number of quizzes: ";
        cin >> numQuizzes;

        // 2D Array setup
        vector<vector<double>> scores(numStudents, vector<double>(numQuizzes));

        // Data Entry
        for (int i = 0; i < numStudents; ++i) {
            cout << "\nEntering scores for Student " << (i + 1) << ":" << endl;
            for (int j = 0; j < numQuizzes; ++j) {
                cout << "  Quiz " << (j + 1) << ": ";
                cin >> scores[i][j];
            }
        }

        // Table Header
        cout << "\nStudent\t\t";
        for (int j = 0; j < numQuizzes; ++j) {
            cout << "Quiz " << (j + 1) << "\t";
        }
        cout << "Average" << endl;
        cout << endl;

        // Table Content and Calculation
        for (int i = 0; i < numStudents; ++i) {
            double sum = 0;
            cout << "Student " << (i + 1) << "\t";

            for (int j = 0; j < numQuizzes; ++j) {
                cout << scores[i][j] << "\t";
                sum += scores[i][j];
            }

            // Computing and displaying Average
            double average = sum / numQuizzes;
            cout << average << endl;
        }

        // Loop Control
        cout << "\nRun again? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    cout << "Exiting program..." << endl;
    return 0;
}
