//Nick Scalzi (4558771)

#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
#include "node.h"
#include <string>
class polynomial{
public:
    polynomial();

    node* n = 0;

    void addTerm(int c=0, int e=1);

    polynomial& operator+(polynomial rhs);
    polynomial& operator-(polynomial rhs);
    polynomial& operator=(polynomial rhs);

    std::string print();

private:
};

#endif // POLYNOMIAL_H_INCLUDED
