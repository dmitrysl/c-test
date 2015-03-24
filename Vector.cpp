//
// Created by DmitriyS on 12/03/2015.
//

#include "Vector.h"
#include <bits/stl_algobase.h>

class Vector
{
public:
    Vector(std::initializer_list<double> list) : elements{new double[list.size()]}, sz{list.size()}
    {
        std::copy(list.begin(), list.end(), elements);
    }
    Vector(unsigned int s) : elements{new double[s]}, sz{s}
    {
        for (int i = 0; i != s; ++i)
        {
            elements[i] = 0;
        }
    }
    ~Vector()
    {
        delete[] elements;
    }
    double& operator[](int i)
    {
        return elements[i];
    }
    unsigned int size() const
    {
        return sz;
    }
private:
    double* elements;
    unsigned int sz;
};