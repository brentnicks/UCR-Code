#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

bool isValid(int target, vector<pair<long long, long long>> pos) {
    int n = pos.size();

    for (int i = 0; i < n - 1; i++) {
        if (pos[i].second < target) {
            long long needed = target - pos[i].second;
            long long dist = pos[i + 1].first - pos[i].first;
            pos[i].second += needed;
            pos[i + 1].second -= (needed + dist);
        } else if (pos[i].second > target) {
            long long extra = target - pos[i].second;
            long long dist = pos[i + 1].first - pos[i].first;
            if (dist < extra) {
                pos[i].second -= extra;
                pos[i + 1].second += (extra - dist);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << pos[i].second << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        if (pos[i].second < target) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> pos;
    long long candy = 0;

    for (int i = 0; i < n; i++) {
        long long p, c;
        cin >> p >> c;
        pos.push_back({p, c});
        candy += c;
    }

    long long left = 0, right = candy / n + 1, mid = 0;
    long long ans = 0;
    // while (left < right) {
    //     mid = left + (right - left) / 2;
    //     if (isValid(mid, pos)) {
    //         ans = mid;
    //         left = mid + 1;
    //     } else {
    //         right = mid;
    //     }
    // }

    // cout << ans << endl;
    cout << isValid(333, pos) << endl;

    return 0;
}