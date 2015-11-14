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

const int MAX_T  = 24 * 60 * 60,
          IMOS[] = {1, -1};

int main() {
    int n, h, m, s,
        table[MAX_T];
    while (cin >> n, n > 0) {
        memset(table, 0, sizeof(table));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%d:%d:%d", &h, &m, &s);
                table[h * 60 * 60 + m * 60 + s] += IMOS[j];
            }
        }

        for (int i = 1; i < MAX_T; i++) table[i] += table[i - 1];

        sort(table, table + MAX_T, greater<int>());
        cout << table[0] << endl;
    }

    return 0;
}

