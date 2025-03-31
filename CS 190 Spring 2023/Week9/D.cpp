#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
unordered_set<int> used;

bitset<500001> PrimeList;

const int MAXN = 1000001;
void Sieve(int n){
    PrimeList[0] = 1;
    for (int i = 3; i * i <= n; i += 2){
        if (PrimeList[i / 2] == 0){
            for (int j = 3 * i; j <= n; j += 2 * i){
                PrimeList[j / 2] = 1;
            }
        }
    }
}

void SetPrimes(int n){
    for (int i = 1; i <= n; i++){

        if (i == 2){ //item is not in set
            primes.push_back(i);
        }
        else if (i % 2 == 1 && PrimeList[i / 2] == 0){ //item is not in set
            primes.push_back(i);
        }
    }
}

bool Used(int n){
    for (int i = 0; i < primes.size(); i++){
        if (n % primes.at(i) == 0 && used.find(primes.at(i)) == used.end()){ //not found
            used.insert(primes.at(i));
        }
        else if (n % primes.at(i) == 0 && used.find(primes.at(i)) != used.end()){ //not found
            return true;
        }
    }
    return false;
}


int main(){
    Sieve(MAXN);
    SetPrimes(MAXN);

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        int nums;
        cin >> nums;
        bool flag = false;
        used.clear();
        for (int j = 0; j < nums; j++){
            int num;
            cin >> num;
            if (Used(num) && !flag){
                cout << "YES" << endl;
                flag = true;
            }
        }
        if (!flag){
            cout << "NO" << endl;
        }
    }
    return 0;
}