#ifndef EDLL_H_
#define EDLL_H_

#include "Deque.H"
#include "XyzEmployee.H"

class EDLL : public Deque<XyzEmployee*> {
    public:
        EDLL() : Deque<XyzEmployee*>() {}
        EDLL(int sizeParam, XyzEmployee* inputParam) : Deque<XyzEmployee*>(sizeParam, inputParam) {}
        void insertAtIndex(XyzEmployee*, int);
        void removeFromIndex(int);
        void printEDLL();
};

#endif // EDLL_H_