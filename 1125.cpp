#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int MAX_WH = 100;

int main() {
    int N, W, H, S, T,
        field[MAX_WH][MAX_WH],
        x, y;
    while (cin >> N && N) {
        cin >> W >> H;

        memset(field, 0, sizeof(field));
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            field[x - 1][y - 1]++;
        }

        cin >> S >> T;
        int ans = 0;
        for (int i = 0; i + S <= W; i++) {
            for (int j = 0; j + T <= H; j++) {
                int trees = 0;
                for (int k = 0; k < S; k++) {
                    for (int l = 0; l < T; l++) {
                        trees += field[i + k][j + l];
                    }
                }
                ans = max(ans, trees);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

