#include <iostream>

using namespace std;

int main(){

    int yes = 0, no = 0;
    bool sheld;

    string temp = "";

    for (int i = 0; i < 4; i++){
        cin >> temp;
        if (temp.at(0) == 'S'){
            cin >> temp;
            if (temp.at(temp.size()-1) == 's'){
                sheld = true;
                yes++;
            }
            else {
                sheld = false;
                no++;
            }
        }
        else {
            cin >> temp;
            if (temp.at(temp.size()-1) == 's'){
                yes++;
            }
            else no++;
        }
    }

    if (yes > no) cout << "yes";
    else if (yes == no && sheld) cout << "yes";
    else if (yes == no && !sheld) cout << "no";
    else cout << "no";

    return 0;
}