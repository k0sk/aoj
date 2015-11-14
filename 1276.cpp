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

const int MAX_PRIME = 1299709;

bool is_prime(int x) {
    if (x == 2) return true;
    if (x % 2 == 0 || x < 2) return false;

    for (int i = 3; i < sqrt(x) + 1; i += 2)
        if (x % i == 0) return false;

    return true;
}

int main() {
    int n;
    while (cin >> n && n) {
        int p, pn,
            ans = 0;

        if (is_prime(n)) goto last;

        for (p = n; !is_prime(p); p--) continue;
        for (pn = n; !is_prime(pn); pn++) continue;
        ans = pn - p;

last:
        cout << ans << endl;
    }

    return 0;
}

