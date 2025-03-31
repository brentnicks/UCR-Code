#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool sortDesc(pair<int,int> a, pair<int,int> b){
    return (a.first < b.first);
}
int main(){
    int n, d;
    long long max = 0;
    cin >> n >> d;
    vector<pair<int,int>> list;
    for (int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        list.push_back({temp1, temp2});
    }
    /*
    for (int i = 0; i < n; i++){
        cout << list.at(i).first << " " << list.at(i).second << endl;
    }
    */

    sort(list.begin(),list.end(),sortDesc);

    int end = 0;
    long long tempMax = 0;

    for (int i = 0; i < list.size(); i++){
        for (int j = end; j < list.size(); j++){
            if (list.at(j).first - list.at(i).first >= d){
                tempMax -= list.at(i).second;
                end = j;
                break;
            }
            else{
                tempMax += list.at(j).second;
                if (tempMax >= max){
                  max = tempMax;  
                }
                if (j == list.size() - 1){
                    cout << max << endl;
                    return 0;
                }
            }
        }
    }
    cout << max << endl;
    

    return 0;
}