// DERIVED CLASS: Company inherits from User
class company : public User {
private:
    int id;
    string companyName;
    string industry;
    string location;

public:
    void getCompanyData() {
        cout << "\n========================================" << endl;
        cout << "              ADD COMPANY               " << endl;
        cout << "========================================" << endl;
        
        cout << "Enter Company ID: ";
        cin >> id;
        
        cout << "Enter Company Name: ";
        cin >> ws;
        getline(cin, companyName);
        for (int i = 0; i < companyName.length(); i++) {
            if (companyName[i] == ' ') companyName[i] = '_';
        }

        cout << "Enter Industry: ";
        cin >> industry;
        
        cout << "Enter Location: ";
        cin >> location;

        cout << "Enter Company Email: ";
        cin >> email;
        
        cout << "Set Password for Company: ";
        password = getMaskedPassword();
    }

    void displayCompanyData() {
        string displayName = companyName;
        for (int i = 0; i < displayName.length(); i++) {
            if (displayName[i] == '_') displayName[i] = ' ';
        }
        cout << id << "\t" << displayName << "\t\t" << industry << "\t" << location << "\t" << email << endl;
    }

    void saveToFile() {
        ofstream file("data/company.txt", ios::app);
        if (!file) {
            cout << "\nError saving to data/company.txt!" << endl;
            return;
        }
        file << id << " " << companyName << " " << industry << " " << location << " " << email << " " << password << "\n";
        file.close();
        cout << "\nCompany Added Successfully!" << endl;
    }

    void viewAllCompanies() {
        ifstream file("data/company.txt");
        if (!file) {
            cout << "\nNo company records found!" << endl;
            return;
        }

        cout << "\n==========================================================================" << endl;
        cout << "ID\tCompany Name\tIndustry\tLocation\tEmail" << endl;
        cout << "==========================================================================" << endl;

        while (file >> id >> companyName >> industry >> location >> email >> password) {
            displayCompanyData();
        }

        file.close();
        cout << "==========================================================================" << endl;
    }

    bool login() override {
        cout << "\n========================================" << endl;
        cout << "             COMPANY LOGIN              " << endl;
        cout << "========================================" << endl;

        cout << "Enter Company Email: ";
        cin >> email;
        
        cout << "Enter Password: ";
        password = getMaskedPassword();

        ifstream file("data/company.txt");
        if (!file) {
            cout << "\nError: No company records exist!" << endl;
            return false;
        }

        int fId;
        string fName, fIndustry, fLocation, fEmail, fPass;

        while (file >> fId >> fName >> fIndustry >> fLocation >> fEmail >> fPass) {
            if (email == fEmail && password == fPass) {
                file.close();
                id = fId;
                companyName = fName;
                industry = fIndustry;
                location = fLocation;
                
                string displayName = companyName;
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
            cout << "           COMPANY DASHBOARD            " << endl;
            cout << "========================================" << endl;
            cout << "1. View Company Profile" << endl;
            cout << "2. Create Placement Drive" << endl;
            cout << "3. View Applications" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string displayName = companyName;
                    for (int i = 0; i < displayName.length(); i++) {
                        if (displayName[i] == '_') displayName[i] = ' ';
                    }
                    cout << "\n--- COMPANY PROFILE ---" << endl;
                    cout << "ID: " << id << endl;
                    cout << "Name: " << displayName << endl;
                    cout << "Industry: " << industry << endl;
                    cout << "Location: " << location << endl;
                    cout << "Email: " << email << endl;
                    break;
                }
                case 2:
                    cout << "\n[Create Drive Coming Soon]" << endl;
                    break;
                case 3:
                    cout << "\n[View Applications Coming Soon]" << endl;
                    break;
                case 4:
                    cout << "\nLogging out..." << endl;
                    break;
                default:
                    cout << "\nInvalid Choice! Try again." << endl;
            }
        } while (choice != 4);
    }
};