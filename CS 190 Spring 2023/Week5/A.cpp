#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list;
    vector<int> out;
    int size;
    cin >> size;
    size--;
    
    for (unsigned i = 0; i < size; i++){
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    int curr = list.at(list.size()-1);
    out.push_back(size + 1);
    while (out.at(out.size()-1) != 1){
        out.push_back(curr);
        if (curr >= 2) curr = list.at(curr - 2);
        else curr = 0;
    }
    
    for (int i = out.size()-1; i >= 0; i--){
        cout << out.at(i) << " ";
    }
    return 0;
}
