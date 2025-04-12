#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> man(n);
    vector<int> woman(m);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        man[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        woman[i] = temp;
    }

    sort(man.begin(), man.end(), greater<int>());
    sort(woman.begin(), woman.end(), greater<int>());

    int pairs = 0;

    int i = 0;
    int j = 0;
    while (i < n && j + 1 < m) {
        if (woman[j] < man[i]) {
            pairs++;
            i++;
            j += 2;
        } else {
            j++;
        }
    }

    cout << pairs << endl;

    return 0;
}