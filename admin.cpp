#include "user.cpp"

// DERIVED CLASS: Admin inherits from User
class admin : public User {
private:
    string username;

public:
    bool login() override {
        string user, pass;
        
        cout << "\n========================================" << endl;
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
        cout << "\n[Student Management module loading...]" << endl;
    }

    void companyManagement() {
        cout << "\n[Company Management module loading...]" << endl;
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
                case 4:
                case 5:
                case 6:
                case 7:
                    cout << "\n[Module under development for Phase 2]" << endl;
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