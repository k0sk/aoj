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

const int MAX_WH = 52;
const int dx[] = {0, 1, 0, -1},
          dy[] = {-1, 0, 1, 0};

int w, h,
    area_b, area_w;
char land[MAX_WH][MAX_WH];

void cnt_area(int x, int y, char c) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i],
            ny = y + dy[i];

        if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;

        if (land[ny][nx] == '.') {
            if (c == 'B') {
                land[ny][nx] = '@';
                area_b++;
            } else {
                land[ny][nx] = '*';
                area_w++;
            }

            cnt_area(nx, ny, c);
        } else if (c == 'W' && land[ny][nx] == '@') {
            area_b--;
            land[ny][nx] = '*';

            cnt_area(nx, ny, 'W');
        }
    }
}

int main() {
    while (cin >> w >> h, w > 0 && h > 0) {
        for (int i = 0; i < h; i++) cin >> land[i];

        area_b = area_w = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (land[i][j] == 'B') cnt_area(j, i, 'B');
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (land[i][j] == 'W') cnt_area(j, i, 'W');
            }
        }

        printf("%d %d\n", area_b, area_w);
    }

    return 0;
}

