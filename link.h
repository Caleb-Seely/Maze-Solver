/*
link.h

Caleb Seely     CS 121.Bolden    Maze HW     2/13/2018

Linked List class
*/
#include<iostream>
using namespace std;

class LinkedList
{
    private:

        struct node{
            int coord;      
            node* next;
        };

        typedef node* NodePtr;
        NodePtr head;
        int count;        

    public:

        LinkedList()
        {
            head = NULL;
            count = 0;
        }

        ~LinkedList()
        {
            NodePtr p = head, n;

            while(p != NULL)
            {
                n = p;
                p=p->next;
                delete n;
            }
        }

    void AddNode(int x);

    void DeleteNode(int x);

    int FirstNode(int x);

    int Size();
};