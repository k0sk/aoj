#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main() {
    int a, d, n;
    while (cin >> a >> d >> n) {
        if (!(a||d||n)) break;

        int ans, cnt = 0;
        for (int i=a; i<=1000000; i+=d) {
            bool isPrime = true;
            for (int j=2; j<=sqrt(i)+1; j++) {
                if (i%j==0 || i<j) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime || i==2) cnt++;
            if (cnt==n) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

