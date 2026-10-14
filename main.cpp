#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

int readNumber(const string& prompt, int minimum, int maximum) {
    int number;
    while (true) {
        cout << prompt;
        if (cin >> number && number >= minimum && number <= maximum) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
        cout << "Invalid input. Enter a number from " << minimum
             << " to " << maximum << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void viewStudents(const string names[], const int scores[], int count) {
    if (count == 0) {
        cout << "No students added yet.\n";
        return;
    }
    cout << "\n" << left << setw(6) << "No." << setw(26) << "Name" << "Score\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(6) << (i + 1) << setw(26) << names[i]
             << scores[i] << "\n";
    }
}

void calculateResults(const string names[], const int scores[], int count) {
    if (count == 0) {
        cout << "Add students before calculating results.\n";
        return;
    }
    int total = 0;
    int highestIndex = 0;
    int lowestIndex = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
        if (scores[i] > scores[highestIndex]) highestIndex = i;
        if (scores[i] < scores[lowestIndex]) lowestIndex = i;
    }
    cout << "\n--- RESULTS SUMMARY ---\n";
    cout << "Number of students: " << count << "\n";
    cout << "Total score: " << total << "\n";
    cout << fixed << setprecision(2);
    cout << "Average score: " << static_cast<double>(total) / count << "\n";
    cout << "Highest score: " << scores[highestIndex] << " (" << names[highestIndex] << ")\n";
    cout << "Lowest score: " << scores[lowestIndex] << " (" << names[lowestIndex] << ")\n";
}

int main() {
    // Parallel arrays: the name and score at the same index belong to one student.
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS];
    int count = 0;

    while (true) {
        cout << "\n========================================\n";
        cout << " STUDENT RESULTS MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Add student\n";
        cout << "2. View students\n";
        cout << "3. Calculate results\n";
        cout << "4. Search student\n";
        cout << "5. Delete student\n";
        cout << "6. Exit\n";
        int choice = readNumber("Enter your choice (1-6): ", 1, 6);

        if (choice == 1) {
            if (count == MAX_STUDENTS) {
                cout << "The array is full (100 students).\n";
                continue;
            }
            string name;
            do {
                cout << "Enter student name: ";
                getline(cin, name);
                if (name.empty()) cout << "Name cannot be empty.\n";
            } while (name.empty());
            int score = readNumber("Enter examination score (0-100): ", 0, 100);
            names[count] = name;
            scores[count] = score;
            count++;
            cout << "Student added successfully!\n";
        } else if (choice == 2) {
            viewStudents(names, scores, count);
        } else if (choice == 3) {
            calculateResults(names, scores, count);
        } else if (choice == 4) {
            cout << "Enter student name to search: ";
            string search;
            getline(cin, search);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (names[i] == search) {
                    cout << names[i] << " - Score: " << scores[i] << "\n";
                    found = true;
                }
            }
            if (!found) cout << "No student found with that name (check spelling/capitalisation).\n";
        } else if (choice == 5) {
            viewStudents(names, scores, count);
            if (count == 0) continue;
            int position = readNumber("Enter student number to delete: ", 1, count) - 1;
            for (int i = position; i < count - 1; i++) {
                names[i] = names[i + 1];
                scores[i] = scores[i + 1];
            }
            count--;
            cout << "Student deleted successfully!\n";
        } else {
            cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}
