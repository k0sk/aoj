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
    int n, w, v,
        h[100];
    while (cin >> n >> w, n || w) {
        memset(h, 0, sizeof(h));

        int r, f = 0, m = 0;
        for (int i = 0; i < n; i++) {
            cin >> v;
            r = v / w;

            f = max(f, ++h[r]);
            m = max(m, r);
        }

        double ans = 0;
        for (int i = 0; i < m; i++) {
            ans +=  ((double)(m - i) / m) * ((double)h[i] / f);
        }
        ans += 0.01;

        printf("%.10g\n", ans);
    }

    return 0;
}

