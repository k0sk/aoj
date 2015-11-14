#include <bits/stdc++.h>
using namespace std;

const string keys[] = {
    ".,!? ",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

int main() {
    int n, cnt, num, idx;
    string input, ans;
    char p[2] = "0";
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> input;

            cnt = -1;
            ans = "";
            for (int j = 0; j < input.size(); j++) {
                if (input[j] != '0') {
                    cnt++;

                    if (input[j + 1] == '0') {
                        p[0] = input[j];
                        num = atoi(p) - 1;
                        idx = cnt % keys[num].size();
                        ans += keys[num][idx];
                        cnt = -1;
                    }
                } else {
                    continue;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}

