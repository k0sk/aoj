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

const int MAX_N = 16;

int main() {
    int N,
        data[MAX_N + 1][MAX_N + 1];
    while (cin >> N, N) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j <= N; j++)
                cin >> data[i][j];

        int dp[(1 << N)];
        for (int b = 0; b < (1 << N); b++) dp[b] = INT_MAX;
        dp[0] = 0;

        for (int b = 0; b < (1 << N); b++) {
            for (int i = 0; i < N; i++) {
                if ((b & (1 << i)) == 1) continue;

                int c = data[i][0];
                for (int j = 0; j < N; j++) {
                    if ((b & (1 << j)) == 0) continue;
                    c = min(c, data[i][j + 1]);
                }

                int s = (b | (1 << i));
                dp[s] = min(dp[s], dp[b] + c);
            }
        }

        cout << dp[(1 << N) - 1] << endl;
    }

    return 0;
}

