#include "XyzFullTimeEmployee.H"
#include <iomanip>

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

// Update leaves left
void XyzFullTimeEmployee::updateLeavesLeft(int leavesParam){
    mLeavesLeft += leavesParam;
}

// Print Full Time Employee details
void XyzFullTimeEmployee::printEmployeeDetails() {
    cout << "| "<<left<<setw(22)<<mName<<" | "<<left<<setw(10)<<mEmpID<<" | "<<left<<setw(10)<<"Full Time"<<" | "
    <<left<<setw(12)<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))<<" | "
    <<left<<setw(9)<<((mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<" | "<<left<<setw(13)<<mDOB<<" | "<<left<<setw(15)<<mDOJ<<" | "
    <<left<<setw(11)<<mLeavesLeft<<" | "<<left<<setw(14)<<mLeavesAvailed<<" | "<<left<<setw(14)<<"NA"<<" | "<<left<<setw(7)<<"NA"<<" | "
    <<left<<setw(6)<<"NA"<<" |\n";
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
