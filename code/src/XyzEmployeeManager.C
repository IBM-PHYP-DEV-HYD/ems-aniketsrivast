#include "XyzEmployeeManager.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmployee.H"
#include "EmployeeReportBuilder.H"

// Add new employee to EDLL
void XyzEmployeeManager::addEmployee(XyzEmployee* employeeParam){
    if(employeeParam->getEmployementStatus() == XyzEmployeeEnums::Resigned){
        XyzEmployee* sMinimalObject = new XyzEmployee();
        sMinimalObject->setEmployeeName(employeeParam->getEmployeeName());
        sMinimalObject->setEmployeeID(employeeParam->getEmployeeID());
        sMinimalObject->setEmployeeType(employeeParam->getEmployeeType());
        sMinimalObject->setEmployementStatus(XyzEmployeeEnums::Resigned);
        sMinimalObject->setEmployeeGender(employeeParam->getEmployeeGender());
        sMinimalObject->setEmployeeDOB(employeeParam->getEmployeeDOB());
        sMinimalObject->setEmployeeDOJ(employeeParam->getEmployeeDOJ());
        mResignedDLL.push_back(sMinimalObject);
        delete employeeParam;
    }
    else{
        mEmployeeDLL.push_back(employeeParam);
    }
}

// Remove Employee from Current employee and move to Resigned employees
bool XyzEmployeeManager::removeEmployee(string employeeIDParam){
    if (mEmployeeDLL.empty()) {
        cout << "No Active/Inactive employees exist.\n";
        return false;
    }

    int sEDLLSize = mEmployeeDLL.size();
    int sIndex = 0;
    for (sIndex = 0; sIndex < sEDLLSize; ++sIndex) {
        XyzEmployee* sTemp = mEmployeeDLL[sIndex];   // operator[] returns XyzEmployee*
        if (sTemp && sTemp->getEmployeeID() == employeeIDParam) {
            // prepare minimal resigned entry
            XyzEmployee* sResignedEmployee = new XyzEmployee();
            sResignedEmployee->setEmployeeName(sTemp->getEmployeeName());
            sResignedEmployee->setEmployeeID(sTemp->getEmployeeID());
            sResignedEmployee->setEmployeeType(sTemp->getEmployeeType());
            sResignedEmployee->setEmployementStatus(XyzEmployeeEnums::Resigned); // Resigned
            sResignedEmployee->setEmployeeGender(sTemp->getEmployeeGender());
            sResignedEmployee->setEmployeeDOB(sTemp->getEmployeeDOB());
            sResignedEmployee->setEmployeeDOJ(sTemp->getEmployeeDOJ());

            // push to resigned deque (resigned deque owns its pointers)
            mResignedDLL.push_back(sResignedEmployee);

            // remove from active deque — removeAt will also delete emp (since deque owns pointers)
            mEmployeeDLL.removeFromIndex(sIndex);

            cout << "Employee " << employeeIDParam << " removed and moved to resigned list.\n";
            return true;
        }
    }

    cout << "Employee with ID " << employeeIDParam << " not found in current employees.\n";
    return false;
}

// Print Full Time Employees
void XyzEmployeeManager::printFullTimeEmployees(){
    if (mEmployeeDLL.empty()) {
        cout << "No current employees" << endl;
        return;
    }
    bool sPrintedFlag = false;
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeType() == XyzEmployeeEnums::FullTime) {
            sEmployee->printEmployeeDetails();
            cout << "---------------------------------------------" << endl;
            sPrintedFlag = true;
        }
    }
    if (!sPrintedFlag) {
        cout << "No Full-Time employees found" << endl;
    }
}

// Print Contractor Employees
void XyzEmployeeManager::printContractorEmployees(){
    if (mEmployeeDLL.empty()) {
        cout << "No current employees" << endl;
        return;
    }
    bool sPrintedFlag = false;
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeType() == XyzEmployeeEnums::Contractor) {
            sEmployee->printEmployeeDetails();
            cout << "---------------------------------------------" << endl;
            sPrintedFlag = true;
        }
    }
    if (!sPrintedFlag) {
        cout << "No Contractor employees found" << endl;
    }
}

// Print Intern Employees
void XyzEmployeeManager::printInternEmployees(){
    if (mEmployeeDLL.empty()) {
        cout << "No current employees" << endl;
        return;
    }
    bool sPrintedFlag = false;
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeType() == XyzEmployeeEnums::Intern) {
            sEmployee->printEmployeeDetails();
            cout << "---------------------------------------------" << endl;
            sPrintedFlag = true;
        }
    }
    if (!sPrintedFlag) {
        cout << "No Intern employees found" << endl;
    }
}

// Print Male Employees
void XyzEmployeeManager::printMaleEmployees(){
    if (mEmployeeDLL.empty()) {
         cout << "No current employees\n"; 
         return; 
        }
    bool sPrintedFlag = false;
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeGender() == XyzEmployeeEnums::Male) {
            sEmployee->printEmployeeDetails(); 
            cout << "---------------------------------------------\n"; 
            sPrintedFlag = true;
        }
    }
    if (!sPrintedFlag) {
        cout << "No male employees \n";
    }
}

// Print Female Employees
void XyzEmployeeManager::printFemaleEmployees(){
    if (mEmployeeDLL.empty()) {
         cout << "No current employees\n"; 
         return; 
        }
    bool sPrintedFlag = false;
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeGender() == XyzEmployeeEnums::Female) {
            sEmployee->printEmployeeDetails(); 
            cout << "---------------------------------------------\n"; 
            sPrintedFlag = true;
        }
    }
    if (!sPrintedFlag) {
        cout << "No female employees \n";
    }
}

// Print Current (Active/Inactive) Employees
void XyzEmployeeManager::printCurrentEmployees(){
    mEmployeeDLL.printEDLL();
}

// Print Resigned Employees
void XyzEmployeeManager::printResignedEmployees(){
    mResignedDLL.printEDLL();
}

// Print All employees
void XyzEmployeeManager::printAllEmployees(){
    mEmployeeDLL.printEDLL();
    mResignedDLL.printEDLL();

}

// Print Employee by name
void XyzEmployeeManager::getEmployeeByName(string nameParam){
    bool sFoundFlag = false;
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeName() == nameParam) {
            sEmployee->printEmployeeDetails();
            cout << "---------------------------------------------" << endl;
            sFoundFlag = true;
        }
    }
    for (sIndex = 0; sIndex < mResignedDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mResignedDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeName() == nameParam) {
            sEmployee->printEmployeeDetails();
            cout << "---------------------------------------------" << endl;
            sFoundFlag = true;
        }
    }
    if (!sFoundFlag) {
        cout << "No employee found with name: " << nameParam << endl;
    }
}

// Print Employee by Employee ID
void XyzEmployeeManager::getEmployeeByID(string empIDParam){
    int sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeID() == empIDParam) {
            sEmployee->printEmployeeDetails();
            return;
        }
    }
    for (sIndex = 0; sIndex < mResignedDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mResignedDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeID() == empIDParam) {
            sEmployee->printEmployeeDetails();
            return;
        }
    }
    cout << "Employee ID " << empIDParam << " not found." << endl;
}

// Convert any employe to Full Time
bool XyzEmployeeManager::convertToFullTime(string employeeID){
     if (mEmployeeDLL.empty()) {
        cout << "No current employees exist.\n";
        return false;
    }

    int sDLLSize = mEmployeeDLL.size();
    int sIndex = 0;
    for (sIndex = 0; sIndex < sDLLSize; ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (sEmployee && sEmployee->getEmployeeID() == employeeID) {
            if (sEmployee->getEmployeeType() == XyzEmployeeEnums::FullTime) {
                cout << "Employee is already Full-Time.\n";
                return false;
            }
            // create new full-time employee and copy useful fields
            XyzFullTimeEmployee* sFullTimeEmployee = new XyzFullTimeEmployee();
            sFullTimeEmployee->setEmployeeName(sEmployee->getEmployeeName());
            sFullTimeEmployee->setEmployeeID(sEmployee->getEmployeeID());
            sFullTimeEmployee->setEmployeeGender(sEmployee->getEmployeeGender());
            sFullTimeEmployee->setEmployeeDOB(sEmployee->getEmployeeDOB());
            sFullTimeEmployee->setEmployeeDOJ(sEmployee->getEmployeeDOJ());
            sFullTimeEmployee->setEmployeeType(XyzEmployeeEnums::FullTime);
            sFullTimeEmployee->setEmployementStatus(sEmployee->getEmployementStatus());
            // initialize leaves (you may choose a rule; here we give full allotment)
            sFullTimeEmployee->updateLeavesLeft(STANDARD_LEAVES);

            // remove old (this deletes the old pointer because deque owns it)
            mEmployeeDLL.removeFromIndex(sIndex);
            // insert the new fte at the same position
            mEmployeeDLL.insertAtIndex(sFullTimeEmployee, sIndex);

            cout << "Converted " << employeeID << " to Full-Time.\n";
            return true;
        }
    }
    cout << "Employee ID " << employeeID << " not found for conversion.\n";
    return false;
}

// Add leaves to Full-Time employee
void XyzEmployeeManager::addLeaves(int leavesParam){
  if (mEmployeeDLL.empty()) {
        cout << "No current employees exist.\n";
        return;
    }
    int sCountFLag = 0, sIndex = 0;
    for (sIndex = 0; sIndex < mEmployeeDLL.size(); ++sIndex) {
        XyzEmployee* sEmployee = mEmployeeDLL[sIndex];
        if (!sEmployee) continue;
        XyzFullTimeEmployee* sFullTimeEmployee = dynamic_cast<XyzFullTimeEmployee*>(sEmployee);
        if (sFullTimeEmployee) {
            sFullTimeEmployee->updateLeavesLeft(leavesParam);
            ++sCountFLag;
        }
    }
    cout << "Added " << leavesParam << " leaves to " << sCountFLag << " Full-Time employees.\n";
}

// ID Generator
string XyzEmployeeManager::generateNextEmployeeID(char typeParam) {
    string sEmployeeID = "XYZ" + std::to_string(mNextNumericID) + string(1, typeParam);
    ++mNextNumericID;
    return sEmployeeID;
}

// Create Employee randomly
XyzEmployee* XyzEmployeeManager::createEmployeeRandom() {
    int sRandomType = (rand() % 3) + 1; // 1..3
    XyzEmployee* sEmployee = nullptr;
    char sTypeCode = (sRandomType == XyzEmployeeEnums::FullTime ? 'F' : (sRandomType == XyzEmployeeEnums::Contractor ? 'C' : 'I'));
    string sEmployeeID = generateNextEmployeeID(sTypeCode);

    if (sRandomType == XyzEmployeeEnums::FullTime) {
        XyzFullTimeEmployee* sFullTimeEmployee = new XyzFullTimeEmployee();
        sFullTimeEmployee->setEmployeeName("Random FullTime");
        sFullTimeEmployee->setEmployeeID(sEmployeeID);
        sFullTimeEmployee->setEmployeeType(XyzEmployeeEnums::FullTime);
        sFullTimeEmployee->setEmployementStatus(XyzEmployeeEnums::Active);
        sFullTimeEmployee->setEmployeeGender(XyzEmployeeEnums::Male);
        sFullTimeEmployee->setEmployeeDOB("1999-01-01");
        sFullTimeEmployee->setEmployeeDOJ("2024-01-01");
        sFullTimeEmployee->updateLeavesLeft(STANDARD_LEAVES);
        sEmployee = sFullTimeEmployee;
    } else if (sRandomType == XyzEmployeeEnums::Contractor) {
        XyzContractorEmployee* sContractor = new XyzContractorEmployee();
        sContractor->setEmployeeName("Random Contractor");
        sContractor->setEmployeeID(sEmployeeID);
        sContractor->setEmployeeType(XyzEmployeeEnums::Contractor);
        sContractor->setEmployementStatus(XyzEmployeeEnums::Active);
        sContractor->setEmployeeGender(XyzEmployeeEnums::Male);
        sContractor->setEmployeeDOB("1995-03-03");
        sContractor->setEmployeeDOJ("2024-02-15");
        sContractor->setAgency(1 + (rand()%3));
        sEmployee = sContractor;
    } else {
        XyzInternEmployee* sIntern = new XyzInternEmployee();
        sIntern->setEmployeeName("Random Intern");
        sIntern->setEmployeeID(sEmployeeID);
        sIntern->setEmployeeType(XyzEmployeeEnums::Intern);
        sIntern->setEmployementStatus(XyzEmployeeEnums::Active);
        sIntern->setEmployeeGender(XyzEmployeeEnums::Female);
        sIntern->setEmployeeDOB("2002-06-06");
        sIntern->setEmployeeDOJ("2024-07-01");
        sIntern->setCollege(1 + (rand()%7));
        sIntern->setBranch(1 + (rand()%3));
        sEmployee = sIntern;
    }
    return sEmployee;
}

// Create Employee manually
XyzEmployee* XyzEmployeeManager::createEmployeeFromInput() {
    cout << "Choose type: 1. Full-Time  2. Contractor  3. Intern\nYour choice: ";
    int sTypeChoice = XyzEmployeeEnums::FullTime;
    if (!(cin >> sTypeChoice)) {
        cin.clear(); 
        sTypeChoice = XyzEmployeeEnums::FullTime; 
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    XyzEmployee* sEmployee = nullptr;
    if (sTypeChoice == XyzEmployeeEnums::FullTime) {
        auto* sFullTimeEmployee = new XyzFullTimeEmployee();
        cin >> *sFullTimeEmployee; // expects operator>> for derived / base fields
        sFullTimeEmployee->setEmployeeID(generateNextEmployeeID('F'));
        sEmployee = sFullTimeEmployee;
    } else if (sTypeChoice == XyzEmployeeEnums::Contractor) {
        auto* sContractor = new XyzContractorEmployee();
        cin >> *sContractor;
        sContractor->setEmployeeID(generateNextEmployeeID('C'));
        sEmployee = sContractor;
    } else {
        auto* sIntern = new XyzInternEmployee();
        cin >> *sIntern;
        sIntern->setEmployeeID(generateNextEmployeeID('I'));
        sEmployee = sIntern;
    }
    return sEmployee;
}

// Read integer by ignoring any spaces or newlines present
int XyzEmployeeManager::readIntSafely() const {
    int sInput;
    while (!(cin >> sInput)) {
        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return sInput;
}

// Pause buffer in mid
void XyzEmployeeManager::pauseForEnter() const {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Main Employee Manager
void XyzEmployeeManager::mainMenu() {
    while (true) {
        cout << "---------------------------------------------------------------------------------\n";
        cout << "|                         Employee Management System                            |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "| 1. Add an Employee                                                            |\n";
        cout << "| 2. Remove an Employee                                                         |\n";
        cout << "| 3. Get Employee Details                                                       |\n";
        cout << "| 4. Do something else                                                          |\n";
        cout << "|    (Enter -1 to exit)                                                         |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Your Choice: ";
        int sInputChoice = readIntSafely();

        switch (sInputChoice) {
            case EMSMenu::AddMenu: 
            {
                subAddMenu(); 
                break;
            }

            case EMSMenu::RemoveMenu: 
            {
                cout << "Enter Employee ID to remove: ";
                string sInputEmployeeID; 
                getline(cin, sInputEmployeeID);
                if (sInputEmployeeID.empty()) {
                    getline(cin, sInputEmployeeID);
                }
                if (!sInputEmployeeID.empty()) {
                    removeEmployee(sInputEmployeeID);
                }
                else {
                    cout << "No ID entered.\n";
                }
                pauseForEnter();
                break;
            }

            case EMSMenu::DetailsMenu: 
            {
                subSummaryMenu(); 
                break;
            }

            case EMSMenu::OtherMenu: {
                subOthersMenu(); 
                break;
            }

            case EMSMenu::ExitMain:
            {
                cout << "Exiting...\n"; 
                return; 
            }

            default: 
            {
                cout << "Invalid input. Please try again\n";
                break;
            }
        }
    }
}

// Addition Sub Menu
void XyzEmployeeManager::subAddMenu() {
    while(true) {
        cout << "---------------------------------------------------------------------------------\n";
        cout << "|                         Employee Management System                            |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "| Add an Employee:                                                              |\n";
        cout << "|     1. Add an Employee at Random                                              |\n";
        cout << "|     2. Add an Employee (F/C/I)                                                |\n";
        cout << "|    (Enter -1 to go back to main menu)                                         |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Your choice: ";
        int sInputChoice = readIntSafely();

        switch(sInputChoice){
            case EMSMenu::AddRandom:
            {
                XyzEmployee* sEmployee = createEmployeeRandom();
                addEmployee(sEmployee);
                cout << "Random employee added.\n";
                pauseForEnter();                
            }
            break;

            case EMSMenu::AddManually:
            {
                XyzEmployee* sEmployee = createEmployeeFromInput();
                addEmployee(sEmployee);
                cout << "Employee added.\n";
                pauseForEnter();
            }
            break;

            case EMSMenu::ExitAdd:
            {
                return;
            }

            default: 
            {
                cout << "Invalid input. Please try again\n";
                break;
            }
        }
    }
}

void XyzEmployeeManager::subSummaryMenu() {
    while(true) {
        cout << "---------------------------------------------------------------------------------\n";
        cout << "|                         Employee Management System                            |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "| Get Employee details:                                                         |\n";
        cout << "|     1. All employees summary                                                  |\n";
        cout << "|     2. Employee summary (F/C/I)                                               |\n";
        cout << "|     3. Employee summary (M/F)                                                 |\n";
        cout << "|     4. Employee summary (A/I/R)                                               |\n";
        cout << "|     5. Display employee details                                               |\n";
        cout << "|    (Enter -1 to go back to previous menu)                                     |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Your choice: ";
        int sInputChoice = readIntSafely();

        if (sInputChoice == EMSMenu::ExitDetails) {
            return;
        }

        EmployeeReportBuilder sBuilder(*this); // start with default

        switch (sInputChoice) {
            case EMSMenu::AllDetails: {
                sBuilder.includeCurrent(true).includeResigned(true).clearFilters().print();
                break;
            }

            case EMSMenu::DetailsByType: {
                cout << "Choose Employee type: 1.Full-Time 2.Contractor 3.Intern\nChoice: ";
                int sInputType = readIntSafely();
                if (sInputType == XyzEmployeeEnums::FullTime ||
                    sInputType == XyzEmployeeEnums::Contractor ||
                    sInputType == XyzEmployeeEnums::Intern) {
                    sBuilder.includeCurrent(true).includeResigned(false).filterType(sInputType).print();
                } else {
                    cout << "Invalid type\n";
                }
                break;
            }

            case EMSMenu::DetailsByGender: {
                cout << "Choose gender: 1.Male 2.Female\nChoice: ";
                int sInputGender = readIntSafely();
                if (sInputGender == XyzEmployeeEnums::Male || sInputGender == XyzEmployeeEnums::Female) {
                    // include both current and resigned for gender view
                    sBuilder.includeCurrent(true).includeResigned(true).filterGender(sInputGender).print();
                } else {
                    cout << "Invalid gender\n";
                }
                break;
            }

            case EMSMenu::DetailsByStatus: {
                cout << "Choose status: 1.Active/2.Inactive/3.Resigned\nChoice: ";
                int sInputStatus = readIntSafely();
                if (sInputStatus == XyzEmployeeEnums::Active || sInputStatus == XyzEmployeeEnums::Inactive) {
                    // current deque contains active/inactive
                    sBuilder.includeCurrent(true).includeResigned(false).filterStatus(sInputStatus).print();
                }
                else if (sInputStatus == XyzEmployeeEnums::Resigned) {
                    sBuilder.includeCurrent(false).includeResigned(true).filterStatus(sInputStatus).print();
                }
                else {
                    cout << "Invalid status\n";
                }
                break;
            }

            case EMSMenu::DetailsByID: {
                cout << "Enter Employee ID to display details: ";
                string sEmployeeID; 
                getline(cin, sEmployeeID);
                if (sEmployeeID.empty()){
                    getline(cin, sEmployeeID);
                }
                if (!sEmployeeID.empty()) {
                    getEmployeeByID(sEmployeeID);
                } else {
                    cout << "No ID entered.\n";
                }
                break;
            }

            default: {
                cout << "Invalid choice.\n";
                break;
            }
        }

        pauseForEnter();
    }
}


// Do something else Sub Menu
void XyzEmployeeManager::subOthersMenu() {
    while(true) {
        cout << "---------------------------------------------------------------------------------\n";
        cout << "|                         Employee Management System                            |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "| Do something else:                                                            |\n";
        cout << "|     1. Add 'n' number of leaves to all the Full-Time employees               |\n";
        cout << "|     2. Convert an Intern to Full-Time employee                                |\n";
        cout << "|     3. Search an Employee by ID                                               |\n";
        cout << "|     4. Search an Employee by Name                                             |\n";
        cout << "|    (Enter -1 to go back to previous menu)                                     |\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Your choice: ";
        int sInputChoice = readIntSafely();

        switch (sInputChoice) {
            case EMSMenu::AddLeaves: 
            {
                cout << "Enter number of leaves to add: ";
                int sLeavesInput = readIntSafely();
                addLeaves(sLeavesInput);
                pauseForEnter();
                break;
            }

            case EMSMenu::ConvertToFullTime: 
            {
                cout << "Enter Employee ID to convert to Full-Time: ";
                string sInputEmployeeID; 
                getline(cin, sInputEmployeeID);
                if (sInputEmployeeID.empty()) {
                    getline(cin, sInputEmployeeID);
                }
                if (!sInputEmployeeID.empty()) {
                    convertToFullTime(sInputEmployeeID);
                }
                else {
                    cout << "No ID entered.\n";
                }
                pauseForEnter();
                break;
            }

            case EMSMenu::SearchByID: 
            {
                cout << "Enter Employee ID to search: ";
                string sInputEmployeeID; 
                getline(cin, sInputEmployeeID);
                if (sInputEmployeeID.empty()) {
                    getline(cin, sInputEmployeeID);
                }
                if (!sInputEmployeeID.empty()) {
                    getEmployeeByID(sInputEmployeeID);
                }
                else {
                    cout << "No ID entered.\n";
                }
                pauseForEnter();
                break;
            }

            case EMSMenu::SearchByName: 
            {
                cout << "Enter full name to search: ";
                string sInputName; 
                getline(cin, sInputName);
                if (sInputName.empty()) {
                    getline(cin, sInputName);
                }
                if (!sInputName.empty()) {
                    getEmployeeByName(sInputName);
                }
                else cout << "No name entered.\n";
                pauseForEnter();
                break;
            }

            case EMSMenu::ExitOther:
            {
                return;
            }

            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}

// Get size of current employees
int XyzEmployeeManager::getCurrentSize() {
    return mEmployeeDLL.size();
}

// Get Current employee from EDLL
XyzEmployee* XyzEmployeeManager::getCurrentEmployeeAt(int indexParam) {
    if (indexParam < 0 || indexParam >= mEmployeeDLL.size()){
        return nullptr;
    }
    return mEmployeeDLL[indexParam];
}

// Get size of resigned employees
int XyzEmployeeManager::getResignedSize() {
    return mResignedDLL.size();
}

// Get Resigned employee from EDLL
XyzEmployee* XyzEmployeeManager::getResignedEmployeeAt(int indexParam) {
    if (indexParam < 0 || indexParam >= mResignedDLL.size()){
        return nullptr;
    }
    return mResignedDLL[indexParam];
}