#include <iostream>
#include "XyzEmployee.H"
#include "utils.H"

//////////////// XyzEmployee ////////////////

// Default Destructor
XyzEmployee::~XyzEmployee() = default;

// Returns Employee Name
string XyzEmployee::getEmployeeName(){
    return mName;
}

// Set Employee Name
void XyzEmployee::setEmployeeName(string nameParam){
    mName = nameParam;
}

// Returns Employee ID
string XyzEmployee::getEmployeeID(){
    return mEmpID;
}

// Set Employee ID
void XyzEmployee::setEmployeeID(string IDParam){
    mEmpID = IDParam;
}

// Returns Employee Type (Full Time, Contractor, Intern)
int XyzEmployee::getEmployeeType(){
    return mType;
}

// Set Employee Type (Full Time, Contractor, Intern) 
void XyzEmployee::setEmployeeType(int typeParam){
    mType = typeParam;
}

// Returns Employee Status (Active, Inactive, Resigned)
int XyzEmployee::getEmployementStatus(){
    return mStatus;
}

// Set Employee Status (Active, Inactive, Resigned)
void XyzEmployee::setEmployementStatus(int statusParam){
    mStatus = statusParam;
}

// Returns Employee Gender (Male, Female)
int XyzEmployee::getEmployeeGender(){
    return (mGender);
}

// Set Employee Gender (Male, Female)
void XyzEmployee::setEmployeeGender(int genderParam){
    mGender = genderParam;
}

// Returns Employee DOB
string XyzEmployee::getEmployeeDOB(){
    return mDOB;
}

// Set Employee DOB
void XyzEmployee::setEmployeeDOB(string dobParam){
    mDOB = dobParam;
}

// Returns Employee DOJ
string XyzEmployee::getEmployeeDOJ(){
    return mDOJ;
}

// Set Employee DOJ
void XyzEmployee::setEmployeeDOJ(string dojParam){
    mDOJ = dojParam;
}

// Prints Employee details
void XyzEmployee::printEmployeeDetails(){
    cout<<"Employee Name: "<<mName
    <<",\nGender: "<<((mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
    ",\nDate of Birth: "<<mDOB
    <<",\nEmployee ID: "<<mEmpID
    <<",\nEmployement Type: "<<((mType==XyzEmployeeEnums::FullTime)?"Full Time":((mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<mDOJ<<endl;
}

// Overloading << output stream operator to print XyzEmployee object
ostream& operator<<(ostream& OutParam, const XyzEmployee& XyzEmployeeParam){
        OutParam<<"Employee Name: "<<XyzEmployeeParam.mName
        <<",\nGender: "<<((XyzEmployeeParam.mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
        ",\nDate of Birth: "<<XyzEmployeeParam.mDOB
        <<",\nEmployee ID: "<<XyzEmployeeParam.mEmpID
        <<",\nEmployement Type: "<<((XyzEmployeeParam.mType==XyzEmployeeEnums::FullTime)?"Full Time":((XyzEmployeeParam.mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
        <<",\nEmployement Status: "<<((XyzEmployeeParam.mStatus==XyzEmployeeEnums::Active)?"Active":((XyzEmployeeParam.mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
        <<",\nDate of Joining: "<<XyzEmployeeParam.mDOJ<<endl;
        return OutParam;
}

// Overloading >> input stream operator to input XyzEmployee object
istream& operator>>(istream& InParam, XyzEmployee& XyzEmployeeParam) {
        cout << "Enter Name: ";
        getline(InParam, XyzEmployeeParam.mName);
        cout << "Enter Employee ID: ";
        getline(InParam, XyzEmployeeParam.mEmpID);
        cout << "Enter Gender: ";
        InParam >> XyzEmployeeParam.mGender;
        cout << "Enter Date of Birth: ";
        getline(InParam, XyzEmployeeParam.mDOB);
        cout << "Enter Date of Joining: ";
        getline(InParam, XyzEmployeeParam.mDOJ);
        cout << "Enter Type: 1. Full-Time, 2. Contractor, 3. Intern"<<endl;
        cout<<"Your choice: ";
        cin>>XyzEmployeeParam.mType;
        cout << "Enter Status: 1. Active, 2. Inactive, 3. Resigned"<<endl;
        cout<<"Your choice: ";
        cin>>XyzEmployeeParam.mStatus;
        return InParam;
}

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// XyzFullTimeEmployee ////////////////

//Default Destructor
XyzFullTimeEmployee::~XyzFullTimeEmployee() = default;

// Returns leaves availed
int XyzFullTimeEmployee::getLeavesAvailed(){
    return mLeavesAvailed;
}

// Returns leaves left
int XyzFullTimeEmployee::getLeavesLeft(){
    return mLeavesLeft;
}

// Avail leaves from existing pool
void XyzFullTimeEmployee::availLeaves(int leavesParam){
    if(leavesParam <= mLeavesLeft){
        mLeavesAvailed += leavesParam;
        mLeavesLeft -= leavesParam;
    }
    else{
        cout<<"Not enough leaves."<<endl;
    }
}

// Update leaves left
void XyzFullTimeEmployee::updateLeavesLeft(int leavesParam){
    mLeavesLeft += leavesParam;
}

// Print Full Time Employee details
void XyzFullTimeEmployee::printEmployeeDetails() {
    cout<<"Employee Name: "<<mName
    <<",\nGender: "<<((mGender==1)?"Male":"Female")<<
    ",\nDate of Birth: "<<mDOB
    <<",\nEmployee ID: "<<mEmpID
    <<",\nEmployement Type: "<<((mType==XyzEmployeeEnums::FullTime)?"Full Time":((mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<mDOJ
    <<",\nLeaves Left: "<<mLeavesLeft<<endl;
}

// Overloading << output stream operator to print XyzFullTimeEmployee object
ostream& operator<<(ostream& OutParam, const XyzFullTimeEmployee& XyzFullTimeEmployeeParam){
    OutParam<<"Employee Name: "<<XyzFullTimeEmployeeParam.mName
    <<",\nGender: "<<((XyzFullTimeEmployeeParam.mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
    ",\nDate of Birth: "<<XyzFullTimeEmployeeParam.mDOB
    <<",\nEmployee ID: "<<XyzFullTimeEmployeeParam.mEmpID
    <<",\nEmployement Type: "<<((XyzFullTimeEmployeeParam.mType==XyzEmployeeEnums::FullTime)?"Full Time":((XyzFullTimeEmployeeParam.mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((XyzFullTimeEmployeeParam.mStatus==XyzEmployeeEnums::Active)?"Active":((XyzFullTimeEmployeeParam.mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<XyzFullTimeEmployeeParam.mDOJ
    <<",\nLeaves Left: "<<XyzFullTimeEmployeeParam.mLeavesLeft<<endl; 
    return OutParam;
}

// Overloading >> input stream operator to input XyzFullTimeEmployee object
istream& operator>>(istream& InParam, XyzFullTimeEmployee& XyzEmployeeParam) {
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
        XyzEmployeeParam.mType = XyzEmployeeEnums::FullTime;
        cout << "Enter Status: 1. Active, 2. Inactive, 3. Resigned"<<endl;
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mStatus;
        cout<<endl;
        XyzEmployeeParam.mLeavesLeft = STANDARD_LEAVES;
        return InParam;
}

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// XyzContractorEmployee ////////////////

// Default Destructor
XyzContractorEmployee::~XyzContractorEmployee() = default;

// Returns Agency of Contractor
int XyzContractorEmployee::getAgency(){
    return mAgency;
}

// Set Agency of Contractor
void XyzContractorEmployee::setAgency(int agencyParam){
    mAgency = agencyParam;
}

// Print Contractor Employee details
void XyzContractorEmployee::printEmployeeDetails() {
    cout<<"Employee Name: "<<mName
    <<",\nGender: "<<((mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
    ",\nDate of Birth: "<<mDOB
    <<",\nEmployee ID: "<<mEmpID
    <<",\nEmployement Type: "<<((mType==XyzEmployeeEnums::FullTime)?"Full Time":((mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<mDOJ
    <<",\nAgency: "<<((mAgency==XyzEmployeeEnums::Avengers)?"Avengers":((mAgency==XyzEmployeeEnums::JusticeLeague)?"Justice League":"X-Men"))<<endl;
}

// Overloading << output stream operator to print XyzContractorEmployee object
ostream& operator<<(ostream& OutParam, const XyzContractorEmployee& XyzFullTimeEmployeeParam){
    OutParam<<"Employee Name: "<<XyzFullTimeEmployeeParam.mName
    <<",\nGender: "<<((XyzFullTimeEmployeeParam.mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<
    ",\nDate of Birth: "<<XyzFullTimeEmployeeParam.mDOB
    <<",\nEmployee ID: "<<XyzFullTimeEmployeeParam.mEmpID
    <<",\nEmployement Type: "<<((XyzFullTimeEmployeeParam.mType==XyzEmployeeEnums::FullTime)?"Full Time":((XyzFullTimeEmployeeParam.mType==XyzEmployeeEnums::Contractor)?"Contractor":"Intern"))
    <<",\nEmployement Status: "<<((XyzFullTimeEmployeeParam.mStatus==XyzEmployeeEnums::Active)?"Active":((XyzFullTimeEmployeeParam.mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))
    <<",\nDate of Joining: "<<XyzFullTimeEmployeeParam.mDOJ
    <<",\nAgency: "<<XyzFullTimeEmployeeParam.mAgency<<endl; 
    return OutParam;
}

// Overloading >> input stream operator to input XyzContractorEmployee object
istream& operator>>(istream& InParam, XyzContractorEmployee& XyzEmployeeParam) {
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
        XyzEmployeeParam.mType = XyzEmployeeEnums::Contractor;
        cout << "Enter Status: 1. Active, 2. Inactive, 3. Resigned"<<endl;
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mStatus;
        cout<<endl;
        cout<<"Enter Agency: 1. Avengers, 2. Justice Leque, 3. X-Men";
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mAgency;
        cout<<endl;
        return InParam;
}

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// XyzInternEmployee ////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////
