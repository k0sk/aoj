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
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int MAX_L = 6 + 1;

int get_max(string str, int L) {
    char max_num[MAX_L] = "000000";
    max_num[L] = '\0';

    for (int i = 0; i < str.size(); i++) max_num[i] = str[i];
    sort(max_num, max_num + L, greater<char>());

    return atoi(max_num);
}

int get_min(string str, int L) {
    char min_num[MAX_L] = "000000";
    min_num[L] = '\0';

    for (int i = 0; i < str.size(); i++) min_num[i] = str[i];
    sort(min_num, min_num + L);

    return atoi(min_num);
}

int main() {
    ll a[21];
    int L;
    string num;
    stringstream ss;
    while (cin >> num >> L) {
        a[0] = atoi(num.c_str());

        int i, j;
        for (j = 1; j < 21; j++) {
            ss << a[j - 1];
            int max_num = get_max(ss.str(), L);
            int min_num = get_min(ss.str(), L);

            a[j] = max_num - min_num;

            for (i = 0; i <= j; i++) {
                if (a[j] == a[i]) break;
            }
        }

        printf("%d %lld %d\n", j, a[i], i - j);
    }

    return 0;
}
