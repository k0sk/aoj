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

const int RIGHT = 0,
          LEFT = 1;

int cnt_v(const string data, const int init_foot) {
    int ret = 0;

    int prev_foot = init_foot,
        pos[] = {0, 2};
    REP(i, (int)data.size()) {
        int p = (data[i] - '0' - 1) % 3;

        if (prev_foot == RIGHT) {
            if (pos[LEFT] < p) {
                ret++;
                pos[LEFT] = p;
            } else {
                pos[RIGHT] = p;
                prev_foot = (prev_foot + 1) % 2;
            }
        } else {
            if (p < pos[RIGHT]) {
                ret++;
                pos[RIGHT] = p;
            } else {
                pos[LEFT] = p;
                prev_foot = (prev_foot + 1) % 2;
            }
        }
    }

    return ret;
}

int main() {
    string data;
    while (cin >> data, data != "#") {
        cout << min(cnt_v(data, RIGHT), cnt_v(data, LEFT)) << endl;
    }
    return 0;
}

