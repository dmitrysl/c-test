//
// Created by DmitriyS on 12/03/2015.
//

#ifndef _TEST2_VECTOR_H_
#define _TEST2_VECTOR_H_


#include <initializer_list>

class Vector
{
public:
    Vector(std::initializer_list<double> list);
    Vector(unsigned int s);
    ~Vector();
    double& operator[](int i);
    unsigned int size() const;
private:
    double* elements;
    unsigned int sz;
};


#endif //_TEST2_VECTOR_H_
