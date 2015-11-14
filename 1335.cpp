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

int dp[22][11][156];

int main() {
    for (int i = 0; i <= 20; i++) dp[i][1][i] = 1;
    for (int i = 1; i <= 20; i++) {
        for (int k = 1; k <= 155; k++) {
            for (int j = 1; j <= 10; j++) {
                if (dp[i][j][k]) {
                    dp[i + 1][j][k] += dp[i][j][k];

                    if (j < 10 && k + i + 1 <= 155)
                        dp[i + 1][j + 1][k + i + 1] += dp[i][j][k];
                }
            }
        }
    }

    int n, k, s;
    while (cin >> n >> k >> s) {
        if (!n && !k && !s) break;

        cout << dp[n][k][s] << endl;
    }

    return 0;
}

