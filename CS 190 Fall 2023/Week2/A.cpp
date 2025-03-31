#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int cases;
    int n;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        cin >> n;
        vector<int> list;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            list.push_back(x);
        }

        sort(list.begin(), list.end());

        int smallest = list.at(0);
        int ans = 0;

        for (int i = 0; i < list.size(); i++){
            ans += list.at(i) - smallest;
        }

        cout << ans << endl;
    }

    return 0;
}