#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    
    int stepCount;
    cin >> stepCount;
    
    vector<int> steps;
    
    for (int i = 0; i < stepCount; i++) {
        int temp;
        cin >> temp;
        steps.push_back(temp);
    }
    unordered_map<int, int> counts;
    
    for (int i = 0; i < stepCount - 1; i++) {
        counts[steps[i + 1] - steps[i]]++;
    }
    
    int normVal = -1;
    int normCount = -1;
    
    for (auto it : counts) {
        if (it.second > normCount) {
            normVal = it.first;
            normCount = it.second;
        }
    }
    if (steps[1] - steps[0] != normVal && steps[2] - steps[1] == normVal) {
        cout << 1 << endl;
        return 0;
    }
    
    for (int i = 1; i < stepCount - 1; i++) {
        if (steps[i] - steps[i - 1] != normVal) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    if (steps[stepCount - 1] - steps[stepCount - 2] != normVal){
        cout << stepCount << endl;
        return 0;
    }
    return 0;
}