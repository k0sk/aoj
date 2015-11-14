#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, pii> pip;

int n, m, k;

int dfs(int n, int v) {
    int ret = 0;

    if (n == 0)
        ret += (v - k > 0) ? v - k : 1;
    else
        for (int i = 1; i <= m; i++) ret += dfs(n - 1, v + i);

    return ret;
}

int main() {
    while (cin >> n >> m >> k, n || m || k) {
        cout << fixed << setprecision(8) << (double)dfs(n, 0) / pow(m, n) << endl;
    }

    return 0;
}

