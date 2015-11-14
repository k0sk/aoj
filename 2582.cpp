#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100;

int main() {
    int n;
    vector<string> f(MAX_N);
    while (cin >> n && n) {
        int ans = 0;

        for (int i = 0; i < n; i++) cin >> f[i];

        for (int i = 1; i < n; i++){
            if ((f[i]=="ru"&&f[i-1]!="lu") || (f[i]=="lu"&&f[i-1]!="ru"))
                continue;
            if ((f[i]=="rd"&&f[i-1]!="ld") || (f[i]=="ld"&&f[i-1]!="rd"))
                continue;

            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}

