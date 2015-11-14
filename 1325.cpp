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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, pii> pip;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ALL(c) (c).begin(), (c).end()
#define CLR(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<": "<<x<<endl

bool is_divisor(const int p, const int q, const int m, const int n) {
    int ss_mn = m * m + n * n;
    return ((m * p + n * q) % ss_mn == 0 && (m * q - n * p) % ss_mn == 0);
}

int main() {
    int a;
    cin >> a;

    while (a--) {
        int p, q;
        cin >> p >> q;

        int ss = p * p + q * q,
            cnt = 0;

        for (int m = 0; m * m <= ss; m++)
            for (int n = 0; n * n <= ss; n++)
                if (m * m + n * n >= 1 && is_divisor(p, q, m, n)) cnt++;

        cout << (cnt * 2 <= 8 ? "P" : "C") << endl;
    }

    return 0;
}

