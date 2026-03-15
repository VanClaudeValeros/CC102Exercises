#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cstdlib>
using namespace std;

int main(){
    int students;
    int subjects;
    char choice;
    double sum = 0;

    do{
        system("cls");
        cout << "Student Grades: (Represented in columns and rows)" << endl; // Student represents as Row and Subjects represents as columns

        cout << "Enter a number of student: ";
        cin >> students;

        cout << "Enter a number of student: ";
        cin >> subjects;

        cout<<endl;
        cout<<endl;

        vector<vector<int>> gridGrade(students, vector<int>(subjects));
        vector<vector<int>> *pGrid = &gridGrade; // p stands for point, pointers are confusing.

        for (int i = 0; i < (*pGrid).size(); i++){
            for (int j = 0; j < (*pGrid)[i].size(); j++){
                cout << "Enter grade for Student #" << i + 1 << ", Subject #" << j + 1 << ": ";
                cin >> (*pGrid)[i][j];
            }
            cout << "---------------------------------------" << endl;
        }
        cout<<endl;

        cout<< "Students|\t";

        for(int i=1; i <= subjects; i++){
            cout<<"S"<<i<<"\t";
        }

        cout << "|\t";

        cout << "Average";
        cout << endl;

        for (int i = 0; i < (*pGrid).size(); i++){
            cout<<"----------------------";
        }
        cout<<endl;

        for (int i = 0; i < (*pGrid).size(); i++){
                cout << "   " << i + 1 << '\t';
                cout << "|" << '\t';
                sum = 0;
            for (int j = 0; j < (*pGrid)[i].size(); j++){
                cout << (*pGrid)[i][j] << '\t';
                sum += (*pGrid)[i][j];
            }
            cout << "|" << '\t';
            cout << sum / subjects;
            cout << endl;
        }

        cout<<endl;

        int largest = (*pGrid)[0][0]; //largest is the highest grade in the matrix
        for (int i = 0; i < (*pGrid).size(); i++){
            for (int j = 0; j < (*pGrid)[i].size(); j++){
                if ((*pGrid)[i][j] > largest){
                    largest = (*pGrid)[i][j];
                }
            }
        }

        cout << "This is the highest grade: " << largest <<endl;

        cout << "Do you want to do it again [Y/N]: ";
        cin >> choice;
    }while(tolower(choice)=='y');

	return 0;
}
