#include <iostream>
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

int main() {
    int N, M, D, P,
        DP[11];
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        memset(DP, 0, sizeof(DP));

        for (int i = 0; i < N; i++) {
            cin >> D >> P;
            DP[P] += D;
        }

        int ans = 0;
        for (int i = 10; i >= 0; i--) {
            if (M >= DP[i]) {
                M -= DP[i];
            } else {
                ans += i * (DP[i] - M);
                M = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

