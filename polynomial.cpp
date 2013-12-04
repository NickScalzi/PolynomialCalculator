//Nick Scalzi (4558771)

#include "polynomial.h"
#include "conversions.h"

polynomial::polynomial()
{

}

void polynomial::addTerm(int c, int e )
{

    node* p = n; //pointer
    node* q = 0; //pointer to previous element

    if (c==0) return; //don't add the term if its coefficient is zero

    if (n==0)  //if this is the first term
    {
        n = new node(c,e);
        return;
    }

    else
    {

        while(e<p->getExponent() &&p->next!=0) //cycle through the polynomial until either we discover
        {
            q=p;
            p=p->next;
        }

        if(e==p->getExponent()) //if this exponent already exists
        {
            p->setCoefficient(p->getCoefficient()+c); //add the coefficients

            return;
        }
        else if(e>p->getExponent())
        {
            p = new node(c,e,p);

            if(q!=0) q->next = p; //if we're not at the front of the list, make sure the term before p, points to p.
            else n=p; //if we're at the front of the list, make n point to p, the new first term.

            return;
        }
        else
        {
            p->next = new node(c,e);

            return;
        }

    }

}

std::string polynomial::print()
{
    node* p =n;
    std::string s="";

    if (n==0) return "0"; //if the polynomial is empty, return 0

    while(p!=0)
    {
        s+= intToString(p->getCoefficient());
        s+="x^";
        s+=intToString(p->getExponent());
        if(p->next!=0)s+=" + ";
        p=p->next;
    }
    return s;
}

polynomial& polynomial::operator=(polynomial rhs)
{
    node* p=rhs.n;
    n = 0; //reset the polynomial linked list

    while(p!=0)
    {
        addTerm(p->getCoefficient(),p->getExponent()); //iteratively add the nodes from the rhs polynomial
        p=p->next;
    }

    return *this;
}

polynomial& polynomial::operator+(polynomial rhs)
{
    node* p=rhs.n;
    polynomial r = *this;

    while(p!=0)
    {
        r.addTerm(p->getCoefficient(),p->getExponent());
        p=p->next;
    }

    return r;
}


polynomial& polynomial::operator-(polynomial rhs)
{
    node* p=rhs.n;
    polynomial r = *this;
    while(p!=0)
    {

        r.addTerm(-1*(p->getCoefficient()),p->getExponent());
        p=p->next;
    }

    return r;
}
