#ifndef XYZINTERNEMPLOYEE_H_
#define XYZINTERNEMPLOYEE_H_

#include "XyzEmployee.H"

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

#endif // XYZINTERNEMPLOYEE_H_