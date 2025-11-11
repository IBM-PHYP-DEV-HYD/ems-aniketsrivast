#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

using namespace std;

// Standard leaves allotted to a new Full-Time Employee
#define STANDARD_LEAVES 22
#define MAX_RANDOM_EMPLOYEES 100
#define MIN_RANDOM_EMPLOYEES 1

// Node for EDLL
template<class S>
struct Node {
            S mData;
            Node *mPrev;
            Node *mNext;

            Node(const S &InputParam) : mData(InputParam){
                mPrev = nullptr;
                mNext = nullptr;
            }
        };

/*-------------ENUMERATORS-------------*/

namespace DequeMockMenu{
    // Resize direction
    enum DequeDirection {
        Direction_Left = -1,
        Direction_Right = 1
    };

    // Menu options
    enum DequeMenuInputs {
        Exit = -1,
        EmptyDeque = 1,
        ParameterizedDeque,
        PushEnd,
        PushFront,
        PopEnd,
        PopFront,
        GetFront,
        GetEnd,
        GetSize,
        Resize,
        Clear,
        Print
    };
}

// XyzEmployee Enumerations
namespace XyzEmployeeEnums{
    // XyzEmployee Common Enums
    enum EmployeeStatus{
        Active = 1,
        Inactive,
        Resigned
    };

    enum EmployeeType{
        FullTime = 1,
        Contractor,
        Intern
    };

    enum EmployeeGender{
        Male = 1,
        Female
    };

    // Contractor Agencies
    enum ContractorAgencies{
        Avengers = 1,
        JusticeLeague,
        XMen,
        ContractorAgenciesMax
    };

    // Interns' colleges
    enum Colleges{
        IITD,
        IITM,
        IITK,
        IITH,
        NITW,
        NITT,
        IIITH,
        CollegesMax
    };

    // Interns' branches
    enum Branches{
        CSE,
        CSEIT,
        ECE,
        BranchesMax
    };
}

// Employee Manager Enumerations
namespace EMSMenu{
    enum MainMenuEnums{
        ExitMain = -1,
        AddMenu = 1,
        RemoveMenu,
        DetailsMenu,
        OtherMenu
    };

    enum AddMenuEnums{
        ExitAdd = -1,
        AddRandom = 1,
        AddMultipleRandoms,
        AddManually
    };
    
    enum DetailsMenuEnums{
        ExitDetails = -1,
        AllDetails = 1,
        DetailsByType,
        DetailsByGender,
        DetailsByStatus,
        DetailsByID    
    };

    enum OtherMenuEnums{
        ExitOther = -1,
        AddLeaves = 1,
        ConvertToFullTime,
        SearchByID,
        SearchByName
    };
}
#endif // UTILS_H_
