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

const int MAX_N = 50,
          MAX_M = 10;
const int UP = 0,
          LEFT = 1,
          DOWN = 2,
          RIGHT = 3;

struct _point {
    int x, y;
    int len(const _point &p) {
        return abs(x - p.x) + abs(y - p.y);
    }
    int dir(const _point &p) {
        return LEFT;
    }
};

struct _point data[MAX_M];

int main() {
    int n, m;
    while (cin >> n, n) {
        vector<vector<pii> > pl;

        for (int i = 0; i <= n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) cin >> data[j].x >> data[j].y;

            vector<pii> tmp;
            for (int j = 0; j < m - 1; j++) {
                int l = data[j].len(data[j + 1]),
                    d = data[j].dir(data[j + 1]);

                tmp.push_back(pii(l, d));
                printf("%d %d\n", l, d);
            }
            pl.push_back(tmp);
        }

        for (int i = 1; i < (int)pl.size(); i++) {
            bool f = true;
            for (int j = 0; j < (int)pl[i].size(); j++) {
                if (pl[i][j].first != pl[0][j].first
                        || pl[i][j].second != pl[0][j].second) {
                    f = false;
                    break;
                }
            }

            if (f) printf("%d\n", i);
        }
        printf("+++++\n");
    }

    return 0;
}

