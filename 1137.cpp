#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int mcxi_to_int(string mcxi) {
    map<char, int> fp;
    fp['m'] = 1000;
    fp['c'] = 100;
    fp['x'] = 10;
    fp['i'] = 1;

    int ret = 0, num = 1;

    for (int i = 0; i < mcxi.size(); i++) {
        if ('0' <= mcxi[i] && mcxi[i] <= '9') {
            num = mcxi[i] - '0';
        } else {
            ret += num * fp[mcxi[i]];
            num = 1;
        }
    }

    return ret;
}

string int_to_mcxi(int num) {
    string pf = "ixcm";
    string ret = "";

    for (int i = 0; num > 0 || i < 4; i++, num /= 10) {
        int rem = num % 10;

        if (rem > 0) ret = pf[i] + ret;
        if (rem > 1) {
            char tmp = '0' + rem;
            ret = tmp + ret;
        }
    }

    return ret;
}

int main() {
    int n, num1, num2;
    string mcxi1, mcxi2;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> mcxi1 >> mcxi2;

            num1 = mcxi_to_int(mcxi1);
            num2 = mcxi_to_int(mcxi2);

            cout << int_to_mcxi(num1 + num2) << endl;
        }
    }

    return 0;
}

