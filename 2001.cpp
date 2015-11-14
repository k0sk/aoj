#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int MAX_N = 100,
          MAX_M = 1000;

int main() {
    int n, m, a,
        h, p, q,
        amida[MAX_N][MAX_M];
    while (cin >> n >> m >> a) {
        if (!(n||m||a)) break;
        memset(amida, 0, sizeof(amida));

        for (int i = 0; i < m; i++) {
            cin >> h >> p >> q;

            amida[p - 1][h - 1] = 1;
            amida[q - 1][h - 1] = -1;
        }

        int pos = a - 1;
        for (int i = MAX_M - 1; i >= 0; i--) {
            pos += amida[pos][i];
        }

        cout << pos + 1 << endl;
    }

    return 0;
}

