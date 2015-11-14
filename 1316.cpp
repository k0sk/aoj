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
typedef map<string, int> msi;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ALL(c) (c).begin(), (c).end()
#define CLR(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<": "<<x<<endl

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1},
          dy[] = {1, 1, 0, -1, -1, -1, 0, 1};


bool greater_spell(string a, string b) {
    if (a.size() != b.size())
        return (a.size() > b.size() ? true : false);

    return (a < b);
}

int main() {
    int h, w;
    while (cin >> h >> w, h || w) {
        vs data(h);
        for (int i = 0; i < h; i++) cin >> data[i];

        msi spells;
        REP(sy, h) REP(sx, w) REP(k, 8) {
            string spell = "";
            int nx = sx, ny = sy;
            do {
                spell += data[ny][nx];

                if (spell.size() > 1) spells[spell]++;

                nx = (nx + dx[k] + w) % w;
                ny = (ny + dy[k] + h) % h;
            } while (nx != sx || ny != sy);
        }

        vs ans;
        for (msi::iterator it = spells.begin(), it_end = spells.end(); it != it_end; it++)
            if (it->second >= 2) ans.push_back(it->first);

        sort(ans.begin(), ans.end(), greater_spell);

        cout << (ans.size() ? ans[0] : "0") << endl;
    }

    return 0;
}

