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

const int MAX_N = 20000,
          MAX_M = 16,
          MAX_X = 255;

int main() {
    vector<int> C(MAX_M + 1);
    vector<int> x(MAX_N + 1);

    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<int> > dp(N + 1, vector<int>(MAX_X + 1, INT_MAX));
        dp[0][128] = 0;

        for (int i = 0; i < M; i++) cin >> C[i];
        for (int i = 0; i < N; i++) cin >> x[i];

        for (int i = 0; i < N; i++) {
            for (int yi = 0; yi < MAX_X + 1; yi++) {
                if (dp[i][yi] == INT_MAX) continue;

                for (int k = 0; k < M; k++) {
                    int yk = max(0, min(255, yi + C[k]));
                    int se = pow(x[i] - yk, 2);

                    dp[i + 1][yk] = min(dp[i + 1][yk], dp[i][yi] + se);
                }
            }
        }

        cout << *min_element(dp[N].begin(), dp[N].end()) << endl;
    }

    return 0;
}

