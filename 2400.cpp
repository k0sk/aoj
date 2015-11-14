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
typedef pair<pair<int, int>, int> ppi;

const int MAX_T = 51,
          MAX_P = 11;
const string CORRECT = "CORRECT",
             WRONG = "WRONG";

bool compare_score(const ppi a, const ppi b) {
    if (a.first.first > b.first.first) return true;
    else if (a.first.first < b.first.first) return false;
    else {
        if (a.first.second < b.first.second) return true;
        else if (a.first.second > b.first.second) return false;
        else {
            if (a.second < b.second) return true;
            else return false;
        }
    }
}

int main() {
    int T, P, R;
    int wa_cnt[MAX_T][MAX_P],
        ac_cnt[MAX_T],
        pen[MAX_T];
    bool is_ac[MAX_T][MAX_P];
    while (cin >> T >> P >> R) {
        if (!T && !P && !R) break;
        memset(wa_cnt, 0, sizeof(wa_cnt));
        memset(ac_cnt, 0, sizeof(ac_cnt));
        memset(pen, 0, sizeof(pen));
        memset(is_ac, false, sizeof(is_ac));

        int t_id, p_id, r_time;
        string message;
        for (int i = 0; i < R; i++) {
            cin >> t_id >> p_id >> r_time >> message;

            if (message == CORRECT && !is_ac[t_id][p_id]) {
                ac_cnt[t_id]++;
                pen[t_id] += wa_cnt[t_id][p_id] * 1200 + r_time;
                is_ac[t_id][p_id] = true;
            }

            if (message == WRONG) {
                wa_cnt[t_id][p_id]++;
            }
        }

        vector<ppi> ans(T);
        for (int i = 1; i <= T; i++)
            ans[i - 1] = make_pair(make_pair(ac_cnt[i], pen[i]), i);
        stable_sort(ans.begin(), ans.end(), compare_score);

        for (int i = 0; i < T; i++)
            printf("%d %d %d\n", ans[i].second, ans[i].first.first, ans[i].first.second);
    }

    return 0;
}

