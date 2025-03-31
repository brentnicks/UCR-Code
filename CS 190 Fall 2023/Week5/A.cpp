#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[i] = temp - 1;
    }
    for (int i = 0; i < n; i++){
        int currentIndex = i;
        set<int> s;
        int count = 1;
        while (count <= 3){
            if (a[currentIndex] == i && count == 3){
                cout << "YES";
                return 0;
            }
            currentIndex = a[currentIndex];
            count++;
        }
    }
    cout << "NO" << endl;
    return 0;
}