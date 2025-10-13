#include <iostream>
#include "XyzEmployee.H"

using namespace std;

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
