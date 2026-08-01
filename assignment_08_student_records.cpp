// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateStudentAverage(const Student& student) {
    if (student.scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    while (!(cin >> newStudent.id)) {
        cout << "Invalid ID. Please enter a valid integer ID: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int scoreCount;
    cout << "How many scores? ";
    while (!(cin >> scoreCount) || scoreCount < 0) {
        cout << "Please enter a valid positive number for score count: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    for (int i = 0; i < scoreCount; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> score)) {
            cout << "Invalid score. Enter a numeric score: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully.\n";
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n=========================================================================\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(25) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "-------------------------------------------------------------------------\n";

    for (const auto& student : students) {
        string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); i++) {
            scoresStr += to_string((int)student.scores[i]); 
            if (i < student.scores.size() - 1) scoresStr += ", ";
        }
        if (scoresStr.empty()) scoresStr = "N/A";

        double avg = calculateStudentAverage(student);

        cout << left << setw(20) << student.name
             << setw(12) << student.id
             << setw(25) << scoresStr
             << setw(10) << avg << endl;
    }
    cout << "=========================================================================\n";
}

void calculateSpecificAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }

    int targetID;
    cout << "Enter student ID: ";
    if (!(cin >> targetID)) {
        cout << "Invalid input. Returning to menu.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    bool found = false;
    for (const auto& student : students) {
        if (student.id == targetID) {
            double avg = calculateStudentAverage(student);
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << avg << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student with ID " << targetID << " not found.\n";
    }
}

void displayMenu() {
    cout << "\n================================\n";
    cout << "   STUDENT RECORD SYSTEM MENU\n";
    cout << "================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateSpecificAverage(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                break;
        }
    }

    return 0;
}