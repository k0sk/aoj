#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main() {
    int e;
    while (cin >> e && e) {
        int m = e;

        for (int z = 0; z * z * z <= e; z++) {
            int r = e - z * z * z,
                y = floor(sqrt(r)),
                x = r - y * y;

            if (m > x + y + z) {
                m = x + y + z;
            }
        }

        cout << m << endl;
    }

    return 0;
}

