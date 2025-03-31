#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<pair<int, bool>> list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        list.push_back(make_pair(temp, false));
    }
    

    return 0;
}