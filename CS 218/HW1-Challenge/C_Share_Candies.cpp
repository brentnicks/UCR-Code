#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

bool isValid(int target, vector<pair<long long, long long>> pos) {
    int n = pos.size();

    int left = 0;
    for (int i = 0; i < n; i++) {
        while (left < n && pos[left].second >= target) {
            left++;
            if (left >= n) {
                break;
            }
        }
        if (pos[i].second > target) {
            long long needed = target - pos[left].second;
            long long toSpare = pos[i].second - target;
            long long dist = pos[i].first - pos[left].first;
            if (toSpare > dist) {
                pos[left].second += min(needed, toSpare - dist);
                pos[i].second -= min(needed + dist, toSpare);
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

    // long long dist = 0;

    // for (int i = 0; i < n - 1; i++) {
    //     dist += abs(pos[i + 1] - pos[i]);
    // }

    // cout << floor((candy - dist) / (n * 1.0L));

    cout << isValid(450, pos) << endl;

    return 0;
}