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
typedef pair<int, int> pii;

const int MAX_XY = 500;
const int dx[] = {0, -1, -1, 0, 1, 1},
          dy[] = {-1, -1, 0, 1, 1, 0};

int main() {
    int t, n,
        f[MAX_XY][MAX_XY],
        ox, oy, sx, sy;
    bool v[MAX_XY][MAX_XY];
    while (cin >> t >> n, !(t == 0 && n == 0)) {
        memset(f, 0, sizeof(f));
        memset(v, false, sizeof(v));
        for (int i = 0; i < n; i++) {
            cin >> ox >> oy;
            v[ox + 250][oy + 250] = true;
        }
        cin >> sx >> sy;
        sx += 250, sy += 250;

        queue<pii> q;
        q.push(pii(sx, sy));
        v[sx][sy] = true;

        int ans = 1;
        while (!q.empty()) {
            pii fn = q.front(); q.pop();
            int x = fn.first, y = fn.second;

            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i],
                    ny = y + dy[i];

                if (nx < 0 || MAX_XY < nx || ny < 0 || MAX_XY < ny || v[nx][ny])
                    continue;

                ans++;
                v[nx][ny] = true; f[nx][ny] = f[x][y] + 1;
                if (f[nx][ny] < t) q.push(pii(nx, ny));
            }
        }

        cout << ans << endl;
    }

    return 0;
}

