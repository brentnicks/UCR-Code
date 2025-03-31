#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    map<pair<int,int>, int> mp;
    vector<pair<int,int>> list;

    int n, x, y;
    int bones = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        list.push_back(make_pair(x,y));
    }

    for (int i = 0; i < n; i++){
        mp.clear();
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (list.at(i).first == list.at(j).first){
                mp[{12345678,12345678}]++;
                bones = max(bones, mp[{12345678,12345678}]);
                continue;
            }
            int dx = list.at(j).first - list.at(i).first;
            int dy = list.at(j).second - list.at(i).second;
            int temp = __gcd(dx,dy);
            mp[{dx/temp,dy/temp}]++;
            bones = max(bones, mp[{dx/temp,dy/temp}]);
        }
    }
    cout << bones + 1;
    return 0;
}