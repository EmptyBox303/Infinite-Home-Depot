/* 
schema:
input a number n such that backsubstitution only happens up until(including)
coordinate sum up to that point

for example: ./backsub 7 runs simulation on coordinates: (1,2) (1,4), (2,3), (1,6), (2,5), (3,4)
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <format>
#include <vector>
#include <utility>

#include "backsub.hpp"

using namespace std;


int main(int argc, char* argv[]){
    cout << "This is backsub\n";

    if (argc < 2){
        cout << "usage: ./backsub n; exitting now\n";
        return 0;
    }

    int maxCoordSum = stoi(argv[1]);

    if (maxCoordSum <= 1){
        cout << "please input number larger than 1; exitting now\n";
        return 0;
    }

    int minCoordSum = (maxCoordSum % 2) + 2;

    for(int i = minCoordSum; i <= maxCoordSum; i += 2){
        for (int j = 1; j <= i/2; j++){

            int x = j;
            int y = i-j;

            auto

            cout << format("12 / 16 E({},{}) = 1 + ",x,y);
            for(int i = 0; i < )
            
        }
    }

    return 0;
}


const pair<int,int> JustifyCoords(int x, int y){

    if (x < 0) x = -x;
    if (y < 0) y = -y;

    pair<int,int> ret = {x,y};
    if (x > y) ret = {y,x}; 
    return ret;
}

const vector<pair<int,int>> MakeLateralCoords(const int x, const int y){
    auto right = JustifyCoords(x+2,y);
    auto left = JustifyCoords(x-2,y);
    auto up = JustifyCoords(x,y+2);
    auto down = JustifyCoords(x,y-2);

    vector<pair<int,int>> ret;
    if (right.first > 0 && right.second > 0) ret.push_back(right);
    if (left.first > 0 && left.second > 0) ret.push_back(left);
    if (up.first > 0 && up.second > 0) ret.push_back(up);
    if (down.first > 0 && down.second > 0) ret.push_back(down);

    return ret;
}

const vector<pair<int,int>> MakeDiagonalCoords(const int x, const int y){
    auto right = JustifyCoords(x+1,y+1);
    auto left = JustifyCoords(x+1,y-1);
    auto up = JustifyCoords(x-1,y+1);
    auto down = JustifyCoords(x-1,y-1);

    vector<pair<int,int>> ret;
    if (right.first > 0 && right.second > 0) ret.push_back(right);
    if (left.first > 0 && left.second > 0) ret.push_back(left);
    if (up.first > 0 && up.second > 0) ret.push_back(up);
    if (down.first > 0 && down.second > 0) ret.push_back(down);

    return ret;
}

