#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases > 0) {
        cases--;
        int happy = 0;
        int extra = 0;
        int happyRows = 0;
        int n, r;
        cin >> n >> r;
        for (int i = 0; i < n; i++) {
            int fam;
            cin >> fam;
            happyRows += fam / 2;
            extra += fam % 2; 
        }
        happy += happyRows * 2;
        r -= happyRows;
                int solo = 2 * r - extra; // derived from r = (extra people - solo row people) / 2 + solo row people
                solo = min(solo, extra);
                happy += solo;
        cout << happy << endl;
    }

    return 0;
}