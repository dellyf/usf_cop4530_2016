// AUTHOR: DFONG		U94257843

#include <cassert>
#include <iostream>
#include <string>

class RuntimeException // generic run-time exception
{
 protected:
  std::string errorMsg;
 public:
  RuntimeException(const std::string& err) { errorMsg = err; }
  std::string getMessage() const { return errorMsg; }
};

class InvalidIndex : public RuntimeException
{
 public:
 InvalidIndex(const std::string& err): RuntimeException(err) {};
};

template <class dynElem>
class dynarr {
  private:
    int capacity;
    dynElem *A;
  public:
    dynarr(): capacity(0), A(NULL){}
    dynarr(int N): capacity(N), A(new dynElem[N]){}
    dynarr(const dynarr<dynElem> &other); //COPY CONSTRUCTA
    ~dynarr(); //DESTRUCTA
    dynarr<dynElem> & operator=( const dynarr<dynElem> &other); //ASSIGNMENT
    dynElem & operator[](int ndx) throw(InvalidIndex); //APPARAYTA []
    int getCapacity(); 
    void reserve(int newcap);

};

template <class dynElem>
dynarr<dynElem>::dynarr(const dynarr<dynElem> &other)
{
	//A = other.A;
	capacity = other.capacity;
	A = new dynElem[capacity];

	for (int i = 0; i < capacity; i++)
	{
		A[i] = other.A[i];
	}


}

template <class dynElem>
dynarr<dynElem>::~dynarr()
{
	delete[] A;
}

template <class dynElem>
dynarr<dynElem> & dynarr<dynElem>::operator=( const dynarr<dynElem> &other)
{
	if (*this != other)
	{
		delete[] A;
		capacity = other.capacity;
		A = new dynElem[capacity];
		for (int i = 0; i < capacity; i++)
		{
			A[i] = other.A[i];
		}
	}
  delete *this;
}
  
template <class dynElem>
dynElem & dynarr<dynElem>::operator[](int ndx) throw(InvalidIndex)
{
  
  if (ndx < 0)
  {
    throw InvalidIndex("Array index is negative");
	//return A[ndx];
  }
  else if (ndx > capacity)
  {
	  throw InvalidIndex("Array index is too large");
	  //return A[ndx];
  }
  
	return A[ndx];
  
}

template <class dynElem>
int dynarr<dynElem>::getCapacity()
{
  return capacity;
}
  
template <class dynElem>
void dynarr<dynElem>::reserve(int newcap)
{	
	// if newcap <= capacity, does nothing; 
	if (capacity > newcap)
		return;

	// if capacity is 0, allocates a dynamic array of
	// capacity newcap and makes A point to that array;
	// otherwise allocates a new dynamic array newA of capacity 
	// newcap, copies values in A to newA, deletes A and sets
	// A equal to newA

	dynElem *newA = new dynElem[newcap];
	for (int i = 0; i < newcap; i++)
	{
		newA[i] = A[i];
	}
/*	if (A != NULL) delete[] A;

	A = newA;
	capacity = newcap;
*/
	
	if (capacity == 0)
	{
		A = new dynElem[newcap];
	}
	else 
	{
		
		newA = new dynElem[newcap];
		for (int i = 0; i < capacity; i++)
		{
			newA[i] = A[i];
			
		}
		delete[] A;
		A = newA;
		capacity = newcap;
	}
	
  
}


