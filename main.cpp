#include "admin.cpp"

int main() {
    admin a;
    student s;
    int choice;

    do {
        cout << "\n========================================" << endl;
        cout << "            PLACEMENT BOARD             " << endl;
        cout << "  COLLEGE PLACEMENT MANAGEMENT SYSTEM   " << endl;
        cout << "========================================" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Student Login" << endl;
        cout << "3. Company Login" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (a.login()) {
                    a.showDashboard();
                }
                break;
            case 2:
                if (s.login()) {
                    s.showDashboard();
                }
                break;
            case 3:
                cout << "\n[Company module being pushed by Member 3]" << endl;
                break;
            case 4:
                cout << "\nThank You!" << endl;
                break;
            default:
                cout << "\nInvalid Choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}