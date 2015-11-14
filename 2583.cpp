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

int main() {
    int n;
    while (cin >> n, n > 0) {
        vs s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        FOR(i, 1, n) {
            int l = (int)s[i].size();
            REP(j, l - 1) {
                if (s[i][j + 1] == '.') {
                    s[i][j] = ' ';
                } else {
                    s[i][j] = '+';
                    RFOR(k, 0, i) {
                        if (s[k][j] == ' ') s[k][j] = '|';
                        else break;
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) cout << s[i] << endl;

    }

    return 0;
}

