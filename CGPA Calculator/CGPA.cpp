#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int numCourses;

    // Get the number of courses
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Arrays to store credits and grades for each course
    int credits[numCourses];
    char grades[numCourses];

    // Variables to store total credits and total grade points
    int totalCredits = 0;
    int totalGradePoints = 0;

    // Input grades and credits for each course
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter credits for course " << i + 1 << ": ";
        cin >> credits[i];

        cout << "Enter grade (A, B, C, D, F) for course " << i + 1 << ": ";
        cin >> grades[i];

        // Convert grade to grade points
        int gradePoints;
        switch (grades[i]) {
            case 'A': gradePoints = 4; 
            break;

            case 'B': gradePoints = 3; 
            break;

            case 'C': gradePoints = 2; 
            break;

            case 'D': gradePoints = 1; 
            break;

            case 'F': gradePoints = 0; 
            break;

            default:  gradePoints = 0; 
            break;
        }

        // Calculate total credits and total grade points
        totalCredits += credits[i];
        totalGradePoints += (credits[i] * gradePoints);
    }

    // Calculate GPA for the semester
    double semesterGPA = static_cast<double>(totalGradePoints) / totalCredits;

    // Output individual grades, total credits, GPA for the semester, and CGPA
    cout << "\nIndividual grades and credits:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": " << "Credits - " << credits[i] << ", Grade - " << grades[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "GPA for the Semester: " << fixed << setprecision(2) << semesterGPA << endl;

    // CGPA is not typically calculated within a single semester. For CGPA calculation,
    // you would need to maintain cumulative total credits and cumulative total grade points
    // over multiple semesters. You can then divide the cumulative total grade points by the
    // cumulative total credits to get the CGPA.

    return 0;
}

// Demonsration

// Enter the number of courses: 2
// Enter credits for course 1: 3
// Enter grade (A, B, C, D, F) for course 1: A
// Enter credits for course 2: 4
// Enter grade (A, B, C, D, F) for course 2: B

// Individual grades and credits:
// Course 1: Credits - 3, Grade - A
// Course 2: Credits - 4, Grade - B

// Total Credits: 7
// GPA for the Semester: 3.43
