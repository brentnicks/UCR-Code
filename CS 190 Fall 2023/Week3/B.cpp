#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int nums;
        cin >> nums;
        vector<int> listIn;
        vector<int> listOut;
        for (int j = 0; j < nums; j++){
            int temp;
            cin >> temp;
            listIn.push_back(temp);
        }
        listOut.push_back(listIn[0]);
        for (int j = 1; j < nums; j++){
            if (listIn.at(j - 1) <= listIn.at(j)){
                listOut.push_back(listIn.at(j));
            }
            else {
                listOut.push_back(listIn.at(j));
                listOut.push_back(listIn.at(j));
            }
        }
        cout << listOut.size() << endl;
        for (int j = 0; j < listOut.size(); j++){
            cout << listOut.at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}