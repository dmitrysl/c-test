//
// Created by DmitriyS on 12/03/2015.
//

#include <bits/algorithmfwd.h>
#include "Vector.h"

Vector::Vector(std::initializer_list<double> list) : elements{new double[list.size()]}, sz{list.size()}
{
    std::copy(list.begin(), list.end(), elements);
};

Vector::Vector(unsigned int s) : elements{new double[s]}, sz{s}
{
    for (int i = 0; i != s; ++i)
    {
        elements[i] = 0;
    }
};

Vector::~Vector()
{
    delete[] elements;
};

double& Vector::operator[](int i)
{
    return elements[i];
};

unsigned int Vector::size() const
{
    return sz;
};
