#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct teams{
    string name = "";
    vector<int> problems;
    int score = 0;
    int problemsSolved = 0;
    int timeOfLastAccepted = INT_MAX;
    friend bool operator <(const teams &lt, const teams &rt){
        if (lt.problemsSolved < rt.problemsSolved){
            return false;
        }
        else if (lt.problemsSolved == rt.problemsSolved && lt.score > rt.score){
            return false;
        }
        else if (lt.problemsSolved == rt.problemsSolved && lt.score == rt.score && lt.timeOfLastAccepted > rt.timeOfLastAccepted){
            return false;
        }
        else if (lt.name > rt.name && lt.problemsSolved == rt.problemsSolved && lt.score == rt.score && lt.timeOfLastAccepted == rt.timeOfLastAccepted){
            return false;
        }
        return true;
    }
};

int main()
{
    int n, p, k;
    vector<teams> t;
    cin >> n >> p >> k;
    for (unsigned i = 0; i < n; i++){
        teams temp;
        string tempString;
        cin >> tempString;
        temp.name = tempString;
        for (unsigned j = 0; j < p; j++){
            temp.problems.push_back(0);
        }
        t.push_back(temp);
    }
    for (int i = 0; i < k; i++){
        string name, judge;
        int problem, timePen;
        cin >> name >> problem >> timePen >> judge;
        if (judge == "AC"){
            for (int i = 0; i < n; i++){
                if (name == t.at(i).name && (t.at(i).problems.at(problem - 1) >= 0)){
                    t.at(i).problemsSolved += 1;
                    t.at(i).score += t.at(i).problems.at(problem - 1) + timePen;
                    t.at(i).problems.at(problem - 1) = -1;
                    t.at(i).timeOfLastAccepted = timePen;
                }
            }
        }
        else if (judge != "CE"){
            for (int i = 0; i < n; i++){
                if (name == t.at(i).name && t.at(i).problems.at(problem - 1) >= 0){
                    t.at(i).problems.at(problem - 1) += 20;
                }
            }
        }
    }
    sort(t.begin(),t.end());

    for (int i = 0; i < n; i++){
            cout << t.at(i).name << " " << t.at(i).problemsSolved << " " << t.at(i).score << endl;
    }
    return 0;
}
