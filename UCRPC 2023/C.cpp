#include <iostream>

using namespace std;

int main(){
    string name, verb, object;
    cin >> name >> verb;
    getline(cin, object);
    object.erase(object.size() - 1);
    object.erase(0, 1);
    object.at(0) = toupper(object.at(0));
    cout << object << " " << verb << " " << name << '.';

    return 0;
}