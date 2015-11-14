#include <bits/stdc++.h>
using namespace std;

const int MAX_NM = 100;

int main() {
    int n, m;
    int st[MAX_NM], sh[MAX_NM];
    while (cin >> n >> m && n && m) {
        int t_total = 0, h_total = 0;
        for (int i = 0; i < n; i++) {
            cin >> st[i];
            t_total += st[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> sh[i];
            h_total += sh[i];
        }

        int ans1 = -1, ans2 = -1;
        int sum = 201;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (t_total-st[i]+sh[j] == h_total-sh[j]+st[i] &&
                        st[i] + sh[j] < sum) {
                    ans1 = st[i];
                    ans2 = sh[j];

                    sum = ans1 + ans2;
                }
            }
        }

        if (ans1 > 0 && ans2 > 0) printf("%d %d\n", ans1, ans2);
        else puts("-1");
    }

    return 0;
}

