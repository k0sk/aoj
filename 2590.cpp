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
#include <bitset>
#include <map>
#include <climits>
#include <sstream>
using namespace std;
typedef long long ll;

const int MAX_N = 36,
          MAX_M = 1000;

typedef bitset<MAX_N> S;
typedef bitset<MAX_M> B;

int main() {
    int N, M, Q;
    while (cin >> N >> M >> Q, N || M || Q) {
        vector<S> sw(Q);
        vector<B> bb(Q);

        for (int i = 0; i < Q; i++) cin >> sw[i] >> bb[i];
        for (int i = Q - 1; i > 0; i--) bb[i] ^= bb[i - 1];

        for (int i = M - 1; i >= 0; i--) {
            S ans;
            ans.set();
            ans &= (ans >> (36 - N));

            for (int j = 0; j < Q; j++) ans &= (bb[j][i] ? sw[j] : ~sw[j]);

            if (ans.count() > 1) cout << "?";
            else {
                int j;
                for (j = 0; j < N; j++) if (ans[j]) break;
                j = N - j - 1;

                cout << (char)((j < 10) ? ('0' + j) : ('A' + j - 10));
            }
        }
        cout << endl;
    }


    return 0;
}

