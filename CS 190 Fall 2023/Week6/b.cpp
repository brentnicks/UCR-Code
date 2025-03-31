#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), greater<int>());

    cin >> n;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cout << v.at(temp - 1) << endl;
    }

    return 0;
}