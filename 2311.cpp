#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppipi;

typedef struct {
    int x, y, c;
    vi r;
} point_t;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1},
    dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

vs board(8);
bool checked[8][8];

vi get_reward(int x, int y, char turn) {
    vi ret(8, 0);

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i],
            ny = y + dy[i];

        if (nx < 0 || 8 <= nx || ny < 0 || 8 <= ny || board[ny][nx] == '.')
            continue;

        int cnt = 0;
        bool f = false;
        do {
            if (board[ny][nx] == (turn == 'x' ? 'o' : 'x')) cnt++;
            else if (board[ny][nx] == turn) {
                f = true;
                break;
            }

            nx += dx[i];
            ny += dy[i];
        } while (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && board[ny][nx] != '.');

        if (f) ret[i] = cnt;
    }

    return ret;
}

void put_cookie(int x, int y, char turn, vi r) {
    board[y][x] = turn;

    for (int i = 0; i < 8; i++) {
        if (r[i] < 1) continue;

        int nx = x, ny = y;
        for (int j = 0; j < r[i]; j++) {
            nx += dx[i];
            ny += dy[i];

            board[ny][nx] = turn;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) cin >> board[i];

    int skip = 0;
    char turn = 'x';
    while (skip < 2) {
        turn = (turn == 'x' ? 'o' : 'x');
        memset(checked, false, sizeof(checked));

        point_t move = {-1, -1, -1};
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (board[y][x] == (turn == 'x' ? 'o' : 'x')) {
                    for (int i = 0; i < 8; i++) {
                        int nx = x + dx[i],
                        ny = y + dy[i];

                        if (nx < 0 || 8 <= nx || ny < 0 || 8 <= ny
                                || board[ny][nx] != '.' || checked[ny][nx])
                            continue;

                        vi tmp = get_reward(nx, ny, turn);

                        int c = accumulate(tmp.begin(), tmp.end(), 0);
                        if (c > move.c) {
                            move.x = nx;
                            move.y = ny;
                            move.c = c;
                            move.r = tmp;
                        } else if (c == move.c && (turn == 'o' ? (ny < move.y || (ny == move.y && nx < move.x)) : (ny > move.y || (ny == move.y && nx > move.x)))) {
                            move.x = nx;
                            move.y = ny;
                            move.c = c;
                            move.r = tmp;
                        }
                    }
                }
            }
        }
        // printf("r: %d, d: %d, x: %d, y: %d, skip: %d\n", move.r, move.d, move.x, move.y, skip);

        if (move.c < 1) {
            skip++;
            continue;
        }

        put_cookie(move.x, move.y, turn, move.r);

        skip = 0;
    }

    for (int i = 0; i < 8; i++) cout << board[i] << endl;

    return 0;
}

