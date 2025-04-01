#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> pos;
    long long candy = 0;

    for (int i = 0; i < n; i++) {
        long long p, c;
        cin >> p >> c;
        pos.push_back(p);
        candy += c;
    }

    long long dist = 0;

    for (int i = 0; i < n - 1; i++) {
        dist += abs(pos[i + 1] - pos[i]);
    }

    cout << floor((candy - dist) / (n * 1.0L));

    return 0;
}