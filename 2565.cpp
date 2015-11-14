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
#include <set>
#include <climits>
#include <sstream>
using namespace std;
typedef long long ll;

const int MAX_N = 1000;

int main() {
    int N, a[MAX_N];
    bool b[MAX_N];
    while (cin >> N, N) {
        memset(a, 0, sizeof(a));
        memset(b, false, sizeof(b));

        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            if (s == "x") b[i] = true;
            else a[i] = atoi(s.c_str());
        }

        set<int> ans;
        for (int i = 0; i < N; i++) {
            for (int j = -2; j <= 2; j++) {
                int x = a[i] + j;

                for (int k = 0; k < N; k++)
                    if (b[k]) a[k] = x;

                bool f = true;
                for (int k = 0; k < N - 1; k++) {
                    if (k % 2 == 0 && a[k] >= a[k + 1]) f = false;
                    if (k % 2 == 1 && a[k] <= a[k + 1]) f = false;
                }

                if (f) ans.insert(x);
            }
        }

        int l = ans.size();
        if (l == 1) printf("%d\n", *ans.begin());
        else if (l == 0) printf("none\n");
        else printf("ambiguous\n");
    }

    return 0;
}

