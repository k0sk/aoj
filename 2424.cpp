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


int main() {
    int Q, N;
    while (cin >> Q && Q) {
        for (int i = 0; i < Q; i++) {
            int ans = 0;

            cin >> N;
            if (N < 10) goto last;

            while (N >= 10) {
                int r, l,
                    pf = 10,
                    prod = 0;
                do {
                    r = N % pf;
                    l = N / pf;

                    prod = max(prod, r * l);
                    pf *= 10;
                } while (l >= 10);

                N = prod;
                ans++;
            }

last:
            cout << ans << endl;
        }
    }

    return 0;
}

