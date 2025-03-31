#include <iostream>
#include <vector>
#include <unorded_map>
#include <queue>

using namespace std;

double money = 100.0;

long double cost(unorded_map<int, vector<pair<int,int>>> &m, int friends, int Yihan, int Xiaojun){
    vector<long double> friendCost(friends, 100000.0);
    vector<char> visited(friends, false);

    priority_queue<pair<long double, int>> pq;

    friendCost[Yihan] = money;
}

int main(){
    int friends, pairs;
    cin >> friends >> pairs;
    unordered_map<int, vector<pair<int,int>>> m;

    for (int i = 0; i < pairs; i++){
        int x, y, z;
        cin >> x >> y >> z;
        m[x - 1].push_back({y - 1, z});
        m[y - 1].push_back({x - 1, z});
    }

    int Yihan, Xiaojun;
    cin >> Yihan >> Xiaojun;



    return 0;
}