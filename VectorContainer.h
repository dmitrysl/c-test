//
// Created by DmitriyS on 12/03/2015.
//

#ifndef _TEST2_VECTORCONTAINER_H_
#define _TEST2_VECTORCONTAINER_H_

#include "Container.h"
#include "Vector.h"

class VectorContainer : public Container
{
    Vector v;
public:
    VectorContainer(int s);
    ~VectorContainer();
    double& operator[](int i);
    int size() const;
};


#endif //_TEST2_VECTORCONTAINER_H_
