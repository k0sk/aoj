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
    int n, k, m;
    while (cin >> n >> k >> m, n > 0 && k > 0 && m > 0) {
        vector<int> c(n);
        for (int i = 0; i < n; i++) c[i] = i + 1;
        m--;

        while (c.size() > 1) {
            c.erase(c.begin() + m);
            m = (m + k - 1) % c.size();
        }

        cout << c[0] << endl;
    }

    return 0;
}

