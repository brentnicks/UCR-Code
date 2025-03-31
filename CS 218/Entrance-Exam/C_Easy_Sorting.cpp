#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int candy;
    cin >> candy;
    
    vector<int> candies(candy);
    
    int one = 0, two = 0, three = 0;
    int c1in2 = 0, c1in3 = 0, c2in1 = 0, c2in3 = 0, c3in1 = 0, c3in2 = 0;
    
    int swaps = 0;
    
    for (int i = 0; i < candy; i++) {
        int candyVal;
        cin >> candyVal;
        candies[i] = candyVal;
        if (candyVal == 1) {
            one++;
        } else if (candyVal == 2) {
            two++;
        } else {
            three++;
        }
    }
    
    for (int i = 0; i < candy; i++) {
        if (i < one) {
            if (candies[i] == 2) {
                c2in1++;
            } else if (candies[i] == 3) {
                c3in1++;
            }
        } else if (i >= one && i < one + two) {
            if (candies[i] == 1) {
                c1in2++;
            } else if (candies[i] == 3) {
                c3in2++;
            }
        } else {
            if (candies[i] == 1) {
                c1in3++;
            } else if (candies[i] == 2) {
                c2in3++;
            }
        }
    }
    
    if (c1in3 > 0 && c3in1 > 0) {
        int swap = min(c1in3, c3in1);
        swaps += swap;
        c1in3 -= swap;
        c3in1 -= swap;
    }
    
    if (c1in2 > 0 && c2in1 > 0) {
        int swap = min(c1in2, c2in1);
        swaps += swap;
        c1in2 -= swap;
        c2in1 -= swap;
    }
    
    if (c2in3 > 0 && c3in2 > 0) {
        int swap = min(c2in3, c3in2);
        swaps += swap;
        c2in3 -= swap;
        c3in2 -= swap;
    }
    
    int wrong = c1in2 + c1in3 + c2in1 + c2in3 + c3in1 +c3in2;
    
    swaps += wrong *2.0/3;
    
    cout << swaps << endl;
    return 0;
}