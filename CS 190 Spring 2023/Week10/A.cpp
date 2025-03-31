#include <iostream>

using namespace std;

int main(){
    int nameCount;
    cin >> nameCount;
    int score[3] = {0,0,0};
    int student[3] = {1,1,1};
    
    for (int i = 0; i < nameCount; i++){
        int x,y;
        cin >> x >> y;
        x--;
        if (score[x] < y){
            score[x] = y;
            student[x] = i+1;
        }
    }
    cout << student[0] << endl << student[1] << endl << student[2] << endl;
    return 0;
}