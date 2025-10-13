#include "XyzContractorEmployee.H"

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
