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
#include <numeric>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, pii> pip;

int main() {
    int w, d;
    while (cin >> w >> d, w || d) {
        vi fv(w);
        vi sv(d);

        for (int i = 0; i < w; i++) cin >> fv[i];
        for (int i = 0; i < d; i++) cin >> sv[i];

        int ans = 0;

        for (int i = 0; i < w; i++)
            for (int j = 0; j < d; j++)
                if (fv[i] == sv[j]) {
                    ans += fv[i];
                    fv[i] = 0;
                    sv[j] = 0;
                    break;
                }

        ans += accumulate(fv.begin(), fv.end(), 0);
        ans += accumulate(sv.begin(), sv.end(), 0);

        cout << ans << endl;
    }

    return 0;
}

