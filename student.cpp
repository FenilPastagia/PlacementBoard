#include "user.cpp"

// DERIVED CLASS: Student inherits from User
class student : public User {
private:
    int id;
    string name;
    string course;
    float cgpa;
    int backlogs;

public:
    void getStudentData() {
        cout << "\n========================================" << endl;
        cout << "              ADD STUDENT               " << endl;
        cout << "========================================" << endl;

        cout << "Enter Student ID: ";
        cin >> id;

        cout << "Enter Full Name: ";
        cin >> ws;
        getline(cin, name);

        for (int i = 0; i < name.length(); i++) {
            if (name[i] == ' ') {
                name[i] = '_';
            }
        }

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Course (e.g. MCA/BCA): ";
        cin >> course;

        cout << "Enter CGPA: ";
        cin >> cgpa;

        cout << "Enter Active Backlogs: ";
        cin >> backlogs;

        cout << "Set Password for Student: ";
        password = getMaskedPassword();
    }

    void displayStudentData() {
        string displayName = name;
        for (int i = 0; i < displayName.length(); i++) {
            if (displayName[i] == '_') {
                displayName[i] = ' ';
            }
        }
        cout << id << "\t" << displayName << "\t\t" << email << "\t" << course << "\t" << cgpa << "\t" << backlogs << endl;
    }

    void saveToFile() {
        ofstream file("data/student.txt", ios::app);
        if (!file) {
            cout << "\nError saving to data/student.txt!" << endl;
            return;
        }

        file << id << " " << name << " " << email << " " << course << " " << cgpa << " " << backlogs << " " << password << "\n";
        file.close();
        cout << "\nStudent Added Successfully!" << endl;
    }

    void viewAllStudents() {
        ifstream file("data/student.txt");
        if (!file) {
            cout << "\nNo student records found!" << endl;
            return;
        }

        cout << "\n==========================================================================" << endl;
        cout << "ID\tName\t\tEmail\t\tCourse\tCGPA\tBacklogs" << endl;
        cout << "==========================================================================" << endl;

        while (file >> id >> name >> email >> course >> cgpa >> backlogs >> password) {
            displayStudentData();
        }

        file.close();
        cout << "==========================================================================" << endl;
    }

    bool login() override {
        cout << "\n========================================" << endl;
        cout << "             STUDENT LOGIN              " << endl;
        cout << "========================================" << endl;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Password: ";
        password = getMaskedPassword();

        ifstream file("data/student.txt");
        if (!file) {
            cout << "\nError: No student records exist!" << endl;
            return false;
        }

        int fId, fBacklogs;
        string fName, fEmail, fCourse, fPass;
        float fCgpa;

        while (file >> fId >> fName >> fEmail >> fCourse >> fCgpa >> fBacklogs >> fPass) {
            if (email == fEmail && password == fPass) {
                file.close();
                id = fId;
                name = fName;
                course = fCourse;
                cgpa = fCgpa;
                backlogs = fBacklogs;

                string displayName = name;
                for (int i = 0; i < displayName.length(); i++) {
                    if (displayName[i] == '_') displayName[i] = ' ';
                }

                cout << "\nLogin Successful! Welcome, " << displayName << endl;
                return true;
            }
        }

        file.close();
        cout << "\nInvalid Email or Password!" << endl;
        return false;
    }

    void showDashboard() {
        int choice;

        do {
            cout << "\n========================================" << endl;
            cout << "           STUDENT DASHBOARD            " << endl;
            cout << "========================================" << endl;
            cout << "1. View My Profile" << endl;
            cout << "2. View Placement Drives" << endl;
            cout << "3. Apply for Placement" << endl;
            cout << "4. My Applications" << endl;
            cout << "5. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string displayName = name;
                    for (int i = 0; i < displayName.length(); i++) {
                        if (displayName[i] == '_') displayName[i] = ' ';
                    }

                    cout << "\n--- MY PROFILE ---" << endl;
                    cout << "ID: " << id << endl;
                    cout << "Name: " << displayName << endl;
                    cout << "Email: " << email << endl;
                    cout << "Course: " << course << endl;
                    cout << "CGPA: " << cgpa << endl;
                    cout << "Backlogs: " << backlogs << endl;
                    break;
                }
                case 2:
                    cout << "\n[Placement Drives Coming Soon]" << endl;
                    break;
                case 3:
                    cout << "\n[Apply Module Coming Soon]" << endl;
                    break;
                case 4:
                    cout << "\n[My Applications Coming Soon]" << endl;
                    break;
                case 5:
                    cout << "\nLogging out..." << endl;
                    break;
                default:
                    cout << "\nInvalid Choice! Try again." << endl;
            }
        } while (choice != 5);
    }
};
