#ifndef XYZEMPLOYEEMANAGER_H_
#define XYZEMPLOYEEMANAGER_H_

#include "EDLL.H"

class XyzEmployeeManager {
    private:
        EDLL mEmployeeDLL;
        EDLL mResignedDLL;

        int mNextNumericID = 1; // Incremental number to assign Employee IDs

    public:
        void addEmployee(XyzEmployee*);
        bool removeEmployee(string);

        XyzEmployee* createEmployeeRandom();
        XyzEmployee* createEmployeeFromInput();
        
        void getEmployeeByName(string);
        void getEmployeeByID(string);
        bool convertToFullTime(string);
        void addLeaves(int);

        string generateNextEmployeeID(char);

        void mainMenu();
        void subAddMenu();
        void subSummaryMenu();
        void subOthersMenu();

        int readIntSafely() const;
        void pauseForEnter() const;

        int getCurrentSize();
        XyzEmployee* getCurrentEmployeeAt(int);
        int getResignedSize();
        XyzEmployee* getResignedEmployeeAt(int);
};

#endif // XYZEMPLOYEEMANAGER_H_