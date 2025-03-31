#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp != -1){
            a[i] = temp - 1;
        }
        else{
            a[i] = temp;
        }
    }
    int treeSize = 1;
    for (int i = 0; i < n; i++){
        int tempTreeSize = 1;
        int currentIndex = i;
        while (a[currentIndex] != -1){
            currentIndex = a[currentIndex];
            tempTreeSize++;
        }
        treeSize = max(treeSize, tempTreeSize);
    }
    cout << treeSize << endl;

    return 0;
}