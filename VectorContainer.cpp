//
// Created by DmitriyS on 12/03/2015.
//

#include <stdexcept>
#include "VectorContainer.h"

class VectorContainer : public Container
{
    Vector v;
public:
    VectorContainer(int s) : v(s)
    {

    };
    ~VectorContainer()
    {

    }
    double& operator[](int i)
    {
        if (i >= size())
            throw std::out_of_range( "Array out of bounds." );
        return v[i];
    }
    int size() const
    {
        return v.size();
    }
};