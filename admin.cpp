#include "user.cpp"
#include "company.cpp"
#include "student.cpp"

// DERIVED CLASS: Admin inherits from User
class admin : public User {
private:
    string username;

public:
    bool login() override {
        string user, pass;
        
        cout << "========================================" << endl;
        cout << "              ADMIN LOGIN               " << endl;
        cout << "========================================" << endl;
        
        cout << "Enter Username: ";
        cin >> user;
        
        cout << "Enter Password: ";
        pass = getMaskedPassword();

        ifstream file("data/admin.txt");
        if (!file) {
            cout << "\nError: data/admin.txt file not found!" << endl;
            return false;
        }

        string fileUser, filePass;
        while (file >> fileUser >> filePass) {
            if (user == fileUser && pass == filePass) {
                file.close();
                cout << "\nLogin Successful!" << endl;
                return true;
            }
        }

        file.close();
        cout << "\nInvalid Username or Password!" << endl;
        return false;
    }

    void studentManagement() {
        int choice, targetId;
        student s;
        do {
            cout << "\n========================================" << endl;
            cout << "          STUDENT MANAGEMENT            " << endl;
            cout << "========================================" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. View All Students" << endl;
            cout << "3. Update Student" << endl;
            cout << "4. Delete Student" << endl;
            cout << "5. Back" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    s.getStudentData();
                    s.saveToFile();
                    break;
                case 2:
                    s.viewAllStudents();
                    break;
                case 3:
                    cout << "Enter Student ID to Update: ";
                    cin >> targetId;
                    s.updateStudent(targetId);
                    break;
                case 4:
                    cout << "Enter Student ID to Delete: ";
                    cin >> targetId;
                    s.deleteStudent(targetId);
                    break;
                case 5:
                    break;
                default:
                    cout << "\nInvalid Choice! Try again." << endl;
            }
        } while (choice != 5);
    }

    void companyManagement() {
        int choice, targetId;
        company c;
        do {
            cout << "\n========================================" << endl;
            cout << "          COMPANY MANAGEMENT            " << endl;
            cout << "========================================" << endl;
            cout << "1. Add Company" << endl;
            cout << "2. View All Companies" << endl;
            cout << "3. Update Company" << endl;
            cout << "4. Delete Company" << endl;
            cout << "5. Back" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    c.getCompanyData();
                    c.saveToFile();
                    break;
                case 2:
                    c.viewAllCompanies();
                    break;
                case 3:
                    cout << "Enter Company ID to Update: ";
                    cin >> targetId;
                    c.updateCompany(targetId);
                    break;
                case 4:
                    cout << "Enter Company ID to Delete: ";
                    cin >> targetId;
                    c.deleteCompany(targetId);
                    break;
                case 5:
                    break;
                default:
                    cout << "\nInvalid Choice! Try again." << endl;
            }
        } while (choice != 5);
    }

    void showDashboard() {
        int choice;
        
        do {
            cout << "\n========================================" << endl;
            cout << "            ADMIN DASHBOARD             " << endl;
            cout << "========================================" << endl;
            cout << "1. Student Management" << endl;
            cout << "2. Company Management" << endl;
            cout << "3. Placement Drive Management" << endl;
            cout << "4. Application Management" << endl;
            cout << "5. Selection Management" << endl;
            cout << "6. Reports" << endl;
            cout << "7. Search" << endl;
            cout << "8. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    studentManagement();
                    break;
                case 2:
                    companyManagement();
                    break;
                case 3:
                    cout << "\n[Placement Drive Management Coming Soon]" << endl;
                    break;
                case 4:
                    cout << "\n[Application Management Coming Soon]" << endl;
                    break;
                case 5:
                    cout << "\n[Selection Management Coming Soon]" << endl;
                    break;
                case 6:
                    cout << "\n[Reports Coming Soon]" << endl;
                    break;
                case 7:
                    cout << "\n[Search Coming Soon]" << endl;
                    break;
                case 8:
                    cout << "\nLogging out..." << endl;
                    break;
                default:
                    cout << "\nInvalid Choice! Try again." << endl;
            }
        } while (choice != 8);
    }
};