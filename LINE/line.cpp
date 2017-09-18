// Programmer: D Fong 
// Last modification date:1/20/17

#include <iostream>
#include "line.h"

double Line::intersect(const Line L) const throw(ParallelLines,
	EqualLines)
{

	double other_intercept = L.getIntercept() - b;
	double other_slope = L.getSlope() - a;
	double x_coor = (other_intercept*-1) / other_slope;

	
		if (a == L.getSlope() && b == L.getIntercept())
		{
			//throw EqualLines("The lines are equal: infinite intersection"); 
			//throw "The lines are equal: infinite intersection";
			//throw EqualLines("The lines are equal: infinite intersection");
			RuntimeException err("The lines are equal: infinite intersection");
			EqualLines elre = reinterpret_cast<EqualLines&>(err);
			throw elre;
		}
		else if (a == L.getSlope())
		{
			//throw ParallelLines("The lines are parallel: no intersection");
			//throw "The lines are parallel: no intersection";
			//throw ParallelLines("The lines are parallel: no intersection");
			RuntimeException err("The lines are parallel: no intersection");
			ParallelLines plre = reinterpret_cast<ParallelLines&>(err);
			throw plre;
		}
		else{
			return x_coor;
		}
		
}

