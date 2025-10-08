#include <iostream>
#include <string.h>

#include "EDLL.H"
#include "XyzEmployeeManager.H"
// #include "utils.H"


using namespace std;

int main(){
    // XyzEmployee* a = new XyzInternEmployee("Aniket", "A001", 1, 1, 1, "1999-05-02", "2012-10-10", 1, 1);
    // XyzEmployee *b = new XyzFullTimeEmployee("Animesh", "A002", 1, 1, 0, "1996-12-02", "2012-10-10", 20);
    // XyzEmployee *c = new XyzContractorEmployee("Rahul", "A003", 1, 1, 0, "1996-12-02", "2012-10-10", 1);
    // EDLL obj;
    // obj.push_back(a);
    // obj.push_back(b);
    // obj.push_back(c);
    // obj.printEDLL();
    XyzEmployeeManager oj;
    oj.mainMenu();
    return 0;
}