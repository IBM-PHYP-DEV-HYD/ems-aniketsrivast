#ifndef XYZCONTRACTOREMPLOYEE_H_
#define XYZCONTRACTOREMPLOYEE_H_

#include "XyzEmployee.H"

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

#endif // XYZCONTRACTOREMPLOYEE_H_