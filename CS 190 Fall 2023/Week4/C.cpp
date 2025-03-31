#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(){
    int variables;
    cin >> variables;
    set<int> usedVars;
    map<int,int> varMap;
    vector<int> array;

    for (int i = 0; i < variables; i++){
        int temp;
        cin >> temp;
        int factor = 1;
        if (usedVars.find(temp) == usedVars.end()){
            array.push_back(temp);
            usedVars.insert(temp);
            varMap[temp] += temp;
            continue;
        }
        else{
            while (usedVars.find(varMap[temp] + temp * factor) != usedVars.end()){
                factor++;
            }
            varMap[temp] += temp * factor;
            array.push_back(varMap[temp]);
            usedVars.insert(varMap[temp]);
            
        }
    }
    for (int i = 0; i < variables; i++){
        cout << array.at(i) << " ";
    }

    return 0;
}