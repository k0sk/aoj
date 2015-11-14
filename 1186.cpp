#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > P;

const int MAX_WH = 150 + 1;

int main() {
    int h, w;
    while (cin >> h >> w && h && w) {
        vector<P> p;

        int d = pow(h, 2) + pow(w, 2),
            md = pow(h + 1, 2) + pow(w + 1, 2);

        int nh, nw;
        for (nh = 1; nh < MAX_WH; nh++) {
            for (nw = 1; nw < MAX_WH; nw++) {
                if (nh >= nw || (nh == h && nw == w)) continue;

                int nd = pow(nh, 2) + pow(nw, 2);
                if (md < nd) break;

                if ((nd > d) || (nd == d && nh > h)) {
                    p.push_back(make_pair(nd, make_pair(nh, nw)));
                }
            }
        }

        sort(p.begin(), p.end());

        printf("%d %d\n", p[0].second.first, p[0].second.second);
    }

    return 0;
}

