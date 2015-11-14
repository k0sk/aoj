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
typedef pair<string, double> psd;

bool is_efficient(psd a, psd b) {
    if (a.second == b.second && a.first < b.first) return true;

    return (a.second > b.second);
}

int main() {
    int N, P, A, B, C, D, E, F, S, M;
    string L;
    while (cin >> N, N > 0) {
        vector<psd> d;
        for (int i = 0; i < N; i++) {
            cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;

            int t = A + B + C + M * (D + E),
                p = M * F * S - P;
            d.push_back(psd(L, p / (double)t));
        }

        sort(d.begin(), d.end(), is_efficient);

        for (int i = 0; i < N; i++) cout << d[i].first << endl;
        cout << "#" << endl;
    }

    return 0;
}

