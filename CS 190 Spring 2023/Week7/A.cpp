#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> weights; // weight 1st, value 2nd
vector<vector<int>> memo;

int knapsack(vector<pair<int,int>>& weightList, int weight, int items){
    if (weight < 0){
        return INT_MIN;
    }
    if(items < 0 || weight == 0){
        return 0;
    }
    if (memo[items][weight] != -1){
        return memo[items][weight];
    }
    int include = weightList[items].second + knapsack(weightList, weight - weightList[items].first, items - 1);
    int exclude = knapsack(weightList, weight, items - 1);
    memo[items][weight] = max(include, exclude);
    return max(include, exclude);
}

int main(){
    int w, items;
    cin >> w >> items;
    int tempWeight, tempVal;
    for (int i = 0; i < items; i++){
        cin >> tempWeight >> tempVal;
        weights.push_back({tempWeight, tempVal});
    }
    for (int i = 0; i < items; i++){
        memo.push_back(vector<int>());
        for (int j = 0; j < w + 1; j++){
            memo.at(i).push_back(-1);
        }
    }
    cout << knapsack(weights, w, items - 1) << endl;

    return 0;
}