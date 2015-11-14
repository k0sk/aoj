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

const int MAX_N = 1e6;

int main() {
    vector<int> tetra;
    for (int i = 1; (i * (i + 1) * (i + 2)) / 6 <= MAX_N; i++)
        tetra.push_back((i * (i + 1) * (i + 2)) / 6);

    int dp[MAX_N], dp_odd[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        dp[i] = INT_MAX;
        dp_odd[i] = INT_MAX;
    }

    dp[0] = dp_odd[0] = 0;
    for (int i = 0; i < (int)tetra.size(); i++) {
        for (int j = tetra[i]; j < MAX_N; j++) {
            dp[j] = min(dp[j], dp[j - tetra[i]] + 1);

            if (tetra[i] % 2 == 1)
                dp_odd[j] = min(dp_odd[j], dp_odd[j - tetra[i]] + 1);
        }
    }

    int n;
    while (cin >> n, n) {
        printf("%d %d\n", dp[n], dp_odd[n]);
    }

    return 0;
}

