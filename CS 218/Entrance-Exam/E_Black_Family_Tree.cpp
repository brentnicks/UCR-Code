#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int max_members(vector<vector<int>> &nums, int person) {
    if (dp[person] != -1) {
        return dp[person];
    }
    int children = nums[person].size();
    int count = 1;
    for (int i = 0; i < children; i++) {
        count += max_members(nums, nums[person][i]);
    }
    dp[person] = count;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> nums(n);
    dp.resize(n, -1);
    
    for (int i = 0; i < n - 1; i++) {
        int person;
        cin >> person;
        nums[person].push_back(i + 1);
    }
    
    for (int i = 0; i < m; i++) {
        int traitor;
        cin >> traitor;
        dp[traitor] = 0;
    }
    
    int max_members_family = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) {
            max_members_family = max(max_members_family, max_members(nums, i));
        }
    }
    
    cout << max_members_family << "\n";
    
    
    
    return 0;
}