//---------- Position.h ----------------//
// Position class -
// represents a position within a grid  //
#ifndef __POSITION
#define __POSITION
#include <iostream>

using namespace std;

typedef enum{DOWN, LEFT, UP, RIGHT, NONE} direction;

direction next_direction(direction d);

class Position {
  public:
   static const int POSMAX = 22;
   Position():row(0),col(0) {};
   Position(int m) : row(m),col(m) {};
   Position(int r, int c):row(r),col(c) {};
   int getRow() const { return row;}
   int getCol() const { return col;}
   void input();

   Position Neighbor(direction d) const;

   bool operator==(const Position &other) const;

   void display(ostream & out) const;

   void input(istream & in);

  private:
   int row;
   int col;
};

ostream & operator<<(ostream &out,const Position &P);

istream & operator>>(istream &in, Position &P);

#endif
