#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; i++){
        int numRocks;
        cin >> numRocks;
        int rock1;
        cin >> rock1;
        numRocks--;
        vector<int> rocks;
        for (int j = 0; j < numRocks; j++){
            int temp;
            cin >> temp;
            rocks.push_back(temp);
        }
        sort(rocks.begin(), rocks.end());

        for (int j = 0; j < rocks.size(); j++){
            if (rocks.at(j) > rock1){
                rock1 = ceil((rock1 + rocks.at(j) * 1.0)/2.0);
            }
        }
        cout << rock1 << endl;
    }

    return 0;
}