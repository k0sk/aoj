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

int main() {
    int N, M;
    double L[20], a[20], b[20];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%lf %lf %lf", &L[i], &a[i], &b[i]);

    double ans = 0.0;
    for (int i = 1; i < (1 << N); i++) {
        int bits = 0, s = i;
        while (s > 0) {
            if (s % 2) bits++;
            s /= 2;
        }

        if (bits == M) {
            double d = 0.0;

            int k = 0;
            for (int j = 0; k < bits; j++) {
                if (i & (1 << j)) {
                    k++;
                    for (int l = j + 1; l < N; l++) {
                        if (i & (1 << l)) {
                            d += pow(L[j] - L[l], 2) + pow(a[j] - a[l], 2) + pow(b[j] - b[l], 2);
                        }
                    }
                }
            }

            ans = max(ans, d);
        }
    }

    printf("%f\n", ans);


    return 0;
}

