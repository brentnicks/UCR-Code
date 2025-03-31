#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

using namespace std;

long double function(long double a, long double x) {
    return ((x * x) / log(x)) + a * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double minVal = DBL_MAX;

    long double a;
    cin >> a;

    long double l = 1, r = 2;
    while (r - l > 1e-7) {
        long double midLeft = l + (r - l) / 3.0;
        long double midRight = l + 2 * (r - l) / 3.0;
        long double midLeftVal = function(a, midLeft);
        long double midRightVal = function(a, midRight);
        if (midLeftVal < midRightVal) {
            minVal = midLeftVal;
            r = midRight;
        } else {
            minVal = midRightVal;
            l = midLeft;
        }
    }

    cout << fixed << setprecision(9) << minVal << "\n";

    return 0;
}