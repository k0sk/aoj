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

const int MAX_W = 5,
          MAX_H = 10;

bool is_chained(int c[MAX_H][MAX_W], int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < MAX_W; j++) {
            int cnt = 1;
            while (j + 1 < 5 && c[i][j] == c[i][j + 1] && c[i][j] != 0) {
                cnt++;
                j++;

                if (cnt >= 3) return true;
            }
        }
    }

    return false;
}

int main() {
    int H, c[MAX_H][MAX_W];
    while (cin >> H, H > 0) {
        memset(c, 0, sizeof(c));
        for (int i = H - 1; i >= 0; i--)
            for (int j = 0; j < MAX_W; j++)
                cin >> c[i][j];

        int ans = 0;
        while (is_chained(c, H)) {
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < MAX_W; j++) {
                    int cnt = 1;

                    while (j + 1 < 5 && c[i][j] == c[i][j + 1] && c[i][j] != 0) {
                        cnt++;
                        j++;
                    }

                    if (cnt >= 3) {
                        ans += c[i][j] * cnt;
                        for (int k = j; cnt--; k--) c[i][k] = 0;
                    }
                }
            }

            for (int i = 0; i < MAX_W; i++) {
                for (int j = 0; j < H; j++) {
                    if (c[j][i] == 0) {
                        int cnt = 0;
                        for (int k = j; k < H; k++) {
                            if (c[k][i] != 0) cnt++;

                            if (k < H - 1) c[k][i] = c[k + 1][i];
                            else c[k][i] = 0;
                        }

                        if (cnt > 0) j--;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

