#include <iostream>
#include <array>
#include <cstdlib>
#include <cctype>
using namespace std;

struct student {
    int studentId;
    string name;
    string course;
    int gpa;
};

int main(){
    char choice;
    do {
        system("cls");
        int numStudents;

        cout << "Enter number of students: ";
        cin >> numStudents;
        cin.ignore();
        cout << endl;

        student s[numStudents];
        for (int i = 0; i < numStudents; i++) {

            bool isDuplicate;
            do {
                isDuplicate = false;

                cout << "Enter a student ID: ";
                cin >> s[i].studentId;
                cin.ignore();

                for (int j = 0; j < i; j++) {
                    if (s[i].studentId == s[j].studentId) {
                        cout << "Duplicate student ID found! Enter a different ID.\n";
                        isDuplicate = true;
                        break;
                    }
                }

            } while (isDuplicate);

            do {
                isDuplicate = false;

                cout << "Enter the name of the student: ";
                getline(cin, s[i].name);

                for (int j = 0; j < i; j++) {
                    if (s[i].name == s[j].name) {
                        cout << "Duplicate name found! Enter a different name.\n";
                        isDuplicate = true;
                        break;
                    }
                }

            } while (isDuplicate);

            cout << "Enter the course of the student: ";
            getline(cin, s[i].course);

            do {
                cout << "Enter the GPA of the student: ";
                cin >> s[i].gpa;
                cin.ignore();

                if (s[i].gpa < 0 || s[i].gpa > 100) {
                    cout << "Please enter a value between 0 and 100.\n";
                }

            } while (s[i].gpa < 0 || s[i].gpa > 100);

            cout << endl;
        }

        for (int i = 0; i < numStudents; i++) {
            int width = 32; // Fixed Range size
            string idStr = to_string(s[i].studentId); // Converting int to string

            cout << "Student #" << i + 1 << endl;
            cout << "--------------------------------------------------------"<< endl;
            cout << "| Student ID:        | " << s[i].studentId;
            for (int j = idStr.length(); j < width; j++) cout << " ";
            cout << "|" << endl;

            cout << "| Name:              | " << s[i].name;
            for (int j = s[i].name.length(); j < width; j++) cout << " ";
            cout << "|" << endl;

            cout << "| Course:            | " << s[i].course;
            for (int j = s[i].course.length(); j < width; j++) cout << " ";
            cout << "|" << endl;

            if (s[i].gpa >= 90 && s[i].gpa <= 100){
                cout << "| Academic Standing: | Excellent                       |" << endl;
            }
            else if (s[i].gpa >= 80 && s[i].gpa <= 89){
                cout << "| Academic Standing: | Very Good                       |" << endl;
            }
            else if (s[i].gpa >= 70 && s[i].gpa <= 79){
                cout << "| Academic Standing: | Good                            |" << endl;
            }
            else if (s[i].gpa >= 60 && s[i].gpa <= 69){
                cout << "| Academic Standing: | Passing                         |" << endl;
            }
            else if (s[i].gpa >= 0 && s[i].gpa <= 60){
                cout << "| Academic Standing: | Failed                          |" << endl;
            }
            cout << "--------------------------------------------------------"<< endl;
            cout << endl;
        }

        cout << "Do you want to try again? ";
        cin >> choice;
    }while (tolower(choice)=='y');
}
