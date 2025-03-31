#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

vector<int> table;

void FillTable(){
    for (int i = 1; i < 32768; i++){
        int tempVal = i;
        int tempOperations = 0;
        while (i > 0){
            if (tempVal % 2 == 0){
                tempVal /= 2;
                tempOperations += 1;
            }
            else{
                tempVal -= 1;
                tempOperations += 1;
            }
        }
        table.push_back(tempOperations);
    }
}

int OperationCount(int curr, int target){
    int operations = 0, temp1 = 999, temp2 = 999;
    if (curr == target){
        return operations;
    }
    else {
        if (curr % 2 == 0){
            curr /= 2;
            temp1 = 1 + OperationCount(curr, target);
        }
        else {
            curr -= 1;
            temp2 = 1 + OperationCount(curr, target);
        }
        operations = min(temp1, temp2);
        cout << operations << endl;
        return operations;
    }
}

int main(){
    int n;
    cin >> n;
    table.push_back(1); //fill in 0 element
    table.push_back(1); //takes 1 operation to get to 1: 0 + 1 = 1.
    cout << OperationCount(32768, 19);
    //FillTable();
    //cout << table.at(n);
    //for (auto i : table){
    //    cout << i << " ";
    //}
    /*
    for (int i = 0; i < n; i++){
        int curr;
        cin >> curr;
        while ()
    }
    */
    return 0;
}