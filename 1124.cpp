#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int MAX_M = 100;
int date[MAX_M + 1];

int main() {
    int N, Q, M, D;
    while (cin >> N >> Q) {
        if (N==0 && Q==0) break;
        memset(date, 0, sizeof(date));

        int MAX_D = 0;
        for (int i = 0; i < N; i++) {
            cin >> M;

            for (int j = 0; j < M; j++) {
                cin >> D;

                date[D]++;
                MAX_D = max(MAX_D, D);
            }
        }

        int ans = 0, MAX_ATND = 0;
        for (int i = 0; i <= MAX_D; i++) {
            if (date[i] >= Q && date[i] > MAX_ATND) {
                ans = i;
                MAX_ATND = date[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}

