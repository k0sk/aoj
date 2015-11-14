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

const int MAX_R = 1000,
          LOG_IN = 1,
          LOG_OUT = 0;

typedef struct {
    int t;
    int n;
    int m;
    int s;
} record_t;

int main() {
    int N, M, r, q,
        ts, te, m;
    record_t rec[MAX_R];
    while (cin >> N >> M, N > 0 && M > 0) {
        cin >> r;
        for (int i = 0; i < r; i++)
            cin >> rec[i].t >> rec[i].n >> rec[i].m >> rec[i].s;

        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> ts >> te >> m;

            int ans = 0, in_use = 0,
                t_first_in = 0, t_last_out = 0;
            for (int j = 0; j < r; j++) {
                if (rec[j].m != m) continue;

                if (rec[j].s == LOG_IN) {
                    if (in_use == 0) t_first_in = min(max(rec[j].t, ts), te);

                    in_use++;
                }

                if (rec[j].s == LOG_OUT) {
                    if (in_use == 1) {
                        t_last_out = max(min(rec[j].t, te), ts);

                        ans += t_last_out - t_first_in;
                    }

                    in_use--;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}

