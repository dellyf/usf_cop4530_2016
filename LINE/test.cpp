#include <iostream>
#include "line.h"
using namespace std;

int main() {

	Line L(21, 42);
	Line K(40, 80);
	double a;

	try {
		cout << "X coor: " << L.intersect(K) << endl;
	}

	catch (EqualLines& err) {
		cout << err.getMessage() << endl;
	}

	catch (ParallelLines& err) {
		cout << err.getMessage() << endl;
	}
	cin.get();
	return 0;

}
