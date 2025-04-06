#include <iostream>
#include <vector>

using namespace std;

// normal version of quick_select
// int quick_select(vector<int> list, int l, int r, int target) {
//     int pivot = r;
//     int j = l;
//     for (int i = l; i < r; i++) {
//         if (list[i] <= list[pivot]) {
//             swap(list[i], list[j]);
//             j++;
//         }
//     }
//     swap(list[j], list[pivot]);
//     if (j == target) {
//         return list[j];
//     } else if (j > target) {
//         return quick_select(list, l, j - 1, target);
//     } else if (j < target) {
//         return quick_select(list, j + 1, r, target);
//     }
// }

int quick_select(vector<int>& list, int l, int r, int target) {
    int pivot = r;
    int j = l;
    for (int i = l; i < r; i++) {
        cout << "? " << i + 1 << " " << pivot + 1 << endl;
        cout.flush();
        string input;
        cin >> input;
        if (input == "<") {
        // if (list[i] <= list[pivot]) {
            swap(list[i], list[j]);
            j++;
        }
    }
    swap(list[j], list[pivot]);
    if (j == target) {
        return list[j];
    } else if (j > target) {
        return quick_select(list, l, j - 1, target);
    } else if (j < target) {
        return quick_select(list, j + 1, r, target);
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
        vector<int> list(n);
        for (int j = 0; j < n; j++) {
            list[j] = j + 1;
        }
        vector<int> ans;
        for (int j = 1; j < n; j *= 2) {
            ans.push_back(quick_select(list, 0, n - 1, j - 1));
        }
        cout << "! ";
        for (int j = 0; j < ans.size() - 1; j++) {
            cout << ans[j] << " ";
        }
        cout << ans[ans.size() - 1] << endl;
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    return 0;
} 