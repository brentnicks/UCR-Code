#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool sortDesc(pair<double,int> a, pair<double,int> b){
    return (a.first < b.first);
}
int main(){
    int n, x1,y1,candies = 0,dist = 0;
    cin >> n;
    cin >> x1 >> y1;
    candies += y1;
    for (int i = 0; i < n - 1; i++){
        int x2,y2;
        cin >> x2 >> y2;
        candies += y2;
        dist += abs(x1-x2);
        x1 = x2;
        y1 = y2;
    }
    //cout << candies << " " << dist << endl;
    cout << (candies - dist)/n;
    return 0;
}