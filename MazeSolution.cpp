/*
MazeSolution.cpp

Caleb Seely     CS 121.Bolden    Maze HW     2/13/2018

>>g++ MazeSolution.cpp Linked.cpp Stack.cpp;
>>./a.out Maze00.txt; ./a.out Maze01.txt; ./a.out Maze02.txt

This program reads in a .txt file and outputs if the maze inside is solvable
*Updated 4/25/19
*Makefile and visual effects because I was bored on a bus to Oregon State. 
*Update 9/27/19
*Color and file input added bc I was bored on a bus to the Dellinger Invite.
*/
#include<iostream>
#include<fstream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
#include "stack.h"

void DeleteMem(int ySize, char** arr2D);

char** OpenMaze(int xSize, int ySize, char** arr2D, string file);

void PrintMaze(int ySize, int xSize, char** arr2D);

int main(int argc, char* argv[])
{
    Stack MazeStack;

    bool solved = false;
    bool possible = true;
    string file;

    char **arr2D;           //Char array of arrays, holds the maze dynamically
    int ySize, xSize;
    int xcor,ycor;
    ifstream infile;
    char path = 'O';

    //cout << "Please enter the file name (Maze00.txt | Maze01.txt | Maze02.txt)\n";
    //cin >> file;
    file = argv[1];
    cout << file << endl;
    
    infile.open(file.c_str());
    sleep(2);
    if(!infile)
    cout << "Ah something went wrong trying to open the file\n";

    infile >> ySize;        //Size of maze
    infile >> xSize;

    arr2D = OpenMaze( xSize, ySize, arr2D, file );

    for(int y = 0; y < ySize; y++)      //Find the starting coords
    {
        for(int x = 0; x < xSize; x++)
        {
            if ( arr2D[y][x] == 'S')
            {
                cout << "Starting point Y: " << y << " and X: " << x << endl;
                MazeStack.Push(x);
                MazeStack.Push(y);
            }
        } 
    }

    ycor =  MazeStack.Pop();           //Set starting coords
    xcor = MazeStack.Pop();
   
    //PrintMaze(ySize, xSize, arr2D);

    int y = ycor, x = xcor;     //Not necessary but for simplicity + copied from other code
    
    while(solved == false and possible == true)
    {
        if(y >= 0 && y < ySize-1)     //Down components;
        {
            if(arr2D[y+1][x] == '.')
            {
                arr2D[y+1][x]=path;
                MazeStack.Push(x);
                MazeStack.Push(y+1);
            }
            else if(arr2D[y+1][x] == 'G')
                solved = true;
        }

        if(y > 0 && y <= ySize )      //Up components
        {
            if(arr2D[y-1][x] == '.')
            {
                arr2D[y-1][x]=path;
                MazeStack.Push(x);
                MazeStack.Push(y-1);
            }
            else if(arr2D[y-1][x] == 'G')
                solved = true;
        }

        if(x > 0 && x <= xSize )         //Left <-
        {
            if(arr2D[y][x-1] == '.')
            { 
                arr2D[y][x-1]=path;
                MazeStack.Push (x-1);
                MazeStack.Push(y);
            }
            else if(arr2D[y][x-1] == 'G')
                solved = true;
        }

        if(x >= 0 && x < xSize-1 )      //Right ->
        {
            if(arr2D[y][x+1] == '.')
            {
                arr2D[y][x+1]=path;
                MazeStack.Push(x+1);
                MazeStack.Push(y);
            }
            else if(arr2D[y][x+1] == 'G')
                solved = true;     
        }

        if (solved)
            break;

        if(MazeStack.IsEmpty())
        {
            possible = false;
            cout << "Ran out of moves because the stack is empty\n";
            break;
        }       
   PrintMaze(ySize, xSize, arr2D); 
   //sleep(1);
   system("clear");
   cout << endl;      //Final product

        y = MazeStack.Pop();
        x = MazeStack.Pop();         
    }

    printf("\033[0m");
    if(solved)
    cout << "Yes it can be solved! :)" << endl;

    if(!possible)
    cout << "No it can not be solved! :(" << endl;

   PrintMaze(ySize, xSize, arr2D);       //Final product

    DeleteMem( ySize,  arr2D);
    
}   

char** OpenMaze(int xSize, int ySize, char** arr2D,string file)
{
    char hold;
    ifstream infile;
    infile.open(file.c_str());

    if(!infile)
    cout << "Ah something went wrong trying to open the file\n";

    infile >> ySize;
    infile >> xSize;

    cout << "Size: " << ySize << " * " << xSize << endl;;

    arr2D = new char*[ySize];

    for(int i = 0; i < ySize; i++)
    {
        arr2D[i] = new char[xSize];
         if(arr2D[i] == NULL)
         cout <<"AH something went wrong allocating memory\n";

    } 

    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
        {
            infile >> arr2D[i][j] ;
        }
     
    }
    return arr2D;
}

void PrintMaze(int ySize, int xSize, char** arr2D)
{
    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
        {
            if(arr2D[i][j] == 'O'){printf("\033[1;31m");}
            else if(arr2D[i][j] == 'S' || arr2D[i][j] == 'G' ){printf("\033[1;32m");}
            else
            {
                printf("\033[0m");
            }
            
            cout <<  arr2D[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteMem(int ySize, char** arr2D)
{
    for (int i = 0; i < ySize; i++)
    {
        delete arr2D[i];
    }

    delete [] arr2D;
}