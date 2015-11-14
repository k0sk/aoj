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
    string e;
    cin >> e;

    int am = 0;
    for (int i = 0, l = e.size(); i < l; i++) {
        if (e[i + 1] == '*') {
            int m = e[i] - '0';
            while (i + 1 < l && e[i + 1] == '*') {
                m *= (e[i + 2] - '0');
                i += 2;
            }
            am += m;
        } else if ('0' <= e[i] && e[i] <= '9') {
            am += e[i] - '0';
        }
    }

    int al = e[0] - '0';
    for (int i = 1; i < e.size(); i += 2) {
        if (e[i] == '+') al += e[i + 1] - '0';
        else if (e[i] == '*') al *= e[i + 1] - '0';
    }

    int au;
    cin >> au;

    if (am == au && al == au) cout << "U" << endl;
    else if (am == au) cout << "M" << endl;
    else if (al == au) cout << "L" << endl;
    else cout << "I" << endl;

    return 0;
}

