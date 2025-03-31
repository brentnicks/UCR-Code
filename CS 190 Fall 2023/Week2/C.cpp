#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n, q;
        cin >> n >> q;
        vector<int> list;
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            list.push_back(x);
        }
        sort (list.begin(), list.end(), greater<int>());

        vector<int> prefixSum;
        prefixSum.push_back(list.at(0));
        for (int j = 1; j < list.size(); j++){
            prefixSum.push_back(prefixSum.at(j - 1) + list.at(j));
        }
        sort (prefixSum.begin(), prefixSum.end());
        for (int j = 0; j < q; j++){
            int target;
            cin >> target;
            auto index = lower_bound(prefixSum.begin(), prefixSum.end(), target);
            if (index == prefixSum.end()){
                cout << -1 << endl;
            } 
            else {
                cout << index - prefixSum.begin() + 1 << endl;
            }
        }
    }

    return 0;
}