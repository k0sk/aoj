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

const int MAX_N = 7 + 2;
const int NONE = 0,
          BLACK = 1,
          WHITE = 2;
const int dx[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const int dy[] = {1, 0, 1, 1, 0, 0, 0, 1,-1, 1,-1, 1,-1};
const int dz[] = {0, 1, 1,-1, 0, 1,-1, 0, 0, 1, 1,-1,-1};

int f[MAX_N][MAX_N][MAX_N],
    n, m, p;

int add_ball(int c, int x, int y) {
    for (int i = 1; i <= n; i++) {
        if (f[x][y][i] == NONE) {
            f[x][y][i] = c;
            return i;
        }
    }

    return -1;
}

int get_winner(int c, int x, int y, int z) {
    for (int i = 0; i < 13; i++) {
        int l = 0, r = 0;
        int nx = x, ny = y, nz = z;

        while (f[nx][ny][nz] == c) {
            l++;
            nx += dx[i]; ny += dy[i]; nz += dz[i];

            if (nx < 1 || n < nx || ny < 1 || n < ny || nz < 1 || n < nz)
                break;
        }

        nx = x;
        ny = y;
        nz = z;

        while (f[nx][ny][nz] == c) {
            r++;
            nx -= dx[i]; ny -= dy[i]; nz -= dz[i];

            if (nx < 1 || n < nx || ny < 1 || n < ny || nz < 1 || n < nz)
                break;
        }

        if (l + r - 1 >= m) return c;
    }

    return NONE;
}

int main() {
    while (cin >> n >> m >> p, n || m || p) {
        memset(f, 0, sizeof(f));

        int x, y, z, c,
            winner = 0, mov;
        for (mov = 1; mov <= p; mov++) {
            cin >> x >> y;

            c = (mov % 2) ? BLACK : WHITE;
            z = add_ball(c, x, y);

            winner = get_winner(c, x, y, z);
            if (winner != NONE) break;
        }
        for (int i = 0; i < p - mov; i++) cin >> x >> y;

        switch (winner) {
            case BLACK:
                printf("Black %d\n", mov);
                break;
            case WHITE:
                printf("White %d\n", mov);
                break;
            default:
                printf("Draw\n");
                break;
        }

    }

    return 0;
}

