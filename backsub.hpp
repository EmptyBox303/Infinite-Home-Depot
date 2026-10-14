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
            ret += "(" + to_string(q.numerator) + "/" + to_string(q.denominator) + ")";
        }

        return ret;
    }
};

class Term{
public:
    pair<int,int> coordinate;
    vector<Product> coefficients;
    bool hasCoord;
    bool isReciprocal;

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

        return (isReciprocal) ? 1/sum : sum;
    }

    const string print(){
        string ret = "";

        if (hasCoord){
            ret += "E(" + to_string(coordinate.first) + "," + to_string(coordinate.second) + ")";
        }

        if (coefficients.size() == 0) return ret;

        ret += " * (";
        int track = 0;

        for(Product& p : coefficients){
            if (track > 0){
                ret += "+ ";
            }
            ret += p.print();
            track ++;
        }

        ret.push_back(')');
        if (isReciprocal) ret += "^-1";
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
    Equation(vector<Term> lhs, vector<Term> rhs) : lhs(lhs), rhs(rhs){}

    const vector<pair<int,int>> GetTargets(){
        vector<pair<int,int>> ret;
        for(Term& t : lhs){
            if (t.hasCoord){
                ret.push_back(t.coordinate);
            }
        }
        for(Term& t : rhs){
            if (t.hasCoord){
                ret.push_back(t.coordinate);
            }
        }
        return ret;
    }

    const Equation Substitute(Equation& sub, pair<int,int> target){
        
        vector<Term> left = SubstituteSide(sub,target,true);
        vector<Term> right = SubstituteSide(sub,target,false);
        return Equation(left,right);
        //check lhs and rhs
        //there may be a term that matches target
    } 

    const vector<Term> SubstituteSide(Equation& sub, pair<int,int> target, bool left){
        vector<Term>& searchRange = (left) ? lhs : rhs;

        for (Term& t : searchRange){
            if (!t.hasCoord || t.coordinate != target) continue;

            vector<Product> coefficients = t.coefficients;

            vector<Term>& subLeft = sub.lhs;
            vector<Term>& subRight = sub.rhs;


            //coefficients * target
            //target can be substituted by
            //convention: rhs is a coordinate term always, lhs is complex expression

        }

        return searchRange;
    }
};