#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int calculateGradePoint(const string& grade)
{
    if (grade == "AA")
    return 10;
    else if (grade == "AB")
    return 9;
    else if (grade == "BB")
    return 8;
    else if (grade == "BC")
    return 7;
    else if (grade == "CC")
    return 6;
    else if (grade == "CD")
    return 5;
    else if (grade == "DD")
    return 4;
    else return 0;
}

string calculateGrade(float marks)
{
    if (marks >= 80) return "AA";
    else if (marks >= 73) return "AB";
    else if (marks >= 66) return "BB";
    else if (marks >= 60) return "BC";
    else if (marks >= 55) return "CC";
    else if (marks >= 50) return "CD";
    else if (marks >= 45) return "DD";
    else return "FF";
}

void inputMarks(const string& subjectName, float& theoryMarks, float& practicalMarks, int& theoryCredit, int& practicalCredit)
{
    cout << "Enter marks for " << subjectName << " (Theory): ";
    cin >> theoryMarks;
    cout << "Enter marks for " << subjectName << " (Practical): ";
    cin >> practicalMarks;
    cout << "Enter credit for " << subjectName << " (Theory): ";
    cin >> theoryCredit;
    cout << "Enter credit for " << subjectName << " (Practical): ";
    cin >> practicalCredit;
}

void displayMarksheet(const string& studentId, const string& studentName, int semester, const string subjects[], const float theoryMarks[], const float practicalMarks[]) {
    cout << "\n\n** Marksheet **\n";
    cout << "Student ID: " << studentId << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Semester: " << semester << endl;

    cout << "\nSubject\t\tGrade (Theory)\tGrade (Practical)\n";
    cout << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < 3; ++i) {
        string gradeTheory = calculateGrade(theoryMarks[i]);
        string gradePractical = calculateGrade(practicalMarks[i]);

        cout << setw(15) << left << subjects[i] << "\t" << setw(10) << right << gradeTheory << "\t\t\t" << setw(10) << right << gradePractical << endl;
    }
}

float calculateCGPA(int theoryCredit[], int practicalCredit[], int theoryGradePoint[], int practicalGradePoint[])
{
    int totalCredit = 0;
    float totalGradePoint = 0;

    for (int i = 0; i < 3; ++i) {
        totalCredit += theoryCredit[i] + practicalCredit[i];
        totalGradePoint += theoryGradePoint[i] * theoryCredit[i] + practicalGradePoint[i] * practicalCredit[i];
    }

    return totalGradePoint / totalCredit;
}

int main()
{
    string studentId, studentName;
    int semester;
    string subjects[3];
    float theoryMarks[3], practicalMarks[3];
    int theoryCredit[3], practicalCredit[3];
    int theoryGradePoint[3], practicalGradePoint[3];

    cout << "Enter Student ID: ";
    cin >> studentId;
    cout << "Enter Student Name: ";
    cin >> studentName;
    cout << "Enter Semester (1 to 8): ";
    cin >> semester;

    for (int i = 0; i < 3; ++i) {
        cout << "Enter name of Subject " << i + 1 << ": ";
        cin >> subjects[i];
    }

    for (int i = 0; i < 3; ++i)
        {
        inputMarks(subjects[i], theoryMarks[i], practicalMarks[i], theoryCredit[i], practicalCredit[i]);
        theoryGradePoint[i] = calculateGradePoint(calculateGrade(theoryMarks[i]));
        practicalGradePoint[i] = calculateGradePoint(calculateGrade(practicalMarks[i]));
    }

    displayMarksheet(studentId, studentName, semester, subjects, theoryMarks, practicalMarks);

    float cgpa = calculateCGPA(theoryCredit, practicalCredit, theoryGradePoint, practicalGradePoint);

    cout << "\nCGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
