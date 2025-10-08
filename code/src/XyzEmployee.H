#ifndef XYZEMPLOYEE_H_
#define XYZEMPLOYEE_H_

#include "XyzEmployeeIF.H"

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

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// Full Time Employee ////////////////

class XyzFullTimeEmployee : public XyzEmployee {
    private:
        int mLeavesAvailed;
        int mLeavesLeft;
    public:
        // Parameterized Constructor
        XyzFullTimeEmployee(string name, string empID, int type, int status, int gender, string DOB, string DOJ, int leavesLeft) : 
            XyzEmployee::XyzEmployee(name, empID, type, status, gender, DOB, DOJ),
            mLeavesAvailed(0),
            mLeavesLeft(leavesLeft) {}
        // Default Constructor
        XyzFullTimeEmployee() : 
            XyzEmployee::XyzEmployee(),
            mLeavesAvailed(0),
            mLeavesLeft(0) {}

        virtual ~XyzFullTimeEmployee() override;

        virtual void printEmployeeDetails() override;
        int getLeavesAvailed();
        int getLeavesLeft();
        void updateLeavesLeft(int);   
        friend ostream& operator<<(ostream&, const XyzFullTimeEmployee&);
        friend istream& operator>>(istream& InParam, XyzFullTimeEmployee& InputParam);

};

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// Contractor Employee ////////////////

class XyzContractorEmployee : public XyzEmployee {
    private:
        int mAgency;
    public:
        // Parameterized Constructor
        XyzContractorEmployee(string name, string empID, int type, int status, int gender, string DOB, string DOJ, int Agency) : 
            XyzEmployee::XyzEmployee(name, empID, type, status, gender, DOB, DOJ),
            mAgency(Agency) {}
        // Default Constructor
        XyzContractorEmployee() : 
            XyzEmployee::XyzEmployee(),
            mAgency(-1) {}

        virtual ~XyzContractorEmployee() override;
        void printEmployeeDetails() override;
        int getAgency();
        void setAgency(int);
        friend ostream& operator<<(ostream&, const XyzContractorEmployee&);
        friend istream& operator>>(istream& InParam, XyzContractorEmployee& InputParam);
};
////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// Intern Employee ////////////////

class XyzInternEmployee : public XyzEmployee {
    private:
        int mCollege;
        int mBranch;
    public:
        // Parameterized Constructor
        XyzInternEmployee(string name, string empID, int type, int status, int gender, string DOB, string DOJ, int college, int branch) : 
            XyzEmployee::XyzEmployee(name, empID, type, status, gender, DOB, DOJ),
            mCollege(college),
            mBranch(branch) {}
        // Default Constructor
        XyzInternEmployee() : 
            XyzEmployee::XyzEmployee(),
            mCollege(-1),
            mBranch(-1) {}

        virtual ~XyzInternEmployee() override;
        void printEmployeeDetails() override;
        int getCollege();
        void setCollege(int);
        int getBranch();
        void setBranch(int);  
        string getCollegeString();
        friend ostream& operator<<(ostream&, const XyzInternEmployee&);
        friend istream& operator>>(istream& InParam, XyzInternEmployee& InputParam);
};
////////////////////////////////////////////////////////////////////////////////////////////////

#endif // XYZEMPLOYEE_H_