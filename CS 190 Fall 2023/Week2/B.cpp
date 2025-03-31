#include <iostream>
#include <string>

using namespace std;

int d(int n){
    int ans = 0;
    string newN = to_string(n);
    for (int i = 0; i < newN.length(); i++){
        ans += newN.at(i) - '0';
    }
    return ans;
}

int main(){

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++){
        int n;
        cin >> n;
        int p = 11;
        while (d(n) != d(n * p)){
            p++;
        }
        cout << p << endl;
    }

    return 0;
}