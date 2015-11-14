#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 123456;

int main() {
    int n;
    bool is_prime[MAX_N * 2 + 2] = {false};
    is_prime[2] = true;

    while (cin >> n && n) {
        int ans = 0;
        if (n == 1) ans = 1;

        int n2 = n * 2;
        if (n % 2 == 0) n += 1;
        else n += 2;

        for (int i = n; i < n2; i += 2) {
            if (is_prime[i]) {
                ans++;
                continue;
            }

            bool flag = true;
            for (int j = 3; j < i; j += 2) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans++;
                is_prime[i] = true;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

