//Nick Scalzi

#include "node.h"

    node::node(int c , int e , node* n ){
    coefficient = c;
    exponent = e;
    next = n;
    }

    int node::getCoefficient()
    {
       return coefficient;
    }
    void node::setCoefficient(int x)
    {
        coefficient = x;
    }
    int node::getExponent()
    {
        return exponent;
    }
    void node::setExponent(int x)
    {
        exponent = x;
    }
