#include <iostream>

using namespace std;

int main(){
    int c1, c2;
    int turns;
    cin >> c1 >> turns;
    c2 = c1;

    for (int i = 0; i < turns; i++){
        int p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        c1 -= p3 * p4;
        c2 -= p1 * p2;
        if (c1 <= 0 && c2 > 0){
            cout << "Team 2 wins at round " << i + 1 << '!' << endl;
            return 0;
        }
        else if (c1 > 0 && c2 <= 0){
            cout << "Team 1 wins at round " << i + 1 << '!' << endl;
            return 0;
        }
        else if (c1 <= 0 && c2 <= 0){
            cout << "It's a tie at round " << i + 1 << '!' << endl;
            return 0;
        }
    }
    cout << "Oh no!" << endl;

    return 0;
}