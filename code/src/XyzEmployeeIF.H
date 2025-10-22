#ifndef XYZEMPLOYEEIF_H_
#define XYZEMPLOYEEIF_H_

#include <string>

using namespace std;

// Employee Interface
class XyzEmployeeIF {
    
    public:
        virtual string getEmployeeName() = 0;
        virtual void setEmployeeName(string) = 0;
        virtual string getEmployeeID() = 0;
        virtual void setEmployeeID(string) = 0;
        virtual int getEmployeeType() = 0;
        virtual void setEmployeeType(int) = 0;
        virtual int getEmployementStatus() = 0;
        virtual void setEmployementStatus(int) = 0;
        virtual int getEmployeeGender() = 0;
        virtual void setEmployeeGender(int) = 0;
        virtual string getEmployeeDOB() = 0;
        virtual void setEmployeeDOB(string) = 0;
        virtual string getEmployeeDOJ() = 0;
        virtual void setEmployeeDOJ(string) = 0;
        virtual void printEmployeeDetails() = 0;
        virtual ~XyzEmployeeIF() = default;
};

#endif // XYZEMPLOYEEIF_H_