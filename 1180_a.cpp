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

const int MAX_I = 20 + 1;

int main() {
    int a[MAX_I];
    string num;
    int L;
    while (cin >> num >> L) {
        if (num == "0" && !L) break;

        a[0] = atoi(num.c_str());

        int i, j;
        for (i = 1; i < MAX_I; i++) {
            for (int k = num.size(); k < L; k++) num = "0" + num;

            sort(num.begin(), num.end(), greater<char>());
            int max_num = atoi(num.c_str());

            sort(num.begin(), num.end());
            int min_num = atoi(num.c_str());

            a[i] = max_num - min_num;
            // printf("a[%d]: %d - %d = %d\n", i, max_num, min_num, a[i]);

            stringstream ss;
            ss << a[i];
            num = ss.str();

            for (j = 0; j < i; j++) {
                if (a[j] == a[i]) goto last;
            }
        }

last:
        printf("%d %d %d\n", j, a[i], i - j);
    }

    return 0;
}
