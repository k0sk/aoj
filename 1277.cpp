#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, pii> pip;

const char LOSE = 'L',
           BACK = 'B';

int main() {
    int N, T, L, B;
    while (cin >> N >> T >> L >> B, N || T ||L || B) {
        string board = string(N + 1, '.');

        for (int i = 0; i < L; i++) {
            int l;
            cin >> l;
            board[l] = LOSE;
        }
        for (int i = 0; i < B; i++) {
            int b;
            cin >> b;
            board[b] = BACK;
        }

        vector<vector<double> > dp(T + 1, vector<double>(N + 1, 0));
        dp[0][0] = 1;

        double P = 1.0 / 6.0;
        for (int t = 0; t < T; t++) {
            for (int n = 0; n < N; n++) {
                for (int d = 1; d <= 6; d++) {
                    int np = n + d;
                    if (np > N) np = 2 * N - np;

                    if (board[np] == LOSE && t + 2 <= T)
                        dp[t + 2][np] += dp[t][n] * P;
                    else if (board[np] == BACK)
                        dp[t + 1][0] += dp[t][n] * P;
                    else
                        dp[t + 1][np] += dp[t][n] * P;
                }
            }
        }

        double ans = 0.0;
        for (int i = 0; i <= T; i++)
            ans += dp[i][N];

        printf("%9lf\n", ans);
    }

    return 0;
}

