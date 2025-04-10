#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

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
    // if (list.size() == 1) {
    //     return list[0];
    // }
    if (mp[target]) {
        return mp[target];
    }
    int begin = l, end = r;
    int pivotIndex = rand() % (r - l + 1) + l;
    int pivotVal = list[pivotIndex];
    while (l < r) {
        while (list[l] < pivotVal) {
            // if (prev.find({l, pivotIndex}) != prev.end()) {
            //     if (prev[{l, pivotIndex}] == '<') {
            //         l++;
            //         continue;
            //     } else if (prev[{l, pivotIndex}] == '>') {
            //         break;
            //     }
            // }
            cout << "? " << list[l] << " " << pivotVal << endl;
            cout.flush();
            string input;
            cin >> input;
            if (input == "x") {
                return -1;
            } else if (input == "<") {
                l++;
                prev[{l, pivotIndex}] = '<';
                prev[{pivotIndex, l}] = '>';
            } else if (input == ">") {
                prev[{l, pivotIndex}] = '>';
                prev[{pivotIndex, l}] = '<';
                break;
            }
        }
        while (list[r] > pivotVal) {
            cout << "? " << list[r] << " " << pivotVal << endl;
            cout.flush();
            string input;
            cin >> input;
            if (input == "x") {
                return -1;
            } else if (input == ">") {
                r--;
                prev[{r, pivotIndex}] = '>';
                prev[{pivotIndex, r}] = '<';
            } else if (input == "<") {
                prev[{r, pivotIndex}] = '<';
                prev[{pivotIndex, r}] = '>';
                break;
            }
        }
        if (l < r) {
            cout << "swap " << l << " " << r << endl;
            swap(list[l], list[r]);
            cout << "list: ";
            for (int i : list) {
                cout << i << " ";
            }
            cout << endl;
            l++;
            r--;
        }
    }
    mp[pivotIndex] = pivotVal;

    if (l < target) {
        return quick_select(list, mp, prev, pivotIndex + 1, end, target);
    } else if (l > target) {
        return quick_select(list, mp, prev, begin, pivotIndex - 1, target);
    } else {
        return list[l];
    }
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
                for (auto it : mp) {
                    if (it.first < j - 1) {
                        l = it.first;
                    } else if (it.first > j - 1) {
                        r = it.first;
                    }
                }
                int num = quick_select(list, mp, prev, l, r, j - 1);
                if (num == -1) {
                    return 0;
                }
                ans.push_back(num);
            }
        }
        cout << "! ";
        for (int j = 0; j < ans.size() - 1; j++) {
            cout << ans[j] << " ";
        }
        cout << ans[ans.size() - 1] << endl;
    }

    return 0;
} 