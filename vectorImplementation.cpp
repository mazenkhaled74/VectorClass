#include "VectorHeader.h"
using namespace std;

template<class type>
mmVector<type>::mmVector()
{
    size = 0;
    capacity = 10;
    array = new type[capacity];
}

template<class type>
mmVector<type>::mmVector(int cap)
{
    size = 0;
    capacity = cap;
    array = new type[capacity];
}

template<class type>
mmVector<type>::mmVector(const mmVector& other)
{
    size = other.size;
    capacity = other.capacity;
    array = new type[capacity];

    for(int i=0; i<size; i++)
    {
        array[i] = other.array[i];
    }
}

template<class type>
mmVector<type>::~mmVector()
{
    delete[] array;
}

template<class type>
mmVector<type>& mmVector<type>::operator=(const mmVector<type>& other)
{
    if(other.size > size)
    {
        delete[] array;
        capacity = other.size + 10;
        array = new type[capacity];
    }

    size = other.size;
    for(int i=0; i<size; i++)
    {
        array[i] = other.array[i];
    }
    return *this;
}

template<class type>
int mmVector<type>::Size()
{
    return size;
}

template<class type>
int mmVector<type>::Capacity()
{
    return capacity;
}

template<class type>
bool mmVector<type>::empty()
{
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class type>
void mmVector<type>::resize(int newCap)
{
    capacity = newCap;
    type* temp = new type[capacity];
    for(int i=0; i<size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

template<class type>
bool mmVector<type>::operator==(const mmVector& other)
{
    if(size != other.size)
    {
        return false;
    }

    for(int i=0; i<size; i++)
    {
        if(array[i] != other.array[i])
        {
            return false;
        }
    }

    return true;
}

template<class type>
bool mmVector<type>::operator<(const mmVector& other)
{
    int limit = min(size, other.size);
    for(int i=0; i<limit; i++)
    {
        if(array[i] < other.array[i])
        {
            return true;
        }
    }
    return false;
}

template<class type>
void mmVector<type>::PushBack(type value)
{
    if(size < capacity)
    {
        array[size] = value;
        size++;
    }
    else
    {
        capacity *= 2;
        type* temp = new type[capacity];
        for(int i=0; i<size; i++)
        {
            temp[i] = array[i];
        }
        temp[size] = value;
        size++;
        delete[] array;
        array = temp;
    }
}

template<class type>
void mmVector<type>::PopBack()
{
    int check=0;
    try
    {
        if(size == 0)
        {
            throw 1;
        }
    }
    catch(int ex)
    {
        cout << "Vector is already empty\n";
        check = 1;
    }
    if(check == 0)
    {
        size--;
    }
}

template<class type>
int& mmVector<type>::operator[](int index)
{
    return array[index];
}

template<class type>
void mmVector<type>::insert(int pos, type value)
{
    int check = 0;
    try
    {
        if(pos < 0 || pos >= size)
        {
            throw 1;
        }
    }
    catch(int ex)
    {
        cout << "Out of range\n";
        check = 1;
    }

    if(check == 0)
    {
        if(size != capacity)
        {
            for(int i=size-1; i>=pos; i--)
            {
                array[i+1] = array[i];
            }
            array[pos] = value;
            size++;
        }
        else
        {
            capacity *= 2;
            type* temp = new type[capacity];
            for(int i=0; i<pos; i++)
            {
                temp[i] = array[i];
            }
            temp[pos] = value;
            for(int i=pos+1; i<size; i++)
            {
                temp[i] = array[i];
            }
            size++;
            delete[] array;
            array = temp;
        }
    }
}

template<class type>
void mmVector<type>::erase(int pos)
{
    int check = 0;
    try
    {
        if(pos < 0 || pos >= size)
        {
            throw 1;
        }
    }
    catch(int ex)
    {
        cout << "Out of range\n";
        check = 1;
    }
    if(check == 0)
    {
        for(int i=pos; i<size-1; i++)
        {
            array[i] = array[i+1];
        }
        size--;
    }
}

template<class type>
void mmVector<type>::erase(int pos1, int pos2)
{
    int check = 0;
    try
    {
        if(pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size)
        {
            throw 1;
        }
    }
    catch(int ex)
    {
        cout << "Out of range\n";
        check = 1;
    }
    if(check == 0)
    {
        type* temp = new type[capacity];
    
        for(int i=0; i<pos1; i++)
        {
            temp[i] = array[i];
        }

        int range = abs(pos2-pos1) + 1;
        for(int i=pos2+1; i<size; i++)
        {
            temp[abs(i-range)] = array[i];
        }

        delete[] array;
        array = temp;
        size -= range;
    }
}

template<class type>
void mmVector<type>::clear()
{
    size = 0;
}

template<class t>
ostream& operator<<(ostream& out, mmVector<t>& vect)
{
    for(int i=0; i<vect.size; i++)
    {
        out << vect.array[i] << " ";
    }
    return out;
}