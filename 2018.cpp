#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;

int main() {
    int N, M, P, X[MAX_N + 1];
    while (cin >> N >> M >> P) {
        if (N == 0 && M == 0 && P == 0) break;

        int ans = 0, num_tickets = 0;
        for (int i = 1; i <= N; i++) {
            cin >> X[i];
            num_tickets += X[i];
        }

        if (X[M] != 0) ans = num_tickets * (100 - P) / X[M];
        cout << ans << endl;
    }

    return 0;
}

