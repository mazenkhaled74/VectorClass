#ifndef MMVECTOR_VECTORHEADER_H
#define MMVECTOR_VECTORHEADER_H


#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

template<class type>
class mmVector
{
private:
    type* array;
    int size;
    int capacity;
public:
    mmVector(); // default constructor
    mmVector(int cap); // a constructor to intialize by a specific capacity and no elements so size = 0
    mmVector(const mmVector& other); // Copy constructor
    ~mmVector(); // destructor

    int Size(); // returns the size of the vector(number of elements)
    int Capacity();// returns the capacity of the vector(the allocated memory)
    bool empty();// returns true if the vector is empty(size=0)
    void resize(int newCap);// resizes the vector by newCap(allocates memory that equals newCap)
    void PushBack(type value);// adds value at the end of the container
    void PopBack();//removes the last element
    void insert(int pos, type value); // inserts element to position(pos)
    void erase(int pos);// removes element at position(pos)
    void erase(int pos1, int pos2);// removes elements in specific range
    void clear();// removes the content of the container
    
    typedef type* iterator;
    iterator begin(){return &array[0];};
    iterator end(){return &array[size];};

    mmVector& operator=(const mmVector<type>& other); // copy assignment
    bool operator==(const mmVector& other); // returns true if the content of two vectors is the same
    bool operator<(const mmVector& other); // returns true if the first different item in the first vector is smaller than the other
    int& operator[](int index); // allows access in the container by index
    template<class t>friend ostream& operator<<(ostream& out, mmVector<t>& Vect);
};
#endif