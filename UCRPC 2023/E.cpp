#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    map<char,char> cipher;

    string inputCipher, inputPlain, code;
    cin >> inputCipher >> inputPlain >> code;

    for (int i = 0; i < inputCipher.size(); i++){
        if (cipher.find(cipher[inputCipher.at(i)]) == cipher.end()){ // if cipher does not exist in encryption
            cipher[inputCipher.at(i)] = inputPlain.at(i);
        }
        else if (cipher[inputCipher.at(i)] != inputPlain.at(i)){ // if cipher is in the wrong place
            cout << "Failed";
            return 0;
        }
    }
    if (cipher.size() != 26){
        cout << "Failed";
        return 0;
    }
    /*
    cout << endl;
    auto it = cipher.begin();
    while (it != cipher.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
    */
    for (int i = 0; i < code.size(); i++){
        cout << cipher[code.at(i)];
    }

    return 0;
}