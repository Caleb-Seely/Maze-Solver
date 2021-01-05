/*
stack.h

Caleb Seely     CS 121.Bolden    Maze HW     2/13/2018

stack class
*/
#include<iostream>
using namespace std;

#include "link.h"
class Stack
{
    public:
        Stack();
        ~Stack();

        void Push(int x);
        int Pop();
        bool IsEmpty();

    private:
        LinkedList topPtr;
};