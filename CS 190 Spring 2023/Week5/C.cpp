#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list;
    int size;
    cin >> size;
    
    for (int i = 0; i < size; i++){
        list.push_back(0);
    }
    for (int i = 0; i < list.size() - 1; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        list.at(temp1 - 1)++;
        list.at(temp2 - 1)++;
    }
    for (int i = 0; i < list.size(); i++){
        if (list.at(i) == 2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
