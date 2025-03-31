#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++){
        int Grace = 0, Liam = 0;
        int bills;
        cin >> bills;
        int counter = 1;
        bool isGraceTurn = true;
        bool isFirstTurn = false;
        while (bills >= counter){
            if (isGraceTurn){ // Grace's turn
                Grace += counter;
                bills -= counter;
                counter++;
                if (isFirstTurn){ //Grace's first turn
                    isFirstTurn = false;
                }
                else{ //Grace's second turn
                   isGraceTurn = false;
                   isFirstTurn = true;
                }
            }
            else{ // Liam's turn
                Liam += counter;
                bills -= counter;
                counter++;
                if (isFirstTurn){ //Liam's first turn
                    isFirstTurn = false;
                }
                else{ //Liam's second turn
                   isGraceTurn = true;
                   isFirstTurn = true;
                }
            }
        }
        if (isGraceTurn){
            Grace += bills;
        }
        else{
            Liam += bills;
        }
        cout << Grace << " " << Liam << endl;
    }
    return 0;
}