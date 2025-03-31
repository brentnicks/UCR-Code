#include <iostream>
#include <algorithm>

using namespace std;

//if strings are same cout 0 and continue
//see how many differences going from forward and back
//take the min of that
//if the min is 0, then answer is 2
//else answer is diff + diff - 1
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int stringSize;
        cin >> stringSize;
        string s, t;
        cin >> s >> t;

        if (s == t){
            cout << 0 << endl;
            continue;
        }

        int forwardDiff = 0, backwardDiff = 0;
        for (int j = 0; j < stringSize; j++){
            if (s[j] != t[j]){
                forwardDiff++;
            }
        }

        for (int j = 0; j < stringSize; j++){
            if (s[j] != t[stringSize - j - 1]){
                backwardDiff++;
            }
        }

        if (forwardDiff == 1){
            cout << 1 << endl;
            continue;
        }
        else if ( backwardDiff == 1){
            cout << 2 << endl;
            continue;
        }
        if (forwardDiff <= backwardDiff && forwardDiff == stringSize){
            cout << forwardDiff * 2 - 1 << endl;
            continue;
        }
        if (forwardDiff > backwardDiff && backwardDiff == stringSize){
            cout << backwardDiff * 2 - 1 << endl;
            continue;
        }
        if (forwardDiff == 0 || backwardDiff == 0){
            cout << 2 << endl;
            continue;
        }
        

        if (forwardDiff < backwardDiff){ //use forward changes
            if (forwardDiff % 2 == 0){
                cout << forwardDiff * 2 << endl;
            }
            else{
                cout << forwardDiff * 2 - 1 << endl;
            }
        }
        else{ //use backward changes
            if (backwardDiff % 2 == 0){
                cout << backwardDiff * 2 - 1 << endl;
            }
            else{
                cout << backwardDiff * 2 << endl;
            }
            
        }
    }

    return 0;
}