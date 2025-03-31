#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<long long> list (51);

string helper(long long k, long long l, long long r) {
    if (k == 1) {
        string temp = "ABC";
        return temp.substr(l, r - l + 1);
    } else {
        vector<string> concat = {"", "", ""};
        long long prevLen = list[k - 1];
        if (l == 0) { // include A
            concat[0] = "A";
        }
        if (l <= 1 + prevLen && r >= 1 + prevLen) { // include B
            concat[1] = "B";
        }
        if (r == 2 + 2 * prevLen) { // include C
            concat[2] = "C";
        }
        
        string prevLeft = "";
        string prevRight = "";
        long long leftOffset = 1;
        long long rightOffset = 1 + prevLen;
        
        if (l < rightOffset && r > 0) { // find prev left
            prevLeft = helper(k - 1, max(0LL, l - leftOffset), min(r - leftOffset, list[k - 1] - 1));
        }
        
        if (r > rightOffset && l < 2 + 2 * prevLen) { // find prev right
            prevRight = helper(k - 1, max(0LL, l - rightOffset - 1), min(r - rightOffset - 1, list[k - 1] - 1));
        }
       
        return concat[0] + prevLeft + concat[1] + prevRight + concat[2];
    }
}

int main() {
    
    int cases;
    cin >> cases;
    
    list[1] = 3;
    
    for (long long i = 2; i < 51; i++) {
        list[i] = list[i - 1] * 2 + 3;
    }
    
    for (int i = 0; i < cases; i++) {
        long long k, l, r;
        cin >> k >> l >> r;
        cout << helper(k, l - 1, r - 1) << endl;
    }
    
    return 0;
}