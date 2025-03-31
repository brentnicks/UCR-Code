#include <iostream>
#include <cmath>

using namespace std;


int queenX, queenY;
int kingX, kingY;
int outX, outY;

    bool isNotWithin(){
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (queenX + i == outX && queenY + j == outY){
                    return false;
                }
            }
        }
        return true;
    }
int main(){
    int n;
    cin >> n;
    cin >> queenX >> queenY;
    cin >> kingX >> kingY;
    cin >> outX >> outY;
    if (kingX > queenX && outX > queenX && kingY > queenY && outY > queenY && abs(outX - queenX) != abs(outY - queenY) && isNotWithin()){ //king is top right of queen
        cout << "YES";
        return 0;
    }
    else if (kingX < queenX && outX < queenX && kingY > queenY && outY > queenY && abs(outX - queenX) != abs(outY - queenY) && isNotWithin()){ //king is top left of queen
        cout << "YES";
        return 0;
    } 
    else if (kingX > queenX && outX > queenX && kingY < queenY && outY < queenY && abs(outX - queenX) != abs(outY - queenY) && isNotWithin()){ //king is bot right of queen
        cout << "YES";
        return 0;
    } 
    else if (kingX < queenX && outX < queenX && kingY < queenY && outY < queenY && abs(outX - queenX) != abs(outY - queenY) && isNotWithin()){ //king is bot left of queen
        cout << "YES";
        return 0;
    } 
    cout << "NO";
    return 0;
}