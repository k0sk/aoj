#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_WH = 50,
          SEA    = 0,
          LAND   = 1;

const int DIRECTIONS = 8,
          dx[]       = {0, 1, 1, 1, 0, -1, -1, -1},
          dy[]       = {1, 1, 0, -1, -1, -1, 0, 1};

int w, h, area_map[MAX_WH][MAX_WH];
bool checked[MAX_WH][MAX_WH];

void check_land_area(int x, int y) {
    for (int i = 0; i < DIRECTIONS; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;

        if (area_map[ny][nx] == LAND && checked[ny][nx] == false) {
            checked[ny][nx] = true;
            check_land_area(nx, ny);
        }
    }
}

int main() {
    while (cin >> w >> h && w && h) {
        memset(checked, false, sizeof(checked));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> area_map[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (area_map[i][j] == LAND && checked[i][j] == false) {
                    ans++;
                    check_land_area(j, i);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

