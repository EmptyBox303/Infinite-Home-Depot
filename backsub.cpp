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
            
        }
    }

    return 0;
}