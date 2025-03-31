#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector<int> v;

    for (int i = 0; i < n; i++){
        v.push_back(n - i);
    }

    for (int i = 0; i < r; i++){
        int p, c;
        cin >> p >> c;
        vector<int> tempV;
        for (int j = 0; j < p - 1; j++){
            tempV.push_back(v.at(j));
        }
        for (int j = 0; j < c; j++){
            v.at(j) = v.at(j + p - 1);
        }
        for (int j = 0; j < p - 1; j++){
            v.at(j + c) = tempV.at(j);
        }
    }
    
    cout << v.at(0) << endl;

    return 0;
}