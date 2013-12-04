//Nick Scalzi (4558771)

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class node{
public:
    node(int c=0, int e=1, node* n=0);
    int getCoefficient();
    void setCoefficient(int x);
    int getExponent();
    void setExponent(int x);

    node* next;

private:
    int coefficient;
    int exponent;
};

#endif // NODE_H_INCLUDED
