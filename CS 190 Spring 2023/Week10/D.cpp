#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> matrix;
vector<vector<int>> dp;
int matrixSize;
int largestMatrix = 0;
int tempLargestMatrix = 0;

bool isValidMatrix(int newX, int newY){
    for (int row = newX; row > newX - tempLargestMatrix; row--){
        if (matrix.at(row - 1).at(newY) == 1)
            return false;
    }
    for (int col = newY; col > newY - tempLargestMatrix; col--){
        if (matrix.at(newX).at(col - 1) == 1)
            return false;
    }
    return true;
}

int main(){
    cin >> matrixSize;
    for (int i = 0; i < matrixSize; i++){
        matrix.push_back(vector<int>());
        dp.push_back(vector<int>());
        for (int j = 0; j < matrixSize; j++){
            int temp;
            cin >> temp;
            matrix.at(i).push_back(temp);
            dp.at(i).push_back(0);
        }
    }
    
    for (int i = 0; i < matrixSize; i++){ //initialize left dp column
        if (matrix.at(i).at(0) == 1){
            dp.at(i).at(0) = 1;
            tempLargestMatrix = 1;
        }
    }
    for (int i = 0; i < matrixSize; i++){ //initialize top dp row
        if (matrix.at(0).at(i) == 1){
            dp.at(0).at(i) = 1;
            tempLargestMatrix = 1;
        }
    }
    for (int i = 1; i < matrixSize; i++){
        for (int j = 1; j < matrixSize; j++){
            if (matrix.at(i).at(j) == 1 && dp.at(i - 1).at(j - 1) >= 1 && isValidMatrix(i,j)){
                dp.at(i).at(j) = dp.at(i-1).at(j-1) + 1;
            }
            else if (matrix.at(i).at(j) == 1){
                dp.at(i).at(j) = 1;
            }
            else if (matrix.at(i).at(j) == 0) {
                dp.at(i).at(j) = 0;
            }
            tempLargestMatrix = dp.at(i).at(j);
            largestMatrix = max(largestMatrix, tempLargestMatrix);
        }
    }
    //cout << endl << endl;

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            //cout << dp.at(i).at(j) << " ";
        }
        //cout << endl;
    }
    
    cout << largestMatrix << endl;

    return 0;
}