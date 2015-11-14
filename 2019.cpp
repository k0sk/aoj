#include <iostream>
#include <algorithm>
#include <cmath>
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
typedef pair<int, int> pii;

int main() {
    int N, D, P;
    ll M;
    while (cin >> N >> M) {
        if (N==0 && M==0) break;

        vector<pii> DP(N);
        for (int i = 0; i < N; i++) {
            cin >> D >> P;
            DP[i] = make_pair(P, D);
        }

        sort(DP.begin(), DP.end(), greater<pii>());

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (M > 0) {
                if (M >= DP[i].second) {
                    M -= DP[i].second;
                    continue;
                } else {
                    DP[i].second -= M;
                    M = 0;
                }
            }

            ans += DP[i].first * DP[i].second;
        }

        cout << ans << endl;
    }

    return 0;
}

