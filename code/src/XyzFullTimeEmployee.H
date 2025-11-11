#ifndef XYZFULLTIMEEMPLOYEE_H_
#define XYZFULLTIMEEMPLOYEE_H_

#include "XyzEmployee.H"

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

#endif // XYZFULLTIMEEMPLOYEE_H_