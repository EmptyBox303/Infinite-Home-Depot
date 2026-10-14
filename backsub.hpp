#pragma once

#include <algorithm>
#include <string>
#include <iostream>
#include <format>
#include <vector>
#include <utility>


using namespace std;

const pair<int,int> JustifyCoords(const int x, const int y);

const vector<pair<int,int>> MakeLateralCoords(const int x, const int y);

const vector<pair<int,int>> MakeDiagonalCoords(const int x, const int y);



class Quotient{
public:
    long long numerator;
    long long denominator;

    Quotient(const long n, const long q) : numerator(n), denominator(q){}

    Quotient Recipricate(){
        return Quotient(denominator,numerator);
    }

};

class Product{
public:
    vector<Quotient> product;

    const double Evaluate(){
        if (product.size() == 0) return 1;

        double prod = 1;
        for(Quotient& q : product){
            prod *= q.numerator;
            if (prod == 0) return 0;
            prod /= (double)q.denominator;
        }
        return prod;
    }

    void Mult(const Quotient q){
        product.push_back(q);
    }

    const string print(){
        string ret;

        if (product.size() == 0) return "1";
        
        for(Quotient& q : product){
            ret += "(" + q.numerator + "/" + q.denominator + ")";
        }

        return ret;
    }
};

class Term{
public:
    pair<int,int> coordinate;
    vector<Product> coefficients;
    bool hasCoord;

    Term(bool b) : hasCoord(b){}

    void Add(const Product p){
        coefficients.push_back(p);
    }

    double Evaluate(){
        if (coefficients.size() == 0){
            return 1;
        }

        double sum = 0;

        for(Product& prod : coefficients){
            sum += prod.Evaluate();
        }

        return sum;
    }

    const string print(){
        string ret;

        if (hasCoord){
            ret += "E(" + coordinate.first + "," + coordinate.second + ")";
        }

        if (coefficients.size() == 0) return ret;

        ret += " * (";
        int track = 0;

        for(Prod& p : coefficients){
            if (track > 0){
                ret += "+ ";
            }
            ret += p.print();
            track ++;
        }

        ret += ")";
        return ret;
    }
};

class Equation{
public:
    vector<Term> lhs;
    vector<Term> rhs;

    void LeftAddTerm(const Term t){
        lhs.push_back(t);
    }
    void RightAddTerm(const Term t){
        rhs.push_back(t);
    }

    const string print(){
        string ret;

        int i = 0;
        for(Term& t : lhs){
            if (i > 0)
                ret += " + ";
            ret += t.print();
            i++;
        }

        ret += " = ";

        i = 0;
        for(Term& t : rhs){
            if (i > 0)
                ret += " + ";
            ret += t.print();
            i++;
        }

        return ret;
    }

    Equation Substitute(Equation& sub, pair<int,int> target){
        return *this;
        //check lhs and rhs
        //there may be a term that matches target
    } 

    vector<Term> SubstituteSide(Equation& sub, pair<int,int> target, bool left){
        const vector<Term>& searchRange = (left) ? lhs : rhs;

        return searchRange;
    }
};