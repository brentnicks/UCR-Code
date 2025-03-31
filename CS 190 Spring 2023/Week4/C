#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, t = 0;
    cin >> n >> m;
    vector<int> f;
    for (unsigned i = 0; i < n; i++){
        int temp;
        cin >> temp;
        f.push_back(temp);
    }
    reverse(f.begin(),f.end());
    
    while (f.size() > m){
        
        for (unsigned int i = 0; i < f.size(); i++){
        }

        int min = f.at(f.size() - 1);
        for (unsigned int i = f.size() - m; i < f.size(); i++){
            if (f.at(i) < min) min = f.at(i);
        }
        for (unsigned int i = f.size() - m; i < f.size(); i++){
            f.at(i) -= min;
        }
        t += min;
        for (unsigned int i = f.size() - m; i < f.size(); i++){
            if (f.at(i) <= 0){
                f.erase(f.begin() + i);
            }
        }
        for (unsigned int i = 0; i < f.size(); i++){
        }
    }
    sort(f.begin(),f.end());
    t += f.at(f.size()-1);
        
    cout << t;
    
    return 0;
}
