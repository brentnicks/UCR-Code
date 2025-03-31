#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++){
        int w,d,h;
        cin >> w >> d >> h;
        int a,b,f,g;
        cin >> a >> b >> f >> g;
        int distance1 = 0, distance2 = 0, distance3 = 0, distance4 = 0;
            distance1 += b; //bot wall
            distance1 += abs(a - f);
            distance1 += h;
            distance1 += g;
            
            
            distance2 += d - b; //top wall
            distance2 += abs(a - f);
            distance2 += h;
            distance2 += abs(d - g);
    

            distance3 += a; //left wall
            distance3 += abs(b - g);
            distance3 += f;
            distance3 += h;


            distance4 += w - a; //right wall
            distance4 += abs(b - g);
            distance4 += abs (w - f);
            distance4 += h;

        cout << min(min(distance1, distance2), min(distance3, distance4)) << endl;
    }

    return 0;
}