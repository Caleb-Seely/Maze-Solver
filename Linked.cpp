/*
Linked.cpp

Caleb Seely     CS 121.Bolden    Maze HW     2/13/2018

Linked List implementation
*/
#include<iostream>
using namespace std;
#include "link.h"

void LinkedList :: AddNode(int x)
{
    NodePtr n;
    
    n = new node;

    n -> coord = x;
  
    count++;

    if ( head == NULL)
    {
        head = n;
        n->next = NULL;
    }
    else{
       NodePtr tmp = head;
       n->next = tmp;
       head = n;
    }   
}

int LinkedList :: FirstNode(int x)
{
    return head->coord;
}

void LinkedList :: DeleteNode(int x)
{
        NodePtr prev , curr = head;
     

        // while(curr != NULL && x>curr->coord )
        // {
        //     cout << "In the while" << endl;
        //     prev = curr;
        //     curr = curr-> next;
        // }   

        if (x == curr->coord)
        {
 
            if (curr == head)
                head = head->next;
            else
                prev->next = curr->next;

            delete curr;
            count --;
        }    
}

int LinkedList :: Size()
{
    return count;
}


