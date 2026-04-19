#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream color;

    color.open("color.txt", ios::out);
    if (color.is_open()) {
        color << "Red\n";
        color << "Blue\n";
        color << "Green\n";
        color << "Black\n";
        color << "White\n";
        color.close();
        cout << "Write successfully!\n";
    } else {
        cout << "Failed to open color.txt for writing.\n";
        return 1;
    }

    color.open("color.txt", ios::in);
    fstream copyFile;
    copyFile.open("color_copy.txt", ios::out);

    if (color.is_open() && copyFile.is_open()) {
        string line;

        while (getline(color, line)) {
            copyFile << line << endl;
        }

        color.close();
        copyFile.close();
        cout << "File copied successfully!\n";
    } else {
        cout << "Failed to open file for copying.\n";
    }

    return 0;
}
