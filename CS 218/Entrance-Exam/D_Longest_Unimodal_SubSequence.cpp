#include <iostream>
#include <vector>

using namespace std;

void LIS(vector<int> &dp, vector<int> &nums, int n) {
    for (int i = 0; i < n; i++) {
        int tempMax = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                tempMax = max(tempMax, dp[j]);
            }
        }
        dp[i] = tempMax + 1;
    }
}

void LDS(vector<int> &dp, vector<int> &nums, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int tempMax = 0;
        for (int j = n - 1; j > i; j--) {
            if (nums[i] > nums[j]) {
                tempMax = max(tempMax, dp[j]);
            }
        }
        dp[i] = tempMax + 1;
    }
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums[i] = num;
    }
    
    vector<int> LISdp(n, 1);
    vector<int> LDSdp(n, 1);
    
    LIS(LISdp, nums, n);
    LDS(LDSdp, nums, n);
    
    int LUS = 0;
    
    for (int i = 0; i < n; i++) {
        LUS = max(LUS, LISdp[i] + LDSdp[i] - 1);
    }
    
    cout << LUS << endl;
    
    return 0;
}