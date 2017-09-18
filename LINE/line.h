#pragma once
#include <string>
using namespace std;

class RuntimeException { // generic run-time exception
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};

// All that is needed for the special exceptions is the inherited constructor and method.

class EqualLines : public RuntimeException
{
public:

};

class ParallelLines : public RuntimeException
{
public:

};


class Line {
public:
	Line(double slope, double y_intercept) : a(slope), b(y_intercept) {};
	double intersect(const Line L) const throw(ParallelLines,
		EqualLines);
	double getSlope() const { return a; };
	double getIntercept() const { return b; };


private:
	double a;
	double b;
};

