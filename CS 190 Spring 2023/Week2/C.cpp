#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,r, p, c;
    
    vector<int> list;
    
    cin >> n >> r;
    
    for (int i = 0; i < n; i++){
        list.push_back(i + 1);
    }
    //cin >> p >> c;
    //list.erase(list.end() - p - c + 1, list.end() - p + 1);
    
    for (int i = 0; i < r; i++){
        cin >> p >> c;
        vector<int> temp;
        for (int j = 0; j < c; j++){
            temp.push_back(list.at(n - p - j));
            //cout << list.at(n - p - j) << " ";
        }
        /*
        for (int j = 0; j < temp.size(); j++){
        cout << temp.at(j) << " ";
        }
        cout << endl;
        */
        list.erase(list.end() - p - c + 1, list.end() - p + 1);
        for (int j = 0; j < temp.size(); j++){
            list.push_back(temp.at(j));
        }
    }
    /*
    for (int i = 0; i < list.size(); i++){
        cout << list.at(i) << " ";
    }
    */
    
    cout << list.back();
    

    return 0;
}
