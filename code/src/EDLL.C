#include "EDLL.H"

// Insert employee at given index
void EDLL::insertAtIndex(XyzEmployee* employeeParam, int indexParam){
    if(indexParam <= 0 || empty()){
        cout<<"Empty EDLL. Inserting at head"<<endl;
        push_front(employeeParam);
        return;
    }
    if(indexParam >= mSize_Deque){
        push_back(employeeParam);
        return;
    }

    Node<XyzEmployee*>* sIterNode = mHead;
    int sIndex = 0;
    for(sIndex = 0; sIndex < indexParam; ++sIndex) {
        sIterNode = sIterNode->mNext;
    }
    Node<XyzEmployee*>* sInputNode = new Node<XyzEmployee*>(employeeParam);
    sInputNode->mData = employeeParam;

    Node<XyzEmployee*>* sPrevNode = sIterNode->mPrev;
    sPrevNode->mNext = sInputNode;
    sInputNode->mPrev = sPrevNode;
    sInputNode->mNext = sIterNode;
    sIterNode->mPrev = sInputNode;
    ++mSize_Deque;
}

// Remove employee from the given index
void EDLL::removeFromIndex(int indexParam){
if(empty()){
        cout<<"Deque is already empty"<<endl;
        return;
    }
    if(indexParam < 0 || indexParam >= mSize_Deque){
        cout<<"Index out of range in removeAt: "<<indexParam<<endl;
        return;
    }

    Node<XyzEmployee*>* sIterNode = mHead;
    int sIndex = 0;
    for(sIndex = 0; sIndex < indexParam; ++sIndex) {
        sIterNode = sIterNode->mNext;
    }

    if(sIterNode == mHead && sIterNode == mTail){
        mHead = mTail = nullptr;
    } else if(sIterNode == mHead){
        mHead = sIterNode->mNext;
        mHead->mPrev = nullptr;
    } else if(sIterNode == mTail){
        mTail = sIterNode->mPrev;
        mTail->mNext = nullptr;
    } else {
        sIterNode->mPrev->mNext = sIterNode->mNext;
        sIterNode->mNext->mPrev = sIterNode->mPrev;
    }
    delete sIterNode;
    --mSize_Deque;
}

void EDLL::printEDLL(){
    if(this->empty()){
        // cout<<"Deque is empty"<<endl;
    }
    else{
        cout << "---------------------------------------------" << endl;
        cout << "Printing Employee List (" << this->size() << " employees)" << endl;
        cout << "---------------------------------------------" << endl;

        Node<XyzEmployee*>* sTemp = this->mHead;
        int sIndex = 0;

        while (sTemp != nullptr) {
            cout << "[" << sIndex++ << "] ";

            XyzEmployee* sEmployee = sTemp->mData;
            if (sEmployee != nullptr) {
                sEmployee->printEmployeeDetails(); 
                cout << "---------------------------------------------" << endl;
            } else {
                cout << "(null employee pointer)" << endl;
            }

            sTemp = sTemp->mNext;
        }
        cout << endl;
    }
}