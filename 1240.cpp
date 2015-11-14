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
    int n;
    while (cin >> n && n) {
        string m, s;
        for (int i = 0; i < n; i++) {
            cin >> m >> s;

            string ans = s,
                   tmp = s;
            for (int j = m.size() - 1, k, l = s.size(); j >= 0; j--) {
                switch (m[j]) {
                    case 'J':
                        tmp = ans.substr(l - 1, 1) + ans.substr(0, l - 1);
                        break;
                    case 'C':
                        tmp = ans.substr(1, l - 1) + ans.substr(0, 1);
                        break;
                    case 'E':
                        if (l % 2 == 0) tmp = ans.substr(l / 2, l / 2) + ans.substr(0, l / 2);
                        else tmp = ans.substr(l / 2 + 1, l / 2) + ans.substr(l / 2, 1) + ans.substr(0, l / 2);
                        break;
                    case 'A':
                        for (k = 0; k < l; k++) tmp[k] = ans[l - k - 1];
                        break;
                    case 'P':
                        for (k = 0; k < l; k++) {
                            if ('1' <= ans[k] && ans[k] <= '9') tmp[k]--;
                            else if (ans[k] == '0') tmp[k] = '9';
                        }
                        break;
                    case 'M':
                        for (k = 0; k < l; k++) {
                            if ('0' <= ans[k] && ans[k] <= '8') tmp[k]++;
                            else if (ans[k] == '9') tmp[k] = '0';
                        }
                        break;
                }

                ans = tmp;
            }
            cout << ans << endl;
        }
    }

    return 0;
}

