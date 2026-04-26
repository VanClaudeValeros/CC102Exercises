#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream inputFile("NUMS.TXT");
    int number;
    int count = 0;

    if (!inputFile) {
        cout << "File not found!" << endl;
        return 1;
    }

    while (inputFile >> number) {
        if (number >= 2) {
            bool isPrime = true;
            int limit = sqrt(number);

            for (int i = 2; i <= limit; i++) {
                if (number % i == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                count++;
            }
        }
    }

    cout << "Total prime numbers: " << count << endl;

    inputFile.close();
    return 0;
}
