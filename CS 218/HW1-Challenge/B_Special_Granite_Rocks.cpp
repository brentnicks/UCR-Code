#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

int quick_select(vector<int>& list, unordered_map<int, int>& mp, unordered_map<pair<int, int>, char, pair_hash>& prev, int l, int r, int target) {
    int pivot = r;
    int j = l;
    for (int i = l; i < r; i++) {
        // if (prev.count({list[i], list[pivot]})) {
        //     if (prev[{list[i], list[pivot]}] == '<') {
        //         cout << "used" << endl;
        //         swap(list[i], list[j]);
        //         j++;
        //     }
        // }
        // else {
            cout << "? " << list[i] << " " << list[pivot] << endl;
            cout.flush();
            string input;
            cin >> input;
            if (input == "<") {
                swap(list[i], list[j]);
                prev[{list[i], list[j]}] = '<';
                prev[{list[j], list[i]}] = '>';
                j++;
            } else if (input == "x") {
                return -1;
            } else {
                prev[{list[i],list[j]}] = '>';
                prev[{list[j], list[i]}] = '<';
            }
        }
    // }
    swap(list[j], list[pivot]);
    mp[j] = list[j];
    if (j == target) {
        return list[j];
    } else if (j > target) {
        return quick_select(list, mp, prev, l, j - 1, target);
    } else if (j < target) {
        return quick_select(list, mp, prev, j + 1, r, target);
    }
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n == -1) {
            return 0;
        }
        vector<int> list(n);
        unordered_map<int, int> mp;
        unordered_map<pair<int, int>, char, pair_hash> prev;

        for (int j = 0; j < n; j++) {
            list[j] = j + 1;
        }
        vector<int> ans;
        for (int j = 1; j <= n; j *= 2) {
            if (mp.find(j - 1) != mp.end()) {
                ans.push_back(mp[j - 1]);
                continue;
            } else {
                int l = 0, r = n - 1;
                // for (auto it : mp) {
                //     if (it.first < j - 1) {
                //         l = it.first;
                //     } else if (it.first > j - 1) {
                //         r = it.first;
                //     }
                // }
                int num = quick_select(list, mp, prev, l, r, j - 1);
                if (num == -1) {
                    return 0;
                }
                ans.push_back(num);
                // ans.push_back(quick_select(list, mp, l, r, j - 1));
            }
        }
        cout << "! ";
        for (int j = 0; j < ans.size() - 1; j++) {
            cout << ans[j] << " ";
        }
        cout << ans[ans.size() - 1] << endl;

        // for (int i : list) {
        //     cout << i << " ";
        // }
    }

    return 0;
} 