#include <iostream>

using namespace std;

struct userData {
    string name;
    int regNo;
    string program;
    int courses;
    int *marks = new int(courses);
    float SGPA = 0;
    void sgpa() {
        int gpa = 0;
        for (int i = 0; i < courses; i++) {
            if (marks[i] >= 86)
                gpa = 4;
            else if (marks[i] < 86 && marks[i] >= 82)
                gpa = 3.67;
            else if (marks[i] < 82 && marks[i] >= 78)
                gpa = 3.33;
            else if (marks[i] < 78 && marks[i] >= 72)
                gpa = 3;
            else if (marks[i] < 72 && marks[i] >= 68)
                gpa = 2.67;
            else if (marks[i] < 68 && marks[i] >= 62)
                gpa = 2.33;
            else if (marks[i] < 62 && marks[i] >= 58)
                gpa = 2;
            else
                gpa = 0;

            SGPA += (gpa*3) / (courses*3);
        }
        SGPA = SGPA / courses;
    }
};

int main() {
    userData studs[3];

    for ( int i = 0; i < 3; i++) {
        cout << "Enter the data for student " << i+1 << endl;
        cout << "Enter the name of student: ";
        cin >> studs[i].name;
        cout << "Enter the reg no. : ";
        cin >> studs[i].regNo;
        cout << "Enter the program: ";
        cin >> studs[i].program;
        cout << "Enter the total number of courses: ";
        cin >> studs[i].courses;
        cout << "Enter the marks: \n";
        for (int j = 0; j < studs[i].courses; j++) {
            cout << "Enter the marks for subject " << j+1 << ": ";
            cin >> studs[i].marks[j];
        }
        studs[i].sgpa();
    }

    for ( int i = 0; i < 3; i++) {
        cout << i+1 << "\t" << studs[i].name << "\t" << studs[i].regNo << "\t" << studs[i].program << "\t" << studs[i].SGPA << endl;
    }
}