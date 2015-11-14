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

const int MAX_N = 101;

int main() {
    int N, M, K,
        I[MAX_N];
    bool P[MAX_N][MAX_N];
    while (cin >> N && N) {
        memset(P, false, sizeof(P));
        for (int i = 1; i <= N; i++) {
            cin >> M;
            int id;
            for (int j = 1; j <= M; j++) {
                cin >> id;
                P[i][id] = true;
            }
        }
        cin >> K;
        for (int i = 1; i <= K; i++) cin >> I[i];

        int ans = -1, cnt = 0;
        for (int i = 1; i <= N; i++) {
            bool f = true;
            for (int j = 1; j <= K; j++) {
                if (!P[i][I[j]]) {
                    f = false;
                    break;
                }
            }

            if (f) {
                if (cnt < 1) {
                    ans = i;
                    cnt++;
                } else {
                    ans = -1;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

