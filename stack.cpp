/*
stack.cpp

Caleb Seely     CS 121.Bolden    Maze HW     2/13/2018

stack implementation
*/
#include <iostream>
#include<assert.h>

#include "stack.h"

Stack::Stack(){

}

Stack::~Stack(){
    while(!IsEmpty()){
        int n = topPtr.FirstNode(n);
        topPtr.DeleteNode(n);
       // cout <<"~Stack" << endl;
    }
}

void Stack ::Push(int x )
{
    topPtr.AddNode(x);
   // cout << "Push " << endl;
}

bool Stack:: IsEmpty()
{
    int n = topPtr.Size();
    return(n==0);              
}

int Stack :: Pop()
{  
    assert(!IsEmpty());
    int n = topPtr.FirstNode(n);
    topPtr.DeleteNode(n);
   // cout << "POP" << endl;
    return n;
}