#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        int n, q;
        cin >> n >> q;
        vector<int> array;
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            array.push_back(temp);
        }
        int prefixSum = 0;
        for (int j = 0; j < array.size(); j++){
            prefixSum += array.at(j);
            array.at(j) = prefixSum;
        }
        for (int j = 0; j < q; j++){
            int low, high, target;
            cin >> low >> high >> target;
            int count = prefixSum;
            if (low >= 2) count -= array.at(high - 1) - array.at(low - 2);
            else count -= array.at(high - 1);
            count += target * (high - low + 1);
            if (count % 2 == 0){
                cout << "NO" <<  endl;
            }
            else cout << "YES" << endl;
        }
    }

    return 0;
}