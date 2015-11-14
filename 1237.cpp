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

int t, ans, n_pcs;
string path;

void dfs(int num, int sum, int p, string buf) {
    if (num < p) {
        sum += num;
        buf = to_string(num) + buf;

        if (ans < sum && sum <= t) {
            ans = sum;
            path = buf;
            n_pcs = 1;
        } else if (ans == sum) {
            n_pcs++;
        }

        return;
    }

    dfs(num, sum, p * 10, buf);

    int rem = num % p;
    dfs(num / p, sum + rem, 10, " " + to_string(rem) + buf);
}

int main() {
    int num;
    while (cin >> t >> num, t || num) {
        ans = 0;
        n_pcs = 0;
        path = "";
        dfs(num, 0, 10, "");

        if (n_pcs == 0) cout << "error" << endl;
        else if (n_pcs == 1) cout << ans << " " << path << endl;
        else cout << "rejected" << endl;
    }

    return 0;
}

