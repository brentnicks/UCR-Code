#include <iostream>
#include <cmath>

using namespace std;

bool inWindowRange(int s, int n, int x, int y){
    double slope;
    if (n-s != 0){
        slope = 500/(n-s);
        float xMax, xMin, yMax, yMin;
        yMax = slope * (x - s);
        yMin = slope * (x - 100 - s);
        if (y <= yMax && y >= yMin){
            return true;
        }
        else return false;
    }
    else{
        if (s <= x && s + 100 >= x){
            return true;
        }
        else return false;
    }
}

int main(){
    int c1, c2, rx, ry;
    cin >> c1 >> c2 >> rx >> ry;
    int s, n;
    cin >> s >> n;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        bool rad, TV, window;

        if (pow(x - rx, 2) + pow(y - ry, 2) >= pow(c1, 2) && pow(x - rx, 2) + pow(y - ry, 2) <= pow(c2, 2)){
            rad = true;
        }
        else{
            rad = false;
        }
        window = inWindowRange(s, n, x, y);
        
        if (y >= 300 && abs((y - 300)/(500 - x * 1.0)) <= 1 || y <= 200 && abs((200 - y)/(500 - x * 1.0)) <= 1){
            TV = true;
        }
        else{
            TV = false;
        }
    
        if (rad && TV && window){
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }


    return 0;
}