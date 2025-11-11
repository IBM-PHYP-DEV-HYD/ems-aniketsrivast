#include "XyzContractorEmployee.H"
#include <iomanip>
#include "HelperClass.H"

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
    cout << "| "<<left<<setw(22)<<mName<<" | "<<left<<setw(12)<<mEmpID<<" | "<<left<<setw(10)<<"Contractor"<<" | "
    <<left<<setw(12)<<((mStatus==XyzEmployeeEnums::Active)?"Active":((mStatus==XyzEmployeeEnums::Inactive)?"Inactive":"Resigned"))<<" | "
    <<left<<setw(9)<<((mGender==XyzEmployeeEnums::Male)?"Male":"Female")<<" | "<<left<<setw(13)<<mDOB<<" | "
    <<left<<setw(15)<<mDOJ<<" | "<<left<<setw(11)<<"NA"<<" | "<<left<<setw(14)<<"NA"<<" | "<<left<<setw(14)
    <<((mAgency==XyzEmployeeEnums::JusticeLeague)?"Justice League":((mAgency==XyzEmployeeEnums::XMen)?"X-Men":"Avengers"))<<" | "<<left<<setw(7)<<"NA"<<" | "
    <<left<<setw(6)<<"NA"<<" |\n";
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

        XyzEmployeeParam.mType = XyzEmployeeEnums::Contractor;

        cout << "Enter Status: 1. Active, 2. Inactive, 3. Resigned"<<endl;
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mStatus;
        cout<<endl;

        cout<<"Enter Agency: 1. Avengers, 2. Justice League, 3. X-Men\n";
        cout<<"Your choice: ";
        InParam>>XyzEmployeeParam.mAgency;
        cout<<endl;
        return InParam;
}
