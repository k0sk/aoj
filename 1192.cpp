#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main() {
    int x, y, s;
    while (cin >> x >> y >> s) {
        if(x==0 && y==0 && s==0) break;

        int ans = 0;
        for (int i=1; i<s/2+1; i++) {
            for (int j=s-i; j>0; j--) {
                if (i*(100+x)/100 + j*(100+x)/100 != s) continue;

                ans = max(ans, i*(100+y)/100 + j*(100+y)/100);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

