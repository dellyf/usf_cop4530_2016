#include "Maze.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;


void Maze::print_dfsExitPath()
{
   cout<<"DFS\n";
   stack<Position> path;
   Position current, nbr;
//   bool flag=false;
   setState(start, VISITED);
   path.push(start);
   current = start;
   
   if(start==exitpos)
   {
      cout << "Remy, here is a sequence of positions to escape the maze:\n";
               printBottomToTop(path);
      }
   //while ( !(current==exitpos))
   while ((!(path.empty())) && (!(current==exitpos)))
   {
   current=path.top();
   
	   if (getState(current.Neighbor(DOWN)) == OPEN)
	   {
		   setState(current.Neighbor(DOWN), VISITED);
		   current = current.Neighbor(DOWN);
		   path.push(current);
          if (current == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printBottomToTop(path);
                 break;
                 
		         }
	   }
       else if (getState(current.Neighbor(LEFT)) == OPEN)
	   {
		   setState(current.Neighbor(LEFT), VISITED);
		   current = current.Neighbor(LEFT);
		   path.push(current);
          if (current == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printBottomToTop(path);
                 break;
                 
		         }
	   }
       else if (getState(current.Neighbor(UP)) == OPEN)
	   {
		   setState(current.Neighbor(UP), VISITED);
		   current = current.Neighbor(UP);
		   path.push(current);
          if (current == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printBottomToTop(path);
                 break;
                 
		         }
	   }
       else if (getState(current.Neighbor(RIGHT)) == OPEN)
	   {
		   setState(current.Neighbor(RIGHT), VISITED);
		   current = current.Neighbor(RIGHT);
		   path.push(current);
          if (current == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printBottomToTop(path);
                 break;
                 
		         }
	   }
      else
      {
        path.pop();
      }
    }
    if (!(current==exitpos))
    {
      cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n" ;
    }
     
      
}

void Maze::printShortestPath()
{
     cout<<"BFS\n";
     queue<Position> Q;
     Position current, nbr;
     bool found=false;
   // Allocate the two dimensional predecessor array
   // The predecessor of Position P is given by
   // predecessor[P.row][P.col]
     Position** predecessor = new Position *[size];
     for(int i = 0; i < size; ++i) 
     {
        predecessor[i] = new Position[size];
        for(int j = 0; j < size; ++j)
	         predecessor[i][j] = NULLPOS;
     }
   // FILL IN MISSING CODE
     setState(start, VISITED);
     Q.push(start);

while ((!(Q.empty())) && (!(current==exitpos)))
   {
   current=Q.front();
   
   do
   {
	   if (getState(current.Neighbor(DOWN)) == OPEN)
	   {
       nbr = current.Neighbor(DOWN);
		   setState(nbr, VISITED);
		   Q.push(nbr);
          predecessor[current.getRow()][current.getCol()] = current;
          if (nbr == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                break;
                 
		         }
	   }
      if (getState(current.Neighbor(LEFT)) == OPEN)
	   {
       nbr = current.Neighbor(LEFT);
		   setState(nbr, VISITED);
		   Q.push(nbr);
          predecessor[current.getRow()][current.getCol()] = current;
          if (nbr == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                break;
                 
		         }
	   }
      if (getState(current.Neighbor(UP)) == OPEN)
	   {
       nbr = current.Neighbor(UP);
		   setState(nbr, VISITED);
		   Q.push(nbr);
          predecessor[current.getRow()][current.getCol()] = current;
          if (nbr == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                break;
                  
		         }
	   }
      if (getState(current.Neighbor(RIGHT)) == OPEN)
	   {
       nbr = current.Neighbor(RIGHT);
		   setState(nbr, VISITED);
		   Q.push(nbr);
          predecessor[current.getRow()][current.getCol()] = current;
          if (nbr == exitpos)
		         {
                 cout << "Remy, here is a sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                break;
                 
		         }
	   }
   }  while((!(getState(current.Neighbor(DOWN)) == OPEN)) && (!(getState(current.Neighbor(LEFT)) == OPEN)) && (!(getState(current.Neighbor(UP)) == OPEN)) && (!(getState(current.Neighbor(RIGHT)) == OPEN)));
      
        Q.pop();
      
  }
    if (!(nbr==exitpos))
    {
      cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n" ;
    }    
}

