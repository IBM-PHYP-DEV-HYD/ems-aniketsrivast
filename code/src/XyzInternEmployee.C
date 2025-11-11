#include "XyzInternEmployee.H"
#include <iomanip>
#include "HelperClass.H"

XyzInternEmployee::~XyzInternEmployee() = default;

// Returns College of Intern
int XyzInternEmployee::getCollege(){
    return mCollege;
}

// Set College of Intern
void XyzInternEmployee::setCollege(int collegeParam){
    mCollege = collegeParam;
}

// Returns Branch of Intern
int XyzInternEmployee::getBranch(){
    return mBranch;
}

// Set College of Intern
void XyzInternEmployee::setBranch(int branchParam){
    mBranch = branchParam;
}

// Returns College of Intern in String
string XyzInternEmployee::getCollegeString(){
    switch(mCollege){
        case XyzEmployeeEnums::IITD:
            return "IITD";
            break;
        case XyzEmployeeEnums::IITM:
            return "IITM";
            break;
        case XyzEmployeeEnums::IITK:
            return "IITK";
            break;
        case XyzEmployeeEnums::IITH:
            return "IITH";
            break;
        case XyzEmployeeEnums::NITW:
            return "NITW";
            break;
        case XyzEmployeeEnums::NITT:
            return "NITT";
            break;
        case XyzEmployeeEnums::IIITH:
            return "IIITH";
            break;
        default:
            return "IITD";
            break;
    }
}

// Print Intern Employee details
void XyzInternEmployee::printEmployeeDetails() {
    cout << "| "<<left<<setw(22)<<mName<<" | "<<left<<setw(12)<<mEmpID<<" | "<<left<<setw(10)<<"Intern"<<" | "
    <<left<<setw(12)<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))<<" | "
    <<left<<setw(9)<<((mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<" | "<<left<<setw(13)<<mDOB<<" | "
    <<left<<setw(15)<<mDOJ<<" | "<<left<<setw(11)<<"NA"<<" | "<<left<<setw(14)<<"NA"<<" | "<<left<<setw(14)<<"NA"<<" | "<<left<<setw(7)<<getCollegeString()<<" | "
    <<left<<setw(6)<<((mCollege==XyzEmployeeEnums::CSE)?"CSE":((mCollege==XyzEmployeeEnums::CSEIT)?"CSEIT":"ECE"))<<" |\n";
}

// Overloading << output stream operator to print XyzInternEmployee object
ostream& operator<<(ostream& OutParam, const XyzInternEmployee& XyzFullTimeEmployeeParam){
    OutParam<<"Employee Name: "<<XyzFullTimeEmployeeParam.mName
    <<",\nGender: "<<((XyzFullTimeEmployeeParam.mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
    ",\nDate of Birth: "<<XyzFullTimeEmployeeParam.mDOB
    <<",\nEmployee ID: "<<XyzFullTimeEmployeeParam.mEmpID
    <<",\nEmployement Type: "<<((XyzFullTimeEmployeeParam.mType==XyzEmployeeEnums::FullTime)?"Full Time":((XyzFullTimeEmployeeParam.mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((XyzFullTimeEmployeeParam.mStatus==XyzEmployeeEnums::Active)?"Active":((XyzFullTimeEmployeeParam.mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<XyzFullTimeEmployeeParam.mDOJ
    <<",\nCollege: "<<XyzFullTimeEmployeeParam.mCollege
    <<",\nBranch: "<<XyzFullTimeEmployeeParam.mBranch<<endl;
    return OutParam;
}

// Overloading >> input stream operator to input XyzInternEmployee object
istream& operator>>(istream& InParam, XyzInternEmployee& XyzEmployeeParam) {
        cout << "Enter Name: ";
        getline(InParam, XyzEmployeeParam.mName);
        while(!HelperClass::validateName(XyzEmployeeParam.mName)){
            cout<<"Name cannot be left blank.\nEnter Name: ";
            getline(InParam, XyzEmployeeParam.mName);
        }

        cout << "Enter Gender: 1. Male, 2. Female"<<endl;
        cout << "Your choice: ";
        InParam >> XyzEmployeeParam.mGender;
        InParam.ignore();        

        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        getline(InParam, XyzEmployeeParam.mDOB);
        while(!HelperClass::isValidDateFormat(XyzEmployeeParam.mDOB)){
            cout << "Incorrect Format\nEnter Date of Birth (DD-MM-YYYY): ";
            getline(InParam, XyzEmployeeParam.mDOB);
        }

        cout << "Enter Date of Joining (DD-MM-YYYY): ";
        getline(InParam, XyzEmployeeParam.mDOJ);
        while(!HelperClass::isValidDateFormat(XyzEmployeeParam.mDOJ)){
            cout << "Incorrect Format\nEnter Date of Joining (DD-MM-YYYY): ";
            getline(InParam, XyzEmployeeParam.mDOJ);
        }        
        while(!HelperClass::validateDOJ(XyzEmployeeParam.mDOB, XyzEmployeeParam.mDOJ)){
            cout<<"The employee must be above 18 years of age on the date of joining.\n";
            cout << "Re-enter Date of Joining (DD-MM-YYYY): ";
            getline(InParam, XyzEmployeeParam.mDOJ);
        }

        XyzEmployeeParam.mType = XyzEmployeeEnums::Intern;

        cout << "Enter Status: 1. Active, 2. Inactive, 3. Resigned"<<endl;
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mStatus;
        cout<<endl;

        cout<<"Enter Branch: 1. CSE, 2. CSEIT, 3. ECE\n";
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mCollege;
        cout<<endl;

        cout<<"Enter College: 1. IITD, 2. IITM, 3. IITK, 4. IITH, 5. NITW, 6. NITT, 7. IIITH\n";
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mCollege;
        cout<<endl;
        return InParam;
}
