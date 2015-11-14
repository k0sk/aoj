#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int dx[]   = {0, 1, 0, -1},
          dy[]   = {1, 0, -1, 0},
          MAX_WH = 20;
const char BLACK_TILE  = '.',
           START_POINT = '@';

int W, H;
bool checked[MAX_WH][MAX_WH];
char room[MAX_WH][MAX_WH];

int count_black_tiles(int x, int y) {
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;

        if (room[ny][nx] == BLACK_TILE && checked[ny][nx] == false) {
            checked[ny][nx] = true;
            ret += count_black_tiles(nx, ny);
        }
    }

    return ret;
}

int main() {
    int sx, sy;

    while (cin >> W >> H && W && H) {
        memset(checked, false, sizeof(checked));

        for (int i = 0; i < H; i++) {
            cin >> room[i];

            for (int j = 0; j < W; j++) {
                if (room[i][j] == START_POINT) {
                    sx = j;
                    sy = i;
                }
            }
        }

        cout << count_black_tiles(sx, sy) << endl;
    }

    return 0;
}

