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

const int MAX_WH = 70;
const int dx[] = {1, 0},
          dy[] = {0, 1};

int W, H;
vector<string> mat(MAX_WH);
vector<vector<string> > dp(MAX_WH, vector<string>(MAX_WH));

string max_strnum(string a, string b) {
    if (a.size() < b.size()) return b;
    if (a.size() > b.size()) return a;

    return (a > b ? a : b);
}

string dfs_dp(int x, int y) {
    if (dp[y][x] != "#") return dp[y][x];

    string ret = "";
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i],
            ny = y + dy[i];

        if (W <= nx || H <= ny || !isdigit(mat[ny][nx])) continue;

        ret = max_strnum(ret, dfs_dp(nx, ny));
    }

    dp[y][x] = mat[y][x] + ret;

    return dp[y][x];
}

int main() {
    while (cin >> W >> H, W || H) {
        for (int i = 0; i < H; i++) cin >> mat[i];

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) dp[i][j] = "#";

        string ans = "";
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (isdigit(mat[i][j]) && mat[i][j] != '0')
                    ans = max_strnum(ans, dfs_dp(j, i));

        cout << ans << endl;
    }

    return 0;
}

