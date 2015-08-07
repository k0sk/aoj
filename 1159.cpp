#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
int players[MAX_N];

int main() {
    int n, p;
    while (cin >> n >> p && n && p) {
        memset(players, 0, sizeof(players));

        int i = -1, j;
        bool flag;
        while (true) {
            i = (i + 1) % n;

            if (p == 0 && players[i] > 0) {
                p += players[i];
                players[i] = 0;
                continue;
            }

            if (p == 1) {
                flag = true;

                for (j=0; j<n; j++) {
                    if (j==i) continue;
                    if (players[j]>0) {
                        flag = false;
                        break;
                    }
                }

                if (flag) break;
            }

            if (p > 0) {
                p--;
                players[i]++;
            }
        }

        cout << i << endl;
    }
    return 0;
}

