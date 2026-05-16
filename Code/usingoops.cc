#include <iostream>
#include <fstream>
using namespace std;

class Student {
protected:
    string name;
    int roll;

public:
    void getStudentData() {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> roll;
    }
};

class Result : public Student {
private:
    int marks[5];
    int total = 0;
    float percentage;
    char grade;

public:
    void getMarks() {
        cout << "\nEnter Marks of 5 Subjects:\n";

        for(int i = 0; i < 5; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
            total = total + marks[i];
        }
    }

    void calculate() {
        percentage = total / 5.0;

        if(percentage >= 90)
            grade = 'A';
        else if(percentage >= 75)
            grade = 'B';
        else if(percentage >= 50)
            grade = 'C';
        else
            grade = 'F';
    }

    void display() {
        cout << "\n----- RESULT -----\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;

        if(grade == 'F')
            cout << "Status: Fail\n";
        else
            cout << "Status: Pass\n";
    }

    void saveToFile() {
        ofstream file("student_result.txt", ios::app);

        file << "----- RESULT -----\n";
        file << "Name: " << name << endl;
        file << "Roll No: " << roll << endl;
        file << "Marks: ";

        for(int i = 0; i < 5; i++) {
            file << marks[i] << " ";
        }

        file << "\nTotal: " << total << endl;
        file << "Percentage: " << percentage << "%" << endl;
        file << "Grade: " << grade << endl;

        if(grade == 'F')
            file << "Status: Fail\n";
        else
            file << "Status: Pass\n";

        file << "----------------------\n\n";

        file.close();

        cout << "\nData Saved in student_result.txt file";
    }
};

int main() {
    Result r;

    r.getStudentData();
    r.getMarks();
    r.calculate();
    r.display();
    r.saveToFile();

    return 0;
}