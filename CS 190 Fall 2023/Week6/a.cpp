#include <iostream>

using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if (temp == 't') ans++;
        }
    }
    cout << ans << endl;

    return 0;
}