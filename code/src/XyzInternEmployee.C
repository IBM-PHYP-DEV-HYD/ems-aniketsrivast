#include "XyzInternEmployee.H"

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
            return "Default College";
            break;
    }
}

// Print Intern Employee details
void XyzInternEmployee::printEmployeeDetails() {
    cout<<"Employee Name: "<<mName
    <<",\nGender: "<<((mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
    ",\nDate of Birth: "<<mDOB
    <<",\nEmployee ID: "<<mEmpID
    <<",\nEmployement Type: "<<((mType==XyzEmployeeEnums::FullTime)?"Full Time":((mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<mDOJ
    <<",\nCollege: "<<getCollegeString()
    <<",\nBranch: "<<((mBranch==XyzEmployeeEnums::CSE)?"CSE":((mBranch==XyzEmployeeEnums::CSEIT)?"CSEIT":"ECE"))<<endl;
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
        cout << "Enter Gender: 1. Male, 2. Female"<<endl;
        cout << "Your choice: ";
        InParam >> XyzEmployeeParam.mGender;
        InParam.ignore();        
        cout << "Enter Date of Birth: ";
        getline(InParam, XyzEmployeeParam.mDOB);
        cout << "Enter Date of Joining: ";
        getline(InParam, XyzEmployeeParam.mDOJ);
        XyzEmployeeParam.mType = XyzEmployeeEnums::Intern;
        cout << "Enter Status: 1. Active, 2. Inactive, 3. Resigned"<<endl;
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mStatus;
        cout<<endl;
        cout<<"Enter Branch: 1. CSE, 2. CSEIT, 3. ECE";
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mCollege;
        cout<<endl;
        cout<<"Enter Agency: 1. IITD, 2. IITM, 3. IITK, 4. IITH, 5. NITW, 6. NITT, 7. IIITH";
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mCollege;
        cout<<endl;
        return InParam;
}
