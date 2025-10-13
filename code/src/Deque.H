#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>
#include "utils.H"

using namespace std;

template<class S>
class Deque{
    protected:
        Node<S> *mHead; // pointer to mHead element
        Node<S> *mTail; // pointer to mTail element
        int mSize_Deque; // size of Deque

    public:
        Deque();                
        Deque(int SizeParam, S InputParam);      
        virtual ~Deque();

        void push_back(S InputParam);
        void pop_back();
        void push_front(S InputParam);
        void pop_front();
        
        S front();
        S back();
        
        bool empty();
        int size();
        void resize(int SizeParam, S DefaultParam, int DirectionParam);
        void clear();
        
        S operator[](int SizeParam);
};

// Default constructor
template<class S>
Deque<S>::Deque(){
    mHead = nullptr;
    mTail = nullptr;
    mSize_Deque = 0;
}

// Parameterized constructor
template<class S>
Deque<S>::Deque(int SizeParam, S InputParam) : Deque() {
    int sIndex = 0;
    for(sIndex = 0; sIndex < SizeParam; sIndex++){
        push_back(InputParam);
    }
}

// Destructor for Deque class
template<class S>
Deque<S>::~Deque(){
    clear();
}

// Push Data to the back of Deque
template<class S>
void Deque<S>::push_back(S InputParam){
    struct Node<S> *sNewNode = new Node<S>(InputParam);
    sNewNode->mData = InputParam;
    if(empty()){
        mHead = sNewNode;
        mTail = sNewNode;
    }
    else{
        mTail->mNext = sNewNode;
        sNewNode->mPrev = mTail;
        mTail = sNewNode;
    }
    mSize_Deque++;
}

// Pop mData from the back of Deque
template<class S>
void Deque<S>::pop_back(){
    if(empty()){
        cout<<"Deque is already empty"<<endl;
    }
    else {
        struct Node<S>* sTemp = mTail;
        if(mHead == mTail){
            mHead = nullptr; 
            mTail = nullptr;
        }
        else{
            mTail = mTail->mPrev;
            mTail->mNext = nullptr;
        }
        delete sTemp;
        mSize_Deque--;
    }
}

// Push mData to the front of Deque
template<class S>
void Deque<S>::push_front(S InputParam){
    struct Node<S> *sNewNode = new Node<S>(InputParam);
    sNewNode->mData = InputParam;
    if(empty()){
        mHead = sNewNode; 
        mTail = sNewNode;
    }
    else{
        sNewNode->mNext = mHead;
        mHead->mPrev = sNewNode;
        mHead = sNewNode;
    }
    mSize_Deque++;
}

// Pop mData from the front of Deque
template<class S>
void Deque<S>::pop_front(){
    if(empty()){
        cout<<"Deque is already empty"<<endl;
    }
    else {
        struct Node<S>* sTemp = mHead;
        if(mHead == mTail){
            mHead = nullptr;
            mTail = nullptr;
        }
        else{
            mHead = mHead->mNext;
            mHead->mPrev = nullptr;
        }
        delete sTemp;
        mSize_Deque--;
    }
}

// Return mData at mHead
template<class S>
S Deque<S>::front(){
    return mHead->mData;
}

// Return mData at mTail
template<class S>
S Deque<S>::back(){
    return mTail->mData;
}

// Returns true if Deque is empty
template<class S>
bool Deque<S>::empty(){
    return 0 == mSize_Deque;
}

// Returns size of the Deque
template<class S>
int Deque<S>::size(){
    return mSize_Deque;
}

// Resize Deque
template<class S>
void Deque<S>::resize(int SizeParam, S DefaultParam, int DirectionParam){
    if(SizeParam < 0){
        cout<<"Invalid size provided."<<endl;
    }
    else if (DirectionParam != DequeMockMenu::Direction_Left && DirectionParam != DequeMockMenu::Direction_Right){
        cout<<"Invalid direction provided"<<endl;
    }
    else if (0 == SizeParam){
        clear();
    }
    else{
        uint sDifference;
        if(SizeParam > size()){
            sDifference = SizeParam-size();

            if(DequeMockMenu::Direction_Left == DirectionParam){
                while(sDifference--){
                    push_front(DefaultParam);
                }
            }
            else {
                while(sDifference--){
                    push_back(DefaultParam);
                }
            }
        }
        else{
            sDifference = size()-SizeParam;

            if(DequeMockMenu::Direction_Left == DirectionParam){
                while(sDifference--){
                    pop_front();
                }
            }
            else {
                while(sDifference--){
                    pop_back();
                }
            }
        }
    }
}

// Clear Deque
template<class S>
void Deque<S>::clear(){
    while(!empty()){
        pop_back();
    }
}

// [] operator overloading
template<class S>
S Deque<S>::operator[](int SizeParam){
    struct Node<S> *sTemp = mHead;
    while(SizeParam--){
        sTemp = sTemp->mNext;
    }
    return sTemp->mData;
}

#endif // DEQUE_H_
 