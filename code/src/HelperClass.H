#ifndef HELPERCLASS_H_
#define HELPERCLASS_H_

#include <string>
#include "XyzEmployee.H"
#include "XyzEmployeeManager.H"

class HelperClass {
    public:
    static bool validateDOJ(string DOBParam, string DOJParam);
    static bool validateName(string &nameParam);
    static bool isValidDateFormat(const string& dateParam);
    static int readIntSafely();
    static void pauseForEnter();
};

#endif // HELPERCLASS_H_
