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

const int MAX_N = 1<<15;

int main() {
    int dp[MAX_N + 1][5] = {};
    dp[0][0] = 1;
    for (int i = 1; i * i <= MAX_N; i++) {
        int sq = i * i;
        for (int j = sq; j <= MAX_N; j++)
            for (int k = 0; k < 4; k++)
                dp[j][k + 1] += dp[j - sq][k];
    }

    int n;
    while (cin >> n, n) {
        int ans = 0;

        for (int i = 0; i < 5; i++) ans += dp[n][i];

        cout << ans << endl;
    }

    return 0;
}

