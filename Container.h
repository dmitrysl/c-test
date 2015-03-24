//
// Created by DmitriyS on 12/03/2015.
//

#ifndef _TEST2_CONTAINER_H_
#define _TEST2_CONTAINER_H_


class Container
{
public:
    virtual ~Container() {};
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
};


#endif //_TEST2_CONTAINER_H_
