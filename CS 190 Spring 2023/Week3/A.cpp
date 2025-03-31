#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

bool sortDesc(pair<double,int> a, pair<double,int> b){
    return (a.first < b.first);
}
int main(){
    int n, s;
    cin >> n >> s;
    cout << fixed;
    cout << setprecision(7);
    vector<pair<double,int>> list;
    for (int i = 0; i < n; i++){
        int x,y,val;
        cin >> x >> y >> val;
        list.push_back({sqrt(pow(x,2) + pow(y,2)), val});
    }
    
    sort(list.begin(),list.end(), sortDesc);
    for (int i = 0; i < list.size(); i++){
        s += list.at(i).second;
        if (s >= 1000000){
            cout << list.at(i).first;
            return 0;
        }
    }
    cout << "-1";
    
    /*
    for (int i = 0; i < list.size(); i++){
        cout << list.at(i).first << " " << list.at(i).second << endl;
    }
    */
    return 0;
}