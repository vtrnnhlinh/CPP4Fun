#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool checkWholeNum(double num) {
    if (num == (int)num) {
        return true;
    }
    return false;
}

int main() {
    int n = 0;
    int m = 0;
    cin >> m;
    n = sqrt(m);
    string s = "";
    if (n*n == m) {
        s += to_string(n);
    }
    else {
    for (int i = n; i >= 1; i--) {
        double sqrtNum = 0.00;
        sqrtNum = (double) m / (i * i);
        if (checkWholeNum(sqrtNum) == true) {
            if (i == 1) {
                s += "sqrt " + to_string((int)sqrtNum);
            }
            else {
            s += to_string(i) + " sqrt " + to_string((int)sqrtNum);
            m = sqrtNum;
            }
            break;
        }
    }
    if (s == "") {
        s = "sqrt " + to_string(m);
    }
    }
    cout << s << endl;
    return 0;
}