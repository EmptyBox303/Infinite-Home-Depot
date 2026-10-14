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

class Equation{

};

class Quotient{
public:
    long long numerator;
    long long denominator;

    Quotient(long n, long q) : numerator(n), denominator(q){}

    Quotient Recipricate(){
        return Quotient(denominator,numerator);
    }
};

class Product{
public:
    vector<Quotient> product;

    double Evaluate(){
        if (product.size() == 0) return 1;

        double prod = 1;
        for(Quotient q : product){
            prod *= q.numerator;
            if (prod == 0) return 0;
            prod /= (double)q.denominator;
        }
        return prod;
    }

    void Mult(Quotient q){
        product.push_back(q);
    }
};

class Term{
public:
    pair<int,int> coordinate;
    vector<Product> coefficients;

    void Add(Product p){
        coefficients.push_back(p);
    }

    double Evaluate(){
        if (coefficients.size() == 0){
            return 1;
        }

        double sum = 0;

        for(auto& prod : coefficients){
            sum += prod.Evaluate();
        }

        return sum;
    }
};