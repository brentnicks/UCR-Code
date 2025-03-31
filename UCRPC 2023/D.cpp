#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int monte;
    cin >> monte;
    n--;
    set<int> list;
    list.insert(monte);

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        list.insert(temp);
    }

    n++;
    
    /*
    cout << endl;
    for (auto it : list){
        cout << it << " ";
    }
    cout << endl;
    */

    auto pos = list.find(monte);
    int index = distance(list.begin(), pos);
    //cout << index + 1 << endl;
    double score = log2(n - (index + 1));
    //cout << score << endl;

    int ans = 1;
    while (ans < score){
        ans *= 2;
    }
    cout << ans;

    return 0;
}