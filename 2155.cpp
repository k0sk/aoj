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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pip;

const int MAX_N = 20001;
bool is_infected[MAX_N];

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        memset(is_infected, false, sizeof(is_infected));
        is_infected[0] = true;

        int ti, si, di;
        vector<pip> d(M);
        for (int i = 0; i < M; i++) {
            cin >> ti >> si >> di;
            d[i] = pip(ti, pii(si, di));
        }

        sort(d.begin(), d.end());

        int ans = 1;
        for (int i = 0; i < M; i++) {
            si = d[i].second.first - 1;
            di = d[i].second.second - 1;

            if (is_infected[si] == false || is_infected[di] == true) continue;

            is_infected[di] = true;
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}

