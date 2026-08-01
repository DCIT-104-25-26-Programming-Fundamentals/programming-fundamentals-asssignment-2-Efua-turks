// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
#include <iostream>
using namespace std;

void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i;
        if (i < 10) cout << " "; 
        cout << "  =  " << (num * i) << endl;
    }
}

void printTablesUpToN(int n) {
    for (int i = 1; i <= n; i++) {
        printTable(i);
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num <= 0) {
        cout << "Error: Input must be a positive integer." << endl;
        return 1;
    }

    printTable(num);

    cout << "\n===========================================\n" << endl;

    int n;
    cout << "Enter a number N to generate tables from 1 to N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Input N must be a positive integer." << endl;
        return 1;
    }

    printTablesUpToN(n);

    return 0;
}