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
typedef pair<int, int>  pii;

int main() {
    int N, Q;
    while (cin >> N >> Q, N > 0 && Q > 0) {
        string en;
        int eby, wy;
        vector<string> nd(N);
        vector<pii> yd(N);

        for (int i = 0; i < N; i++) {
            cin >> en >> eby >> wy;
            nd[i] = en;
            yd[i] = pii(wy - eby + 1, wy);
        }

        for (int i = 0; i < Q; i++) {
            cin >> wy;

            bool f = false;
            for (int j = 0; j < N; j++) {
                if (yd[j].first <= wy && wy <= yd[j].second) {
                    f = true;
                    printf("%s %d\n", nd[j].c_str(), wy - yd[j].first + 1);
                }
            }

            if (!f) printf("Unknown\n");
        }
    }

    return 0;
}

