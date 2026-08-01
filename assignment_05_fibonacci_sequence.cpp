// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
#include <iostream>
using namespace std;

void printFibonacciTerms(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    long long first = 0;
    long long second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << first;
        } else if (i == 2) {
            cout << " " << second;
        } else {
            long long next = first + second;
            cout << " " << next;
            first = second;
            second = next;
        }
    }
    cout << endl;
}

bool isFibonacciNumber(long long target) {
    if (target < 0) {
        return false;
    }

    long long first = 0;
    long long second = 1;

    if (target == first || target == second) {
        return true;
    }

    long long next = first + second;

    while (next <= target) {
        if (next == target) {
            return true;
        }
        first = second;
        second = next;
        next = first + second;
    }

    return false;
}

int main() {
    int n;
    cout << "How many terms? ";
    cin >> n;

    printFibonacciTerms(n);

    cout << endl;

    long long checkNum;
    cout << "Enter a number to check: ";
    cin >> checkNum;

    if (isFibonacciNumber(checkNum)) {
        cout << checkNum << " is a Fibonacci number." << endl;
    } else {
        cout << checkNum << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}