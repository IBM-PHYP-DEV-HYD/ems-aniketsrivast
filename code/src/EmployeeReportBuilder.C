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

void EmployeeReportBuilder::forEach(function<void(XyzEmployee*)> functionParam) const {
    if (mIncludeCurrentFlag) {
        int sCurrentSize = mEmployeeManager.getCurrentSize();
        int sIndex = 0;
        for (sIndex = 0; sIndex < sCurrentSize; ++sIndex) {
            XyzEmployee* sXyzEmployee = mEmployeeManager.getCurrentEmployeeAt(sIndex);
            if (sXyzEmployee && matchesFilters(sXyzEmployee)) {
                functionParam(sXyzEmployee);
            }
        }
    }
    if (mIncludeCurrentFlag) {
        int sResignedSize = mEmployeeManager.getResignedSize();
        int sIndex = 0;
        for (sIndex = 0; sIndex < sResignedSize; ++sIndex) {
            XyzEmployee* sXyzEmployee = mEmployeeManager.getResignedEmployeeAt(sIndex);
            if (sXyzEmployee && matchesFilters(sXyzEmployee)) {
                functionParam(sXyzEmployee);
            }
        }
    }
}

void EmployeeReportBuilder::print() const {
    cout << "--------------------------------------------------\n";
    cout << "Employee Report\n";
    cout << "Filters: "
         << (mGenderFilter ? (mGenderFilter==XyzEmployeeEnums::Male? "Male" : "Female") : "Any Gender")
         << ", " << (mTypeFilter ? (mTypeFilter==XyzEmployeeEnums::FullTime? "FullTime" : (mTypeFilter==XyzEmployeeEnums::Contractor? "Contractor":"Intern")) : "Any Type")
         << ", " << (mStatusFilter ? (mStatusFilter==XyzEmployeeEnums::Active? "Active" : (mStatusFilter==XyzEmployeeEnums::Inactive? "Inactive":"Resigned")) : "Any Status")
         << "\n";
    cout << (mIncludeCurrentFlag ? "Including: Active/Inactive" : "")
         << (mIncludeResignedFlag ? (mIncludeCurrentFlag ? " and Resigned" : "Including: Resigned") : "")
         << "\n";
    cout << "--------------------------------------------------\n";

    int sCount = 0;
    forEach([&sCount](XyzEmployee* sXyzEmployee){
        ++sCount;
        sXyzEmployee->printEmployeeDetails();
        cout << "--------------------------------------------------\n";
    });

    if (sCount == 0) cout << "[No employees match the criteria]\n";
    else cout << "Total matched: " << sCount << "\n";
}
