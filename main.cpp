#include "user.cpp"

int main() {
    int choice;

    do {
        cout << "\n========================================" << endl;
        cout << "            PLACEMENT BOARD             " << endl;
        cout << "  COLLEGE PLACEMENT MANAGEMENT SYSTEM   " << endl;
        cout << "========================================" << endl;
        cout << "1. Admin Login (Coming Soon)" << endl;
        cout << "2. Student Login (Coming Soon)" << endl;
        cout << "3. Company Login (Coming Soon)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
                cout << "\nModule under implementation by team..." << endl;
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