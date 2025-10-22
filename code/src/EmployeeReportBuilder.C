#include "EmployeeReportBuilder.H"
#include "XyzEmployeeManager.H"
#include <iostream>

using namespace std;

EmployeeReportBuilder::EmployeeReportBuilder(XyzEmployeeManager& managerParam)
    : mEmployeeManager(managerParam),
      mGenderFilter(0),
      mStatusFilter(0),
      mTypeFilter(0)
{}


EmployeeReportBuilder& EmployeeReportBuilder::filterGender(int genderParam) {
    mGenderFilter = genderParam; 
    return *this;
}

EmployeeReportBuilder& EmployeeReportBuilder::filterStatus(int statusParam) {
    mStatusFilter = statusParam; 
    return *this;
}

EmployeeReportBuilder& EmployeeReportBuilder::filterType(int typeParam) {
    mTypeFilter = typeParam; 
    return *this;
}

EmployeeReportBuilder& EmployeeReportBuilder::clearFilters() {
    mGenderFilter = 0;
    mStatusFilter = 0;
    mTypeFilter = 0; 
    return *this;
}

bool EmployeeReportBuilder::matchesFilters(XyzEmployee* employeeParam) const {
    bool sMatchFlag = true;
    if (!employeeParam){
        sMatchFlag = false;
    } 
    else if (mGenderFilter != 0 && employeeParam->getEmployeeGender() != mGenderFilter) {
        sMatchFlag = false;
    }
    else if (mStatusFilter != 0 && employeeParam->getEmployementStatus() != mStatusFilter) {
        sMatchFlag = false;
    }
    else if (mTypeFilter != 0 && employeeParam->getEmployeeType() != mTypeFilter) {
        sMatchFlag = false;
    }
    return sMatchFlag;
}

void EmployeeReportBuilder::printCurrentFiltered() const {
    if(!mEmployeeManager.getCurrentSize()){
        cout<<"No Employees present\n";
    }
    else{
        int sIndex = 0;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| Employee Name          | ID         | Type       | Status       | Gender    | Date of Birth | Date of Joining | Leaves Left | Leaves Availed | Agency         | College | Branch |\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        for (sIndex = 0; sIndex < mEmployeeManager.getCurrentSize(); sIndex++) {
            XyzEmployee* sXyzEmployee = mEmployeeManager.getCurrentEmployeeAt(sIndex);
            if (!sXyzEmployee){
                continue;
            }
            if (!matchesFilters(sXyzEmployee)){
                continue;
            }
            sXyzEmployee->printEmployeeDetails();
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
}

void EmployeeReportBuilder::printResigned() const {
    if(!mEmployeeManager.getResignedSize()){
        cout<<"No Resigned employees present\n";
    }
    else{
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| Employee Name          | ID         | Type       | Status       | Gender    | Date of Birth | Date of Joining | Leaves Left | Leaves Availed | Agency         | College | Branch |\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        int sIndex = 0;
        for (sIndex = 0; sIndex < mEmployeeManager.getResignedSize(); sIndex++) {
            XyzEmployee* sXyzEmployee = mEmployeeManager.getResignedEmployeeAt(sIndex);
            if (!sXyzEmployee){
                continue;
            }
            sXyzEmployee->printEmployeeDetails();
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
}