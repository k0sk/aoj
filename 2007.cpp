#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int v[] = {10, 50, 100, 500};

int main() {
    int t, c[4];
    bool f = false;
    while (cin >> t && t) {
        if (f) putchar('\n');
        int m = 0;
        for (int i = 0; i < 4; i++) {
            cin >> c[i];
            m += v[i] * c[i];
        }

        int d = abs(t - m);
        for (int i = 3; i >= 0; i--) {
            int r = d / v[i];
            d -= v[i] * r;
            c[i] -= r;
        }

        for (int i = 0; i < 4; i++)
            if (c[i] > 0) printf("%d %d\n", v[i], c[i]);
        f = true;
    }

    return 0;
}

