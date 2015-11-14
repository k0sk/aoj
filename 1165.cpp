#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int MAX_N = 200;

int dx[] = {-1, 0, 1, 0},
    dy[] = {0, -1, 0, 1};

int main() {
    int N, n, d;
    int x[MAX_N], y[MAX_N] = {0};

    while (cin >> N && N) {
        for (int i = 1; i < N; i++) {
            cin >> n >> d;
            x[i] = x[n] + dx[d];
            y[i] = y[n] + dy[d];
        }

        int min_w = INT_MAX, max_w = INT_MIN,
            min_h = INT_MAX, max_h = INT_MIN;
        for (int i = 0; i < N; i++) {
            min_w = min(min_w, x[i]);
            max_w = max(max_w, x[i]);
            min_h = min(min_h, y[i]);
            max_h = max(max_h, y[i]);
        }

        printf("%d %d\n", max_w - min_w + 1, max_h - min_h + 1);
    }

    return 0;
}

