#include "Maze.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cassert>
 
using namespace std;


void Maze::print_dfsExitPath()
{
   stack<Position> path;
   Position current, nbr;
   // FILL IN MISSING CODE
   setState(start, VISITED);
   path.push(start);
   current = start;
   bool found = false;
   
   if (start == exitpos)
   {
     found = true;
     cout << "Remy, here is a sequence of positions to escape the maze:\n";
               printBottomToTop(path);
   }
   
    while (!(path.empty()) && (found==false))
    {
      direction d = DOWN;
      current = path.top();
      
      do{
      
      	if (getState(current.Neighbor(d))==OPEN)
      	{
        	setState(current.Neighbor(d), VISITED);
	        path.push(current.Neighbor(d));
        
        	if (current.Neighbor(d) == exitpos)
	        {
        	  found = true;
	          cout << "Remy, here is a sequence of positions to escape the maze:\n" ;
        	  printBottomToTop(path);
	          break;
       		 }
        break;
         
      	}
      
      	d=next_direction(d);
      
      	if(d==NONE)
      	{
        	path.pop();
      	}	
      
        }while(d!=NONE);
       
    }
     
     if (found == false)
      {
        cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n" ;
      }
}

void Maze::printShortestPath()
{
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
   Q.push(start);

    if(start==exitpos)
    {
      found = true;
      predecessor[start.getRow()][start.getCol()] = start;
      cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
  		cout << predecessor[start.getRow()][start.getCol()];       
    }

     while (!(Q.empty()) && (found==false))
    {
      direction d = DOWN;
      current = Q.front();
      
      do{
      
	      if (getState(current.Neighbor(d))==OPEN)
      	      {	
        	setState(current.Neighbor(d), VISITED);
        	Q.push(current.Neighbor(d));
        	predecessor[current.Neighbor(d).getRow()][current.Neighbor(d).getCol()] = current;
        	if (current.Neighbor(d) == exitpos)
        	{
          		found = true;
          		cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
          		printPredecessorPath(predecessor,current.Neighbor(d));
          		break;
        	}
            
      	      }
      	
	  d=next_direction(d);
          
          }while(d!=NONE);
       
	Q.pop();
    }
     
     if (found == false)
      {
        cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n" ;
      }


}

