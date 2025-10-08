#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

using namespace std;

#define STANDARD_LEAVES 22

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

namespace XyzEmployeeEnums{
    enum EmployeeStatus{
        Active = 1,
        Inactive,
        Resigned,
        EmployeeStatusMax
    };

    enum EmployeeType{
        FullTime = 1,
        Contractor,
        Intern,
        EmployeeTypeMax
    };

    enum EmployeeGender{
        Male = 1,
        Female,
        EmployeeGenderMax
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
        AddManually
    };
    
    enum DetailsMenuEnums{
        ExitDetails = -1,
        AllDetails = 1,
        DetalsByType,
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
