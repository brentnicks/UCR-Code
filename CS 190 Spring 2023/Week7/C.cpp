#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> input;
vector<vector<int>> memo;

int FindLongestPath(int x, int y){
    int pathLength = 1;
    if (memo.at(x).at(y) != -1){
        return memo.at(x).at(y);
    }
    if (y - 1 >= 0){
        if(input.at(x).at(y) > input.at(x).at(y-1)){
             pathLength = max(pathLength, FindLongestPath(x, y - 1) + 1);
        }
    }
    if (y + 1 < input.at(0).size()){
        if (input.at(x).at(y) > input.at(x).at(y+1)){
            pathLength = max(pathLength, FindLongestPath(x, y + 1) + 1);
        }
    }
    if (x - 1 >= 0){
         if (input.at(x).at(y) > input.at(x - 1).at(y)){
             pathLength = max(pathLength, FindLongestPath(x - 1, y) + 1);
         }
    }
    if (x + 1 < input.size()){
        if (input.at(x).at(y) > input.at(x + 1).at(y)){
            pathLength = max(pathLength, FindLongestPath(x + 1, y) + 1);
        }
    }
    memo.at(x).at(y) = pathLength;
    return pathLength;
}

int main(){
    int r, c, max = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        memo.push_back(vector<int>());
        input.push_back(vector<int>());
        for (int j = 0; j < c; j++){
            int temp;
            cin >> temp;
            input.at(i).push_back(temp);
            memo.at(i).push_back(-1);
            }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            int tempMax = FindLongestPath(i, j);
            if (tempMax > max){
                max = tempMax;
            }
        }
    }
    
    //max = FindLongestPath(pathLength, 2, 2);

    cout << max;


    return 0;
}