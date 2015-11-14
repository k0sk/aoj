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

const int MAX_PRM = 10000,
          MAX_ITER = 100;
const int MAX_SUM = MAX_ITER * MAX_ITER;

int main() {
    int primes[MAX_PRM];
    primes[0] = 2;
    for (int i = 3, cnt = 1; cnt < MAX_PRM; i += 2) {
        bool is_prime = true;
        for (int j = 3; j < sqrt(i) + 1; j += 2) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes[cnt++] = i;
    }

    int N, P,
        sum[MAX_SUM];
    while (cin >> N >> P) {
        if (N == -1 && P == -1) break;

        int pn;
        for (pn = 0; primes[pn] <= N; pn++) continue;

        int nsum = 0;
        for (int i = pn; i < pn + MAX_ITER; i++) {
            for (int j = i; j < pn + MAX_ITER; j++) {
                sum[nsum++] = primes[i] + primes[j];
            }
        }
        sort(sum, sum + nsum);

        cout << sum[P - 1] << endl;
    }

    return 0;
}

