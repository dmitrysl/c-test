//
// Created by DmitriyS on 12/03/2015.
//

#include <stdexcept>
#include "VectorContainer.h"

VectorContainer::VectorContainer(int s) : v(s)
{

};

VectorContainer::~VectorContainer()
{

};

double& VectorContainer::operator[](int i)
{
    if (i >= size())
        throw std::out_of_range( "Array out of bounds." );
    return v[i];
};

int VectorContainer::size() const
{
    return v.size();
};
