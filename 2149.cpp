#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int N, A, B, C, X,
    Y[MAX_N + 1];

int main() {
    while (cin >> N >> A >> B >> C >> X) {
        if (N==0 && A==0 && B==0 && C==0 && X==0) break;
        for (int i = 0; i < N; i++) cin >> Y[i];

        int idx = 0, cnt;
        for (cnt = 0; cnt <= 10000; cnt++) {
            if (Y[idx] == X) idx++;
            X = (A * X + B) % C;
            if (idx == N) break;
        }

        cout << ((cnt > 10000) ? -1 : cnt) << endl;
    }
    return 0;
}

