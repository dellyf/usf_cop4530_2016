/*
  NAME: Jasmin Kaur  UID: U27924943
*/

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

   setState(start, VISITED);
   path.push(start);
   
   if(start==exitpos)
   {
      cout << "Remy, here is a sequence of positions to escape the maze:\n";
      printBottomToTop(path);
      return;
   }
   
   current = start;
   
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
   // Allocate the two dimensional predecessor array
   // The predecessor of Position P is given by
   // predecessor[P.row][P.col]
   Position** predecessor = new Position *[size];
   for(int i = 0; i < size; ++i) {
      predecessor[i] = new Position[size];
      for(int j = 0; j < size; ++j)
	 predecessor[i][j] = NULLPOS;
   }
   // FILL IN MISSING CODE
   bool found = false;
   setState(start, VISITED);
   
   if(start==exitpos)
   {
       cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
       printPredecessorPath(predecessor, start);
       return;
   }
   
   Q.push(start);

   while (!(Q.empty()) && (found==false))
   {
         current = Q.front();
      
	       if (getState(current.Neighbor(DOWN)) == OPEN)
	       {
             nbr=current.Neighbor(DOWN);
		         setState(nbr, VISITED);
             predecessor[nbr.getRow()][nbr.getCol()]=current;
		         if (nbr == exitpos)
		         {
			           found = true;
                 cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                 return;
		         }
             Q.push(nbr);
	       }
        
         if (getState(current.Neighbor(LEFT)) == OPEN)
	       {
             nbr=current.Neighbor(LEFT);
		         setState(nbr, VISITED);
             predecessor[nbr.getRow()][nbr.getCol()]=current;
		         if (nbr == exitpos)
		         {
			           found = true;
                 cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                 return;
		         }
             else
                 Q.push(nbr);
	       }
         
         if (getState(current.Neighbor(UP)) == OPEN)
	       {
             nbr=current.Neighbor(UP);
		         setState(nbr, VISITED);
             predecessor[nbr.getRow()][nbr.getCol()]=current;
		         if (nbr == exitpos)
		         {
			           found = true;
                 cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                 return;
		         }
             else
                 Q.push(nbr);
	       }
         
         if (getState(current.Neighbor(RIGHT)) == OPEN)
	       {
             nbr=current.Neighbor(RIGHT);
		         setState(nbr, VISITED);
             predecessor[nbr.getRow()][nbr.getCol()]=current;
		         if (nbr == exitpos)
		         {
			           found = true;
                 cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
                 printPredecessorPath(predecessor, nbr);
                 return;
		         }
             else
                 Q.push(nbr);
	       }
       
         Q.pop();
     }

     if (found == false)
     {
        cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n" ;
     }
}

