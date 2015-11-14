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

const int MAX_MS = 300000;

int main() {
    vector<int> ms, ms_prime;
    for (int i = 8; i < MAX_MS; i += 7) ms.push_back(i);
    for (int i = 6; i < MAX_MS; i += 7) ms.push_back(i);
    sort(ms.begin(), ms.end());

    for (int i = 0; i < (int)ms.size(); i++) {
        if (ms[i] == ms[i + 1]) continue;

        bool is_prime = true;
        for (int j = 0; j < i && ms[j] < sqrt(ms[i]) + 1; j++)
            if (ms[i] % ms[j] == 0) {
                is_prime = false;
                break;
            }

        if (is_prime) ms_prime.push_back(ms[i]);
    }

    int n;
    while (cin >> n, n > 1) {
        printf("%d:", n);
        for (int i = 0; i < (int)ms_prime.size() && ms_prime[i] <= n; i++)
            if (n % ms_prime[i] == 0) printf(" %d", ms_prime[i]);
        printf("\n");
    }

    return 0;
}

