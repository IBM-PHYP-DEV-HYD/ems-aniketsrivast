#ifndef XYZEMPLOYEE_H_
#define XYZEMPLOYEE_H_

#include "XyzEmployeeIF.H"
#include "utils.H"

//////////////// Employee Base Class ////////////////
class XyzEmployee : public XyzEmployeeIF {

    protected:
        string mName;
        string mEmpID;
        int mType;
        int mStatus;
        int mGender;
        string mDOB;
        string mDOJ;

    public:
        // Parameterized Constructor
        XyzEmployee(string name, string empID, int type, int status, int gender, string DOB, string DOJ) :
            mName(name),
            mEmpID(empID),
            mType(type),
            mStatus(status),
            mGender(gender),
            mDOB(DOB),
            mDOJ(DOJ) {}    
        
        //Default Constructor
        XyzEmployee() : XyzEmployee("DefaultName", "-1", -1, -1, -1, "1999-01-01", "1999-01-01"){}        

        virtual ~XyzEmployee() override;

        string getEmployeeName() override;
        void setEmployeeName(string) override;
        string getEmployeeID() override;
        void setEmployeeID(string) override;
        int getEmployeeType() override;
        void setEmployeeType(int) override;
        int getEmployementStatus() override;
        void setEmployementStatus(int) override;
        int getEmployeeGender() override;
        void setEmployeeGender(int) override;
        string getEmployeeDOB() override;
        void setEmployeeDOB(string) override;
        string getEmployeeDOJ() override;
        void setEmployeeDOJ(string) override;

        virtual void printEmployeeDetails() override;
        friend ostream& operator<<(ostream&, const XyzEmployee&);
        friend istream& operator>>(istream& InParam, XyzEmployee& InputParam);
};

#endif // XYZEMPLOYEE_H_