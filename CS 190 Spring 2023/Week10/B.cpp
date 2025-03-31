#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int money, items;
    cin >> money >> items;
    vector<int> prices;
    int out = 0;

    for (int i = 0; i < items; i++){
        int x;
        cin >> x;
        prices.push_back(x);
    }

    sort(prices.begin(), prices.end());

    for (int i = 0; i < items; i++){
        if (money >= prices[i]){
            money -= prices[i];
            out++;
        }
        else {
            cout << out << endl;
            break;
        }
    }

    return 0;
}