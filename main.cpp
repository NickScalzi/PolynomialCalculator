//Nick Scalzi

#include <iostream>
#include <stdlib.h>
#include "node.h"
#include "polynomial.h"
#include "conversions.h"

using namespace std;
polynomial readPolynomial();

int main()
{
    polynomial p1;
    polynomial p2;
    polynomial t; //temp

    cout<<"Ex. 4^2 + 3^-6 - 3 -2^2" <<endl;
    cout << "First Polynomial:" << endl;
    p1 = readPolynomial();
    cout<<endl<<p1.print()<<endl<<endl;

    cout << "Second Polynomial:" << endl;
    p2 = readPolynomial();
    cout<<endl<<p2.print()<<endl<<endl;

    cout<<"--------"<<endl<<endl;

    cout << "P1 + P2:" << endl;
    t=p1;
    p1 = p1+p2;
    cout<<endl<<p1.print()<<endl<<endl;

    cout << "P1 - P2:" << endl;
    t = t-p2;
    cout<<endl<<t.print()<<endl;
    return 0;
}

polynomial readPolynomial()
{
    bool isNeg = false;
    int c=0;
    int e=1;
    int i=0;
    string text, temp;
    polynomial p;

    getline(cin,text);
    while(i<text.length())
    {
        if(text[i]=='-')
        {
            isNeg=true;
            i++;
        }

        while(i<text.length() && text[i]!='+' && text[i]!='-' && text[i]!='^')
        {
            if(text.at(i)>='0'&& text.at(i)<='9') temp+=text.at(i); //ignore non-digits
            i+=1;
        }

        c=stringToInt(temp);

        if(isNeg) c*=-1;
        temp="";
        isNeg=false;

        if(i<text.length() &&text.at(i)=='^')  //if the next digit is an exponent
        {
            i++;
            if(text[i]=='-')
            {
                isNeg=true;
                i++;
            }

            while(i<text.length() && text[i]!='+' && text[i]!='-')
            {
                if(text.at(i)>='0'&& text.at(i)<='9') temp+=text.at(i); //ignore non-digits
                i+=1;
            }

            e=stringToInt(temp);

            if(isNeg)
            {
                e*=-1;
            };

            temp="";
            isNeg=false;
        }

        p.addTerm(c,e);
        e=1;
        c=0;

        if(text[i]!='-') i+=1;//move to the next character, unless we need to establish that the next number is negative at the beginning of the loop
    }

    return p;
}
