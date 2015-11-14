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

const int MAX_NM = 1500,
          MAX_HW = 1000 * 1500;
int h[MAX_NM], w[MAX_NM],
    cnt_h[MAX_HW], cnt_w[MAX_HW];

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        memset(cnt_h, 0, sizeof(cnt_h));
        memset(cnt_w, 0, sizeof(cnt_w));

        for (int i = 0; i < N; i++) cin >> h[i];
        for (int i = 0; i < M; i++) cin >> w[i];

        for (int i = 0; i < N; i++) {
            int sum_h = 0;
            for (int j = i; j < N; j++) {
                sum_h += h[j];
                cnt_h[sum_h]++;
            }
        }

        for (int i = 0; i < M; i++) {
            int sum_w = 0;
            for (int j = i; j < M; j++) {
                sum_w += w[j];
                cnt_w[sum_w]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < MAX_HW; i++) ans += cnt_h[i] * cnt_w[i];

        cout << ans << endl;
    }

    return 0;
}

