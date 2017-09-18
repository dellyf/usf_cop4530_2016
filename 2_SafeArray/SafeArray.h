#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include<iostream>
#include<cstdlib>

using namespace std;

template <class T> 
class SafeArray 
{

private:
	int firstValid;
	int firstInvalid;
	T *A;
	//int length;
	
public:   
	SafeArray<T> (int firstInvalidIndex);   
	SafeArray<T> (int firstValidIndex, int firstInvalidIndex);   
	T& operator[](int ndx);   
	int length();  
	
	// the copy constructor below:    
	SafeArray(const SafeArray&);
	
	// the overloaded assignment operator:    
	const SafeArray<T>& operator=(const SafeArray<T>&);

	// the destructor:     
	~SafeArray();

};

// ndx operator
template<class T>
T& SafeArray<T>::operator[](int ndx)
{
	  if (ndx >= firstInvalid)
	  {
	  	cout << "Index is too large";
	  	exit(1);
	  }
	  else
	  if (ndx < firstValid)
	  {
	  	cout << "Index is too small";
	  	exit(1);
	  }
	  else
	  return A[ndx];
}

//length
template <class T>int SafeArray<T>::length()
{
	  length = firstInvalid-firstValid;
  	return length; 
}

// destructor
template <class T>
SafeArray<T>::~SafeArray() 
{ 
	  delete[] A; 
}

// 2nd SafeArray
template<class T>
SafeArray<T>::SafeArray(int firstValidIndex, int firstInvalidIndex)
{
	  length = firstInvalidIndex - firstValidIndex;
	  A = new T[length];
}

// copy constructor
template <class T>
SafeArray<T>::SafeArray(const SafeArray<T> &other) 
{
	  firstValid = other.firstValid;   
	  firstInvalid = other.firstInvalid;
	  length() = other.length();
	  A = new T[length];

  	assert(A != NULL);
  	for (int i = 0; i < length; ++i)      
  		{A[i] = other.A[i]; }
}

// operator=
template <class T>
const SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& other)
{
	  if (this != &other) 
	  {
	  	delete[] A;      
	  	firstValid = other.firstValid;
	  	firstInvalid = other.firstInvalid;
      //length = firstInvalid - firstValid;
      length() = other.length();
	
    	A = new T[length];
	  	for (int i = 0; i < length; i++)         
		  	{A[i] = other.A[i]; }
	  }   
	  return *this;
}

// first SafeArray
template<class T>
SafeArray<T>::SafeArray(int firstInvalidIndex)
{
	  A = new T[firstInvalidIndex];
	
  	if (firstInvalidIndex < 0)
	  {
		  cout << "Index is too small" << endl;
		  exit(1);
	  }
}

#endif
