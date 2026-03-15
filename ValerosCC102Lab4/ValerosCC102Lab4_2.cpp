#include <iostream>
#include <vector>
#include <string>    
#include <cstdlib>
#include <cctype>

using namespace std;

int main() {
    char choice;
    
    do {
        system("cls");
        
        // Data Structures
        vector<vector<double>> sales(5, vector<double>(4, 0.0));
        vector<double> colTotals(4, 0.0);
        int salesperson, product;
        double amount;
        double grandTotal = 0;

        cout << "\n--- Monthly Sales Data Entry ---" << endl;
        cout << "Enter 0 for Salesperson to stop." << endl;

        // --- Data Input Phase ---
        while (true) {
            cout << "Salesperson (1-4): ";
            cin >> salesperson;
            if (salesperson == 0) break;

            cout << "Product (1-5): ";
            cin >> product;
            
            cout << "Amount: ";
            cin >> amount;

            // Validation and accumulation (Adjusting for 0-based indexing)
            if (salesperson >= 1 && salesperson <= 4 && product >= 1 && product <= 5) {
                sales[product - 1][salesperson - 1] += amount;
            } else {
                cout << "Invalid input! Please use Salesperson 1-4 and Product 1-5." << endl;
            }
            cout << "-----------------------" << endl;
        }

        // --- Report Generation Phase ---
        cout.setf(ios::fixed);
        cout.precision(2);

        cout << "\nProd\tSP 1\tSP 2\tSP 3\tSP 4\tTotal" << endl;
        cout << endl;
        
        

        for (int i = 0; i < 5; ++i) {
            double rowTotal = 0;
            cout << (i + 1) << "\t"; // Product number
            
            for (int j = 0; j < 4; ++j) {
                cout << sales[i][j] << "\t";
                rowTotal += sales[i][j];
                colTotals[j] += sales[i][j];
            }
            
            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        // --- Footer Totals ---
        cout << endl;
        cout << "Total\t";
        for (double total : colTotals) {
            cout << total << "\t";
        }
        cout << grandTotal << " (GT)" << endl;
            
        cout << "\nRun again? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    return 0;
}
