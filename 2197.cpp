#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N && N) {
        int ans = 0;

        for (int i = 1; i < 1000; i++) {
            if (i == N) continue;

            int sum = 0;
            for (int j = i; j < 1000; j++) {
                if (sum > N) break;
                else sum += j;

                if (sum == N) {
                    ans++;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

