#include <iostream>
#include <string> // Προσθήκη βιβλιοθήκης για χρήση string

using namespace std;

struct Student {
    string name; // Προσθήκη πεδίου για το όνομα του μαθητή
    float grapth;
    float proforikh;
    float finalgrade;
};

float calculateAverage(float grapth, float proforikh) {
    return (grapth + proforikh) / 2.0;
}

void swapStudents(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

int main() {
    const int studentsCount = 10;
    Student students[studentsCount];

    for (int i = 0; i < studentsCount; ++i) {
        cout << "Student No. " << i+1 << endl;

        // Ζητάμε το όνομα του μαθητή
        cout << "Enter student's name: ";
        cin.ignore(); // Αγνοούμε τυχόν προηγούμενα newline characters
        getline(cin, students[i].name);

        do {
            cout << "Dwse vathmologia grapths eksetashs: ";
            cin >> students[i].grapth;
        } while (students[i].grapth < 0 || students[i].grapth > 100);

        do {
            cout << "Dwse vathmologia proforikhs eksetashs: ";
            cin >> students[i].proforikh;
        } while (students[i].proforikh < 0 || students[i].proforikh > 100);

        students[i].finalgrade = calculateAverage(students[i].grapth, students[i].proforikh);
    }

    for (int i = 0; i < studentsCount - 1; ++i) {
        for (int j = 0; j < studentsCount - i - 1; ++j) {
            if (students[j].finalgrade < students[j + 1].finalgrade) {
                swapStudents(students[j], students[j + 1]);
            }
        }
    }

    cout << "Students sorted by final grade (highest to lowest):" << endl;
    for (int i = 0; i < studentsCount; ++i) {
        cout << "Student Name: " << students[i].name << ", Final Grade: " << students[i].finalgrade << endl;
    }

    return 0;
}
