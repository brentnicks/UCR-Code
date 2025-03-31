#include <iostream>
#include <vector>

using namespace std;


int main(){
    int studentCount;
    cin >> studentCount;
    
    vector<int> studentList;
    vector<int> studentPass;

    for (int i = 0; i < studentCount; i++){
        int tempPass;
        cin >> tempPass;
        studentList.push_back(tempPass);
    }

    for (int i = 0; i < studentCount; i++){
        studentPass.clear();
        for (int j = 0; j < studentCount; j++){
            studentPass.push_back(0);
        }
        studentPass.at(i)++;
        int curr = studentList.at(i);
        
        while (studentPass.at(curr - 1) < 2){
            studentPass.at(curr - 1)++;
            curr = studentList.at(curr - 1);
        }
        
        cout << curr << " ";
    }

    return 0;
}