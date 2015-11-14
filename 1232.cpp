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

const int MAX_PRIME = 50001,
          MAX_M = 100000;

int main() {
    int primes[6000];
    primes[0] = 2;
    int N_PRIME = 1;
    for (int i = 3; i < MAX_PRIME; i += 2) {
        bool is_prime = true;
        for (int j = 3; j < sqrt(i) + 1; j += 2)
            if (i % j == 0) is_prime = false;

        if (is_prime) primes[N_PRIME++] = i;
    }

    int m, a, b;
    while (cin >> m >> a >> b, m || a || b) {
        double r_ab = (double)a / b;

        int ap = 0, aq = 0;
        for (int i = 0; i < N_PRIME; i++) {
            for (int j = i; j < N_PRIME; j++) {
                int p = primes[i],
                    q = primes[j];

                int pq = p * q;
                double r_pq = (double)p / q;
                if (r_pq < r_ab || m < pq) break;

                if (ap * aq < pq) {
                    ap = p;
                    aq = q;
                }
            }
        }

        printf("%d %d\n", ap, aq);
    }

    return 0;
}

