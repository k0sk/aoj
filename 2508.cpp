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

const int MAX_N = 100;

int main() {
    int n, k[MAX_N];
    string s;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) cin >> k[i];
        cin >> s;

        int d, dd;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            d = k[j];
            while (d > 0) {
                if ('A' <= s[i] && s[i] <= 'Z') dd = s[i] - 'A';
                else if ('a' <= s[i] && s[i] <= 'z') dd = s[i] - 'a';

                if (d <= dd) {
                    s[i] -= d;
                    d -= dd;
                } else {
                    if ('A' <= s[i] && s[i] <= 'Z') s[i] = 'z';
                    else if ('a' <= s[i] && s[i] <= 'z') s[i] = 'Z';

                    d -= dd + 1;
                }
            }

            if (j >= n - 1) j = -1;
        }

        cout << s << endl;
    }

    return 0;
}

