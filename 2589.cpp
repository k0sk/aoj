#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <sstream>
using namespace std;
typedef long long ll;

int main() {
    string data;
    while (cin >> data, data != "#") {
        string dir = "";
        for (int i = 0; i < data.size();) {
            if (data[i] == 'n') {
                dir += data[i];
                i += 5;
            } else {
                dir += data[i];
                i += 4;
            }
        }

        cout << dir << endl;

        double a = (dir[dir.size() - 1] == 'n' ? 0.0 : 90.0),
               r = 2.0;
        for (int i = dir.size() - 2; i >= 0; i--) {
            a += (dir[i] == 'n' ? -90.0 : 90.0) / r;
            r *= 2.0;
        }

        int t = 1;
        while (abs(a) > (int)(abs(a))) {
            a *= 2.0;
            t *= 2;
        }

        if (t > 1) printf("%d/%d\n", (int)(abs(a)), t);
        else printf("%d\n", (int)(abs(a)));

    }

    return 0;
}

