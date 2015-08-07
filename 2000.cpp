#include <bits/stdc++.h>
using namespace std;

const int SIDE_LENGTH = 21,
          START_POINT = 10;
int field[SIDE_LENGTH][SIDE_LENGTH],
    robo_x, robo_y;
int N, x, y, M, l;
char d[2];

int main() {
    while (cin >> N && N) {
        memset(field, 0, sizeof(field));

        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            field[x][y] = 1;
        }

        robo_x = START_POINT, robo_y = START_POINT;
        int sum = 0;

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> d >> l;

            while (l > 0) {
                switch (d[0]) {
                    case 'N':
                        robo_y++;
                        break;
                    case 'E':
                        robo_x++;
                        break;
                    case 'S':
                        robo_y--;
                        break;
                    case 'W':
                        robo_x--;
                        break;
                }

                if (field[robo_x][robo_y] > 0) {
                    sum++;
                    field[robo_x][robo_y] = 0;
                }

                l--;
            }
        }

        cout << ((sum == N) ? "Yes" : "No") << endl;
    }

    return 0;
}

