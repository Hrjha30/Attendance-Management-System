#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function to take attendance for a specific day
void takeAttendance(string date) {
    ofstream outfile;
    outfile.open(date + ".txt");
    if (!outfile.is_open()) {
        cout << "Error creating file" << endl;
        return;
    }
    
    string name;
    char present;
    while (true) {
        cout << "Enter student name (enter 'done' to finish): ";
        cin >> name;
        if (name == "done") {
            break;
        }
        cout << "Is " << name << " present? (y/n): ";
        cin >> present;
        outfile << name << "," << present << endl;
    }
    outfile.close();
    cout << "Attendance taken for " << date << endl;
}

// Function to check attendance for a specific day
void checkAttendance(string date) {
    ifstream infile;
    infile.open(date + ".txt");
    if (!infile.is_open()) {
        cout << "Attendance for " << date << " has not been taken" << endl;
        return;
    }
    
    string line;
    while (getline(infile, line)) {
        string name;
        char present;
        int commaPos = line.find(",");
        name = line.substr(0, commaPos);
        present = line[commaPos + 1];
        cout << name << " is " << (present == 'y' ? "present" : "absent") << endl;
    }
    infile.close();
}

int main() {
    while (true) {
        int choice;
        cout << "Enter 1 to take attendance, 2 to check attendance, or 0 to quit: ";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            string date;
            cout << "Enter date for attendance (DDMMYYYY): ";
            cin >> date;
            takeAttendance(date);
        }
        else if (choice == 2) {
            string date;
            cout << "Enter date to check attendance (DDMMYYYY): ";
            cin >> date;
            checkAttendance(date);
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
