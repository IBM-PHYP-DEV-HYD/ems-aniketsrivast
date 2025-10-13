#include "EmployeeReportBuilder.H"
#include "XyzEmployeeManager.H"
#include <iostream>

using namespace std;

EmployeeReportBuilder::EmployeeReportBuilder(XyzEmployeeManager& managerParam)
    : mEmployeeManager(managerParam),
      mIncludeCurrentFlag(true),
      mIncludeResignedFlag(false),
      mGenderFilter(0),
      mStatusFilter(0),
      mTypeFilter(0)
{}

EmployeeReportBuilder& EmployeeReportBuilder::includeCurrent(bool currentParam) {
    mIncludeCurrentFlag = currentParam; 
    return *this;
}
EmployeeReportBuilder& EmployeeReportBuilder::includeResigned(bool resignedParam) {
    mIncludeResignedFlag = resignedParam; 
    return *this;
}
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
    if (!employeeParam){
        return false;
    } 
    else if (mGenderFilter != 0 && employeeParam->getEmployeeGender() != mGenderFilter) {
        return false;
    }
    else if (mStatusFilter != 0 && employeeParam->getEmployementStatus() != mStatusFilter) {
        return false;
    }
    else if (mTypeFilter != 0 && employeeParam->getEmployeeType() != mTypeFilter) {
        return false;
    }
    return true;
}

void EmployeeReportBuilder::print() const {
    int sCount = 0;
    if (mIncludeCurrentFlag) {
        int sIndex = 0;
        for (sIndex = 0; sIndex < mEmployeeManager.getCurrentSize(); sIndex++) {
            XyzEmployee* sXyzEmployee = mEmployeeManager.getCurrentEmployeeAt(sIndex);
            if (!sXyzEmployee){
                continue;
            }
            if (!matchesFilters(sXyzEmployee)){
                continue;
            }
            sCount++;
            sXyzEmployee->printEmployeeDetails();
            cout << "--------------------------------------------------\n";
        }
    }
    if (mIncludeResignedFlag) {
        int sIndex = 0;
        for (int sIndex = 0; sIndex < mEmployeeManager.getResignedSize(); sIndex++) {
            XyzEmployee* sXyzEmployee = mEmployeeManager.getResignedEmployeeAt(sIndex);
            if (!sXyzEmployee){
                continue;
            }
            if (!matchesFilters(sXyzEmployee)){
                continue;
            }
            sCount++;
            sXyzEmployee->printEmployeeDetails();
            cout << "--------------------------------------------------\n";
        }
    }
}
