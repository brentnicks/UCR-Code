#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;
vector<vector<int>> memo;
int problemAnswer;
int output = 0;


void VerifiableSolutionVoid(int index, int sum){
    if (index >= numbers.size()) return;
    
    if ((sum == problemAnswer) && (index == numbers.size() - 1)) output++;
    if (memo.at(index).at(sum) != - 1){
        output++;
    }
    if (sum += numbers.at(index) <= 20){
    sum += numbers.at(index);
    VerifiableSolutionVoid(index + 1, sum);
    memo.at(index).at(sum) = 1;
    }
    if (sum -= numbers.at(index) >= 0){
    sum -= numbers.at(index);
    VerifiableSolutionVoid(index + 1, sum);
    memo.at(index).at(sum) = 1;
    }
    
    return;
}

int VerifiableSolution(int index, int sum){
    int answer = 0;
    if (index >= numbers.size()) return answer;
    if (memo.at(index).at(sum) != - 1){
        return memo.at(sum).at(index);
    }
    if ((sum == problemAnswer) && (index == numbers.size() - 1)) answer++;
    else{
        if (sum += numbers.at(index) <= 20){
        sum += numbers.at(index);
        answer = max(answer, 1 + VerifiableSolution(index + 1, sum));
        }
        if (sum -= numbers.at(index) >= 0){
        sum -= numbers.at(index);
        answer = max(answer, 1 + VerifiableSolution(index + 1, sum));
        }
    }
    memo.at(index).at(sum) = answer;
    return answer;
}

int main(){
    int numberCount;
    cin >> numberCount;
    for (int i = 0; i < numberCount; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    problemAnswer = numbers.back();
    numbers.pop_back();

    for (int i = 0; i <= 100; i++){
        memo.push_back(vector<int>());
        for (int j = 0; j <= 1000; j++){
            memo.at(i).push_back(-1);
        }
    }
    VerifiableSolutionVoid(0,0);
    //cout << VerifiableSolution(0, 0) << endl;
    cout << output;

    return 0;
}