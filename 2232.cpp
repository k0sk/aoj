#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
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

const int dy[] = {1, 0}, dx[] = {0, 1};

int h, w, n;
bool should_bunny_do_this(vector<string> field) {
    while(true) {
        for(int i = h - 2; i >= 0; i--) REP(j, w) {
            if(field[i][j] != '.') {
                int k = i + 1;

                while(k < h && field[k][j] == '.'){
                    swap(field[k - 1][j], field[k][j]);
                    k++;
                }
            }
        }

        bool rem[30][30] = {},
             update = false;
        REP(i, h) REP(j, w)
            if(field[i][j] != '.') {
                REP(d, 2) {
                    int k = 0,
                        x = j, y = i;
                    while(y < h && x < w && field[y][x] == field[i][j]) {
                        x += dx[d];
                        y += dy[d];
                        k++;
                    }

                    if(k < n) continue;
                    x = j;
                    y = i;

                    while(y < h && x < w && field[y][x] == field[i][j]) {
                        rem[y][x] = true;
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }

        REP(i, h) REP(j, w)
            if(rem[i][j]) {
                update = true;
                field[i][j] = '.';
            }

        if (!update) break;
    }

    REP(i, h) REP(j, w)
        if(field[i][j] != '.') return false;

    return true;
}

int main() {
    cin >> h >> w >> n;

    vs field(h);
    for (int i = 0; i < h; i++) cin >> field[i];

    REP(i, h) REP(j, w - 1) {
        vs cp_field = field;
        swap(cp_field[i][j], cp_field[i][j + 1]);

        if (should_bunny_do_this(cp_field)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}

