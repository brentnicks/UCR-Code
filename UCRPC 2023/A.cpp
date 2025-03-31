#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> m;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        m.push_back(a);
    }
    cout << endl;
    vector<int> diff;
    for (int i = 0; i < n - 1; i++){
        diff.push_back(m[i + 1] - m[i]);
        cout << diff[i] << " ";
    }
    map <int, int> mp;
    for (int i = 0; i < diff.size(); i++){
        mp[diff[i]]++;
    }
    int normalStairStepValue;
    for (auto it : mp){
        if (it.second > 1){
            normalStairStepValue = it.first;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < diff.size(); i++){
        if (diff[i] != normalStairStepValue){
            cout << i + 2;
            return 0;
        }
    }

    return 0;
}