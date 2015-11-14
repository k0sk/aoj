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

const int dx[] = {0, 1, 0, -1},
          dy[] = {1, 0, -1, 0};

int main() {
    int w, h,
        maze[60][30],
        d[30][30];
    while (cin >> w >> h, w && h) {
        memset(d, 0, sizeof(d));

        for (int i = 0; i < 2 * h - 1; i++)
            for (int j = 0; j < (i % 2 ? w : w - 1); j++)
                scanf("%d", &maze[i][j]);

        map<pii, int> m;
        queue<pii> q;
        q.push(make_pair(0, 0));
        d[0][0] = 1;

        while (!q.empty()) {
            pii now = q.front(); q.pop();
            int x = now.first,
                y = now.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i],
                    ny = y + dy[i];

                if (nx < 0 || w <= nx || ny < 0 || h <= ny || d[ny][nx]) continue;

                if (i == 0 && maze[y*2+1][x]) continue;
                else if (i == 1 && maze[y*2][x]) continue;
                else if (i == 2 && maze[y*2-1][x]) continue;
                else if (i == 3 && maze[y*2][x-1]) continue;

                d[ny][nx] = d[y][x] + 1;
                q.push(make_pair(nx, ny));
            }
        }

        cout << d[h - 1][w - 1] << endl;
    }

    return 0;
}

