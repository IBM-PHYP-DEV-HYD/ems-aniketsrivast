#ifndef EMPLOYEEREPORTBUILDER_H_
#define EMPLOYEEREPORTBUILDER_H_

#include <string>
#include "XyzEmployee.H"
#include "XyzEmployeeManager.H"

// Builder class to build and return itself for chain filteration
class EmployeeReportBuilder {
    private:
        XyzEmployeeManager& mEmployeeManager;
        bool mIncludeCurrentFlag;
        bool mIncludeResignedFlag;
        int mGenderFilter;
        int mStatusFilter;
        int mTypeFilter;

        bool matchesFilters(XyzEmployee*) const;

    public:
        explicit EmployeeReportBuilder(XyzEmployeeManager&);

        EmployeeReportBuilder& includeCurrent(bool);
        EmployeeReportBuilder& includeResigned(bool);

        // filters (0 = no filter)
        EmployeeReportBuilder& filterGender(int); // 1=Male,2=Female
        EmployeeReportBuilder& filterStatus(int); // 1=Active,2=Inactive,3=Resigned
        EmployeeReportBuilder& filterType(int);     // 1=FullTime,2=Contractor,3=Intern

        EmployeeReportBuilder& clearFilters();

        void print() const;
};

#endif // EMPLOYEEREPORTBUILDER_H_
